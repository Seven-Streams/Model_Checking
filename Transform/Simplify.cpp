#include "Transformer.h"
#include <utility>

namespace grammar {
std::pair<Node *, bool> Simplify(Node *node) {
  // AtomNode do nothing.
  if (typeid(*node) == typeid(AtomNode)) {
    return {node, false};
  }
  if (typeid(*node) == typeid(UnaryNode)) {
    auto unary_node = dynamic_cast<UnaryNode *>(node);
    auto [child, changed] = Simplify(unary_node->getChild());
    if (child != unary_node->child) {
      unary_node->child = child;
    }
    switch (unary_node->op) {
    case grammar::UnaryOperator::NOT: {
      if (typeid(*child) == typeid(AtomNode)) {
        auto atom_node = dynamic_cast<AtomNode *>(child);
        if (atom_node->is_const) {
          atom_node->value = !atom_node->value;
          return {atom_node, true};
        }
      }

      if (typeid(*child) == typeid(UnaryNode)) {
        auto child_unary_node = dynamic_cast<UnaryNode *>(child);
        if (child_unary_node->op == grammar::UnaryOperator::NOT) {
          auto new_node = child_unary_node->getChild();
          delete child_unary_node;
          return {new_node, true};
        }
      }
      break;
    }
    case grammar::UnaryOperator::NEXT: {
      break;
    }
    case grammar::UnaryOperator::EVENTUALLY: {
      AtomNode *new_true_node = new AtomNode("", true, true);
      BinaryNode *new_until_node =
          new BinaryNode(new_true_node, child, BinaryOperator::UNTIL);
      return {new_until_node, true};
    }
    case grammar::UnaryOperator::ALWAYS: {
      UnaryNode *new_node = new UnaryNode(child, UnaryOperator::NOT);
      UnaryNode *new_eventually_node =
          new UnaryNode(new_node, UnaryOperator::EVENTUALLY);
      UnaryNode *new_node2 =
          new UnaryNode(new_eventually_node, UnaryOperator::NOT);
      Simplify(new_node2);
      return {new_node2, true};
    }
    }
    return {unary_node, changed};
  }
  if (typeid(*node) == typeid(BinaryNode)) {
    BinaryNode *binary_node = dynamic_cast<BinaryNode *>(node);
    auto [left, changed_left] = Simplify(binary_node->getLeft());
    auto [right, changed_right] = Simplify(binary_node->getRight());
    if (left != binary_node->getLeft()) {
      delete binary_node->getLeft();
      binary_node->left = left;
    }
    if (right != binary_node->getRight()) {
      delete binary_node->getRight();
      binary_node->right = right;
    }
    switch (binary_node->op) {
    case grammar::BinaryOperator::AND: {
      break;
    }
    case grammar::BinaryOperator::OR: {
      UnaryNode *new_left = new UnaryNode(left, UnaryOperator::NOT);
      UnaryNode *new_right = new UnaryNode(right, UnaryOperator::NOT);
      BinaryNode *new_node =
          new BinaryNode(new_left, new_right, BinaryOperator::AND);
      UnaryNode *new_node2 = new UnaryNode(new_node, UnaryOperator::NOT);
      return {new_node2, true};
    }
    case grammar::BinaryOperator::IMPLIES: {
      UnaryNode *new_right = new UnaryNode(right, UnaryOperator::NOT);
      BinaryNode *new_node =
          new BinaryNode(left, new_right, BinaryOperator::AND);
      return {new_node, true};
    }
    case grammar::BinaryOperator::UNTIL: {
      break;
    }
    }
    return {binary_node, changed_left || changed_right};
  }
  throw std::runtime_error("Unknown node type");
}
Node *Reverse(Node *node) {
  if (typeid(*node) == typeid(UnaryNode)) {
    auto unary = dynamic_cast<UnaryNode *>(node);
    if (unary->getOperator() == UnaryOperator::NOT) {
      return unary->getChild();
    }
  }
  UnaryNode *notNode = new UnaryNode(node, UnaryOperator::NOT);
  return notNode;
}
} // namespace grammar