#include "Transformer.h"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
namespace grammar {
void DFSToGetElementarySet(const std::vector<std::pair<Node *, Node *>> &pairs,
                           Node *true_node, const int &now,
                           std::vector<Node *> now_set,
                           std::vector<std::vector<Node *>> &ElementSet);
void Format(Node *node, std::set<std::string> &ap) {
  if (typeid(*node) == typeid(AtomNode)) {
    AtomNode *atom = dynamic_cast<AtomNode *>(node);
    if (!atom->IsConst()) {
      ap.insert(atom->GetName());
    }
    return;
  }

  if (typeid(*node) == typeid(UnaryNode)) {
    UnaryNode *unary = dynamic_cast<UnaryNode *>(node);
    Format(unary->getChild(), ap);
    return;
  }

  if (typeid(*node) == typeid(BinaryNode)) {
    BinaryNode *binary = dynamic_cast<BinaryNode *>(node);
    Format(binary->getLeft(), ap);
    Format(binary->getRight(), ap);
    if (binary->getOperator() == grammar::BinaryOperator::AND) {
      std::string left = binary->getLeft()->to_string();
      std::string right = binary->getRight()->to_string();
      if (left < right) {
        std::swap(binary->left, binary->right);
      }
    }
    return;
  }
}

void BuildClosure(Node *node, std::set<Node *> &closure,
                  std::set<unsigned long long> &hash) {
  if (typeid(*node) == typeid(AtomNode)) {
    AtomNode *atom = dynamic_cast<AtomNode *>(node);
    if (!atom->IsConst()) {
      if (hash.find(atom->hash()) == hash.end()) {
        closure.insert(atom);
        hash.insert(atom->hash());
        auto opposite = new UnaryNode(atom, UnaryOperator::NOT);
        closure.insert(opposite);
        hash.insert(opposite->hash());
      }
    } else {
      if (hash.find(atom->hash()) == hash.end()) {
        closure.insert(atom);
        hash.insert(atom->hash());
        auto opposite = new AtomNode("", !atom->GetValue(), true);
        closure.insert(opposite);
        hash.insert(opposite->hash());
      }
    }
    return;
  }
  if (typeid(*node) == typeid(UnaryNode)) {
    // remark: A "not" formula will never be added until its child is added.
    UnaryNode *unary = dynamic_cast<UnaryNode *>(node);
    BuildClosure(unary->getChild(), closure, hash);
    if (hash.find(unary->hash()) == hash.end()) {
      closure.insert(unary);
      hash.insert(unary->hash());
      auto opposite = new UnaryNode(unary->getChild(), UnaryOperator::NOT);
      closure.insert(opposite);
      hash.insert(opposite->hash());
    }
    return;
  }

  if (typeid(*node) == typeid(BinaryNode)) {
    BinaryNode *binary = dynamic_cast<BinaryNode *>(node);
    BuildClosure(binary->getLeft(), closure, hash);
    BuildClosure(binary->getRight(), closure, hash);
    if (hash.find(binary->hash()) == hash.end()) {
      closure.insert(binary);
      hash.insert(binary->hash());
      auto opposite = new UnaryNode(node, UnaryOperator::NOT);
      closure.insert(opposite);
      hash.insert(opposite->hash());
    }
    return;
  }
}

std::vector<std::vector<Node *>>
GetElementSet(const std::set<Node *> &closure) {
  std::vector<std::pair<Node *, Node *>> pairs;
  std::vector<std::vector<Node *>> elementary_set;
  Node *true_node = nullptr;
  Node *false_node = nullptr;

  // This part is used to match the subformula with its negation.
  for (auto i : closure) {
    if (typeid(*i) == typeid(AtomNode)) {
      AtomNode *atom = dynamic_cast<AtomNode *>(i);
      if (atom->IsConst()) {
        if (atom->GetValue()) {
          true_node = atom;
        } else {
          false_node = atom;
        }
      }
    }
    if (typeid(*i) == typeid(UnaryNode)) {
      UnaryNode *unary = dynamic_cast<UnaryNode *>(i);
      if (unary->getOperator() == UnaryOperator::NOT) {
        Node *child = unary->getChild();
        pairs.push_back(std::make_pair(child, unary));
      }
    }
  }
  std::sort(pairs.begin(), pairs.end(),
            [](const std::pair<Node *, Node *> &a,
               const std::pair<Node *, Node *> &b) {
              return a.first->length() < b.first->length();
            });
  if (true_node != nullptr) {
    true_node->print();
    std::cout << " ";
    false_node->print();
    std::cout << std::endl;
  }
  for (auto i : pairs) {
    i.first->print();
    std::cout << " ";
    i.second->print();
    std::cout << std::endl;
  }
  std::vector<Node *> now_subformula;
  DFSToGetElementarySet(pairs, true_node, 0, now_subformula, elementary_set);
  return elementary_set;
}
void DFSToGetElementarySet(const std::vector<std::pair<Node *, Node *>> &pairs,
                           Node *true_node, const int &now,
                           std::vector<Node *> now_set,
                           std::vector<std::vector<Node *>> &element_set) {
  // All the possible formulas are checked.
  if (now >= pairs.size()) {
    element_set.push_back(now_set);
    return;
  }

  // This part is to handle True.
  if ((now == 0) && (true_node != nullptr)) {
    now_set.push_back(true_node);
    DFSToGetElementarySet(pairs, true_node, now + 1, now_set, element_set);
    return;
  }
  auto value = pairs[now].first;
  if (typeid(*value) == typeid(BinaryNode)) {
    BinaryNode *binary = dynamic_cast<BinaryNode *>(value);
    auto left_hash = binary->getLeft()->hash();
    auto right_hash = binary->getRight()->hash();
    bool left_flag = false;
    bool right_flag = false;
    for (auto i : now_set) {
      if (i->hash() == left_hash) {
        left_flag = true;
      }
      if (i->hash() == right_hash) {
        right_flag = true;
      }
    }
    // This part is to handle propositional consistency.
    if (binary->getOperator() == BinaryOperator::AND) {
      if (left_flag && right_flag) {
        now_set.push_back(value);
        DFSToGetElementarySet(pairs, true_node, now + 1, now_set, element_set);
        return;
      } else {
        now_set.push_back(pairs[now].second);
        DFSToGetElementarySet(pairs, true_node, now + 1, now_set, element_set);
        return;
      }
    }
    // This part is to handle local until consistency.
    if (binary->getOperator() == BinaryOperator::UNTIL) {
      if (right_flag) {
        now_set.push_back(value);
        DFSToGetElementarySet(pairs, true_node, now + 1, now_set, element_set);
        return;
      } else {
        if (!left_flag) {
          now_set.push_back(pairs[now].second);
          DFSToGetElementarySet(pairs, true_node, now + 1, now_set,
                                element_set);
          return;
        } else {
          now_set.push_back(value);
          DFSToGetElementarySet(pairs, true_node, now + 1, now_set,
                                element_set);
          now_set.pop_back();
          now_set.push_back(pairs[now].second);
          DFSToGetElementarySet(pairs, true_node, now + 1, now_set,
                                element_set);
          return;
        }
      }
    }
  }

  now_set.push_back(value);
  DFSToGetElementarySet(pairs, true_node, now + 1, now_set, element_set);
  now_set.pop_back();
  now_set.push_back(pairs[now].second);
  DFSToGetElementarySet(pairs, true_node, now + 1, now_set, element_set);
  return;
}
} // namespace grammar