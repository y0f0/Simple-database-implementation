//
// Created by nikita on 27.01.2021.
//

#include "date.h"
#include "node.h"

#include <map>
#include <vector>
#include <set>
#include <functional>

using namespace std;

#ifndef COURSE_PROJCET_DATABASE_H
#define COURSE_PROJCET_DATABASE_H

class Database {
public:
  void Add(const Date& date, const string& event);
  void Print(ostream& os) const;
  vector<pair<Date, string>> FindIf(const function<bool(const Date&, const string&)>& predicate) const;
  int RemoveIf(const function<bool(const Date&, const string&)>& predicate);
  pair<Date, string> Last(const Date& date) const;
private:
  map<Date, vector<string>> storage_vec;
  map<Date, set<string>> storage_set;
};

ostream& operator<<(ostream& os, const pair<Date, string>& entry);

#endif //COURSE_PROJCET_DATABASE_H
