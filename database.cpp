//
// Created by nikita on 27.01.2021.
//

#include "database.h"
#include <stdexcept>

void Database::Add(const Date &date, const string &event) {
  auto& events_on_date_vec = storage_vec[date];
  auto& events_on_date_set = storage_set[date];

  if (events_on_date_set.count(event) == 0) {
    events_on_date_set.insert(event);
    events_on_date_vec.push_back(event);
  }
}

void Database::Print(ostream& os) const {
  for (const auto& [date, events] : storage_vec) {
    for (const auto& event : events) {
      os << date << " " << event << endl;
    }
  }
}

vector<pair<Date, string>> Database::FindIf(const function<bool (const Date &, const string &)>& predicate) const {

  vector<pair<Date, string>> results;

  for (const auto& [date, events] : storage_vec) {
    for (const auto& event : events) {
      if (predicate(date, event)) {
        results.emplace_back(date, event);
      }
    }
  }

  return results;
}

int Database::RemoveIf(const function<bool (const Date &, const string &)> &predicate) {

  int removes_count = 0;

  set<Date> date_need_to_delete;

  for (auto& [date, events] : storage_vec) {
    auto it = stable_partition(events.begin(), events.end(),
                               [&, date = date](auto& event) {
                                 return !predicate(date, event);
                               });

    for (auto it_set = it; it_set != events.end(); it_set++) {
      storage_set[date].erase(*it_set);
    }

    removes_count += events.end() - it;
    events.erase(it, events.end());

    if (events.empty()) {
      date_need_to_delete.insert(date);
    }
  }

  for (const auto& date : date_need_to_delete) {
    storage_vec.erase(date);
    storage_set.erase(date);
  }

  return removes_count;
}

pair<Date, string> Database::Last(const Date &date) const{

  auto it = storage_vec.upper_bound(date);

  if (it == storage_vec.begin()) {
    throw invalid_argument("No results");
  }

  it = prev(it);

  return {it->first, it->second.back()};
}

ostream& operator<<(ostream& os, const pair<Date, string>& entry) {
  os << entry.first << " " << entry.second;
  return os;
}