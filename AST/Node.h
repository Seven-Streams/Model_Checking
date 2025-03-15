#pragma once
#include <iostream>
#include <string>
namespace grammar {

enum class UnaryOperator {
  NOT,
  NEXT,
  EVENTUALLY,
  ALWAYS,
};

enum class BinaryOperator {
  AND,
  OR,
  IMPLIES,
  UNTIL,
};

class Node {
public:
  virtual void print() const = 0;
  virtual ~Node() = default;
};

class UnaryNode : public Node {
private:
  UnaryOperator op;
  Node *child;

public:
  friend std::pair<Node *, bool> Simplify(Node *node);
  UnaryNode(Node *child_, const UnaryOperator &op_) : child(child_), op(op_) {}

  Node *getChild() const { return child; }

  UnaryOperator getOperator() const { return op; }

  void print() const override {
    switch (op) {
    case UnaryOperator::NOT:
      std::cout << "NOT";
      break;
    case UnaryOperator::NEXT:
      std::cout << "NEXT";
      break;
    case UnaryOperator::EVENTUALLY:
      std::cout << "EVENTUALLY";
      break;
    case UnaryOperator::ALWAYS:
      std::cout << "ALWAYS";
      break;
    }
    child->print();
    return;
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
      std::cout << (value ? "TRUE" : "FALSE");
    } else {
      std::cout << name;
    }
    return;
  }
};

class BinaryNode : public Node {
private:
  BinaryOperator op;
  Node *left;
  Node *right;

public:
  friend std::pair<Node *, bool> Simplify(Node *node);
  BinaryNode(Node *left_, Node *right_, const BinaryOperator &op_)
      : left(left_), right(right_), op(op_) {}

  Node *getLeft() const { return left; }

  Node *getRight() const { return right; }

  BinaryOperator getOperator() const { return op; }

  void print() const override {
    left->print();
    switch (op) {
    case BinaryOperator::AND:
      std::cout << "AND";
      break;
    case BinaryOperator::OR:
      std::cout << "OR";
      break;
    case BinaryOperator::IMPLIES:
      std::cout << "IMPLIES";
      break;
    case BinaryOperator::UNTIL:
      std::cout << "UNTIL";
      break;
    }
    right->print();
    return;
  }
};
} // namespace grammar