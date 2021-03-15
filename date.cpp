//
// Created by nikita on 27.01.2021.
//

#include <iostream>
#include "date.h"


Date::Date(int new_year, int new_month, int new_day) {
  year = new_year;
  if (new_month > 12 || new_month < 1) {
    throw logic_error("Month value is invalid: " + to_string(new_month));
  }
  month = new_month;
  if (new_day > 31 || new_day < 1) {
    throw logic_error("Day value is invalid: " + to_string(new_day));
  }
  day = new_day;
}

int Date::GetYear() const {
  return year;
}
int Date::GetMonth() const {
  return month;
}
int Date::GetDay() const {
  return day;
}

// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() <<
         "-" << setw(2) << setfill('0') << date.GetMonth() <<
         "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

//Date ParseDate(istream& date_stream) {
//  bool ok = true;
//
//  int year;
//  ok = ok && (date_stream >> year);
//  ok = ok && (date_stream.peek() == '-');
//  date_stream.ignore(1);
//
//  int month;
//  ok = ok && (date_stream >> month);
//  ok = ok && (date_stream.peek() == '-');
//  date_stream.ignore(1);
//
//  int day;
//  ok = ok && (date_stream >> day);
//
//  if (!ok) {
//    throw logic_error("Wrong date format: ");
//  }
//  return Date(year, month, day);
//}

Date ParseDate(istream& is) {

  int year, month, day;
  is >> year;
  is.ignore();
  is >> month;
  is.ignore();
  is >> day;

  return {year, month, day};
}

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs) {
  // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
  // создадим вектор из года, месяца и дня для каждой даты и сравним их
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
         vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}


bool operator==(const Date& ldate, const Date& rdate) {
  return vector<int>{ldate.GetYear(), ldate.GetMonth(), ldate.GetDay()} ==
         vector<int>{rdate.GetYear(), rdate.GetMonth(), rdate.GetDay()};
}

bool operator!=(const Date& ldate, const Date& rdate) {
  return !(ldate == rdate);
}

bool operator<=(const Date& ldate, const Date& rdate) {
  return (ldate == rdate) || (ldate < rdate);
}

bool operator>(const Date& ldate, const Date& rdate) {
  return vector<int>{ldate.GetYear(), ldate.GetMonth(), ldate.GetDay()} >
         vector<int>{rdate.GetYear(), rdate.GetMonth(), rdate.GetDay()};
}

bool operator>=(const Date& ldate, const Date& rdate) {
  return (ldate == rdate) || (ldate > rdate);
}