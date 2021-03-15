//
// Created by nikita on 28.01.2021.
//

#include "node.h"

DateComparisonNode::DateComparisonNode(const Comparison &new_cmp, const Date &new_date) :
  cmp(new_cmp), date(new_date) {}

EventComparisonNode::EventComparisonNode(const Comparison &new_cmp, const string &new_value) :
  cmp(new_cmp), value(new_value) {}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &new_logicalOperation, shared_ptr<Node> new_left, shared_ptr<Node> new_right) :
  logicalOperation(new_logicalOperation), left(new_left), right(new_right) {}

// Evaluate functions
bool EmptyNode::Evaluate(const Date &date_, const string &value_) const { return true; } // ??

template <class T>
bool Compare(const Comparison& cmp, const T& left, const T& right) {
  switch (cmp) {
    case Comparison::Less: return left < right;
    case Comparison::LessOrEqual: return left <= right;
    case Comparison::Equal: return left == right;
    case Comparison::Greater: return left > right;
    case Comparison::GreaterOrEqual: return left >= right;
    case Comparison::NotEqual: return left != right;
  }
  return false;
}

bool DateComparisonNode::Evaluate(const Date &date_, const string &value_) const {
  return Compare(cmp, date_, date);
}

bool EventComparisonNode::Evaluate(const Date &date_, const string &value_) const {
  return Compare(cmp, value_, value);
}

bool LogicalOperationNode::Evaluate(const Date &date_, const string &value_) const {
  if (logicalOperation == LogicalOperation::Or) {
    return left->Evaluate(date_, value_) || right->Evaluate(date_, value_);
  } else {
    return left->Evaluate(date_, value_) && right->Evaluate(date_, value_);
  }
}