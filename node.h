//
// Created by nikita on 28.01.2021.
//
#include "date.h"
#include <string>
#include <memory>

using namespace std;

#ifndef COURSE_PROJCET_NODE_H
#define COURSE_PROJCET_NODE_H
enum class Comparison  {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

enum class LogicalOperation {
  Or,
  And
};

class Node {
public:
  virtual bool Evaluate(const Date& date_, const string& value_) const = 0;
};

class EmptyNode : public Node {
  bool Evaluate(const Date& date_, const string& value_) const override;
};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(const Comparison& new_cmp, const Date& new_date);
  bool Evaluate(const Date& date_, const string& value_) const override;

private:
  const Comparison cmp;
  const Date date;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(const Comparison& new_cmp, const string& new_value);
  bool Evaluate(const Date& date_, const string& value_) const override;
private:
  const Comparison cmp;
  const string value;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(const LogicalOperation& new_logicalOperation, shared_ptr<Node> new_left, shared_ptr<Node> new_right);
  bool Evaluate(const Date& date_, const string& value_) const override;
private:
  LogicalOperation logicalOperation;
  shared_ptr<Node> left;
  shared_ptr<Node> right;
};

#endif //COURSE_PROJCET_NODE_H
