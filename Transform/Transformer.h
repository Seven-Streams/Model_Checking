#pragma once
#include "../AST/Node.h"
#include <utility>
namespace grammar {
std::pair<Node *, bool> Simplify(Node *node);
} // namespace grammar