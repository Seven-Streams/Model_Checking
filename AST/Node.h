#pragma once
#include <iostream>
#include <string>
#include <set>
namespace grammar {

enum class UnaryOperator {
  NOT = 0,
  NEXT = 1,
  EVENTUALLY = 2,
  ALWAYS = 3,
};

enum class BinaryOperator {
  AND = 4,
  OR = 5,
  IMPLIES = 6,
  UNTIL = 7,
};

class Node {
public:
  virtual void print() const = 0;
  virtual std::string to_string() const = 0;
  virtual unsigned long long hash() const = 0;
  virtual ~Node() = default;
  virtual int length() const = 0;
};

class UnaryNode : public Node {
private:
  UnaryOperator op;
  Node *child;

public:
  friend std::pair<Node *, bool> Simplify(Node *node);

  int length() const override {
    return 1 + child->length();
  }

  UnaryNode(Node *child_, const UnaryOperator &op_) : child(child_), op(op_) {}

  Node *getChild() const { return child; }

  UnaryOperator getOperator() const { return op; }

  void print() const override {
    switch (op) {
    case UnaryOperator::NOT:
      std::cout << "!";
      break;
    case UnaryOperator::NEXT:
      std::cout << "X";
      break;
    case UnaryOperator::EVENTUALLY:
      std::cout << "F";
      break;
    case UnaryOperator::ALWAYS:
      std::cout << "G";
      break;
    }
    std::cout << "(";
    child->print();
    std::cout << ")";
    return;
  }
  std::string to_string() const override {
    std::string result;
    switch (op) {
    case UnaryOperator::NOT:
      result += " __NOT__ ";
      break;
    case UnaryOperator::NEXT:
      result += " __NEXT__ ";
      break;
    case UnaryOperator::EVENTUALLY:
      result += " __EVENTUALLY__ ";
      break;
    case UnaryOperator::ALWAYS:
      result += " __ALWAYS__ ";
      break;
    }
    result += child->to_string();
    return result;
  }
  unsigned long long hash() const override {
    unsigned long long op_hash = 0;
    op_hash = std::hash<int>{}(static_cast<int>(op));
    return op_hash ^ (child->hash() << 1);
  }
};

class AtomNode : public Node {
private:
  bool is_const;
  bool value;
  std::string name;

public:
  friend std::pair<Node *, bool> Simplify(Node *node);
  AtomNode(const std::string &name_, bool value_, bool is_const_)
      : name(name_), value(value_), is_const(is_const_) {}

  bool IsConst() const { return is_const; }

  bool GetValue() const {
    if (!is_const) {
      throw std::runtime_error("Value is not constant");
    }
    return value;
  }

  std::string GetName() const {
    if (is_const) {
      throw std::runtime_error("Name is not a variable");
    }
    return name;
  }

  void print() const override {
    if (is_const) {
      std::cout << (value ? "true" : "false");
    } else {
      std::cout << name;
    }
    return;
  }

  std::string to_string() const override {
    if (is_const) {
      return value ? " __TRUE__ " : "  __FALSE__ ";
    } else {
      return name;
    }
  }
  unsigned long long hash() const override {
    if(is_const) {
      return std::hash<bool>{}(value);
    }
    return std::hash<std::string>{}(name);
  }

  int length() const override {
    return 1;
  }
};

class BinaryNode : public Node {
private:
  BinaryOperator op;
  Node *left;
  Node *right;

public:
  friend std::pair<Node *, bool> Simplify(Node *node);
  friend void Format(Node *node, std::set<std::string> &ap);
  BinaryNode(Node *left_, Node *right_, const BinaryOperator &op_)
      : left(left_), right(right_), op(op_) {}

  Node *getLeft() const { return left; }

  Node *getRight() const { return right; }

  BinaryOperator getOperator() const { return op; }

  void print() const override {
    std::cout << "(";
    left->print();
    std::cout << ")";
    switch (op) {
    case BinaryOperator::AND:
      std::cout << "/\\";
      break;
    case BinaryOperator::OR:
      std::cout << "\\/";
      break;
    case BinaryOperator::IMPLIES:
      std::cout << "->";
      break;
    case BinaryOperator::UNTIL:
      std::cout << "U";
      break;
    }
    std::cout << "(";
    right->print();
    std::cout << ")";
    return;
  }

  std::string to_string() const override {
    std::string result = left->to_string();
    switch (op) {
    case BinaryOperator::AND: {
      result += " __AND__ ";
      break;
    }
    case BinaryOperator::OR: {
      result += " __OR__ ";
      break;
    }
    case BinaryOperator::IMPLIES: {
      result += " __IMPLIES__ ";
      break;
    }
    case BinaryOperator::UNTIL: {
      result += " __UNTIL__ ";
      break;
    }
    }
    result += right->to_string();
    return result;
  }
  unsigned long long hash() const override {
    unsigned long long op_hash = 0;
    op_hash = std::hash<int>{}(static_cast<int>(op));
    return op_hash ^ (left->hash() << 1) ^ (right->hash() << 2);
  }

  int length() const override {
    return 1 + left->length() + right->length();
  }
};
} // namespace grammar