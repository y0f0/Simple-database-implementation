//
// Created by nikita on 27.01.2021.
//

#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

#ifndef COURSE_PROJCET_DATE_H
#define COURSE_PROJCET_DATE_H

class Date {
public:
  // конструктор выбрасывает исключение, если его аргументы некорректны
  Date(int new_year, int new_month, int new_day);

  [[nodiscard]] int GetYear() const;
  [[nodiscard]] int GetMonth() const;
  [[nodiscard]] int GetDay() const;

private:
  int year;
  int month;
  int day;
};

std::ostream& operator<<(std::ostream& stream, const Date& date);
Date ParseDate(istream& is);

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& ldate, const Date& rdate);
bool operator!=(const Date& ldate, const Date& rdate);
bool operator<=(const Date& ldate, const Date& rdate);
bool operator>(const Date& ldate, const Date& rdate);
bool operator>=(const Date& ldate, const Date& rdate);

#endif //COURSE_PROJCET_DATE_H
