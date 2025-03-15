#include "Transformer.h"
namespace grammar {
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
} // namespace grammar