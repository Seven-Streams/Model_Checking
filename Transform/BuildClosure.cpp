#include "Transformer.h"
namespace grammar {
    void Format(Node *node, std::set<std::string> &ap) {
        if(typeid(*node) == typeid(AtomNode)) {
            AtomNode *atom = dynamic_cast<AtomNode *>(node);
            if(!atom->IsConst()) {
                ap.insert(atom->GetName());
            }
            return;
        }

        if(typeid(*node) == typeid(UnaryNode)) {
            UnaryNode *unary = dynamic_cast<UnaryNode *>(node);
            Format(unary->getChild(), ap);
            return;
        }

        if(typeid(*node) == typeid(BinaryNode)) {
            BinaryNode *binary = dynamic_cast<BinaryNode *>(node);
            Format(binary->getLeft(), ap);
            Format(binary->getRight(), ap);
            if(binary->getOperator() == grammar::BinaryOperator::AND) {
                std::string left = binary->getLeft()->to_string();
                std::string right = binary->getRight()->to_string();
                if(left < right) {
                    std::swap(binary->left, binary->right);
                }
            } 
            return;
        }
    }
}