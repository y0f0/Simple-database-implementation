#pragma once

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
  DATE,                 // дата
  EVENT,                // событие
  COLUMN,               // тип : "event, "data"
  LOGICAL_OP,           // логический оператор : "OR", "AND"
  COMPARE_OP,           // оператор сравнения : "<", ">", "==", "!=", "<=", ">="
  PAREN_LEFT,           // левая скобка : "("
  PAREN_RIGHT,          // правая скобка : ")"
};

struct Token {
  const string value;
  const TokenType type;
};

vector<Token> Tokenize(istream& cl);
