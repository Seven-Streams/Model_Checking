#pragma once
#include "../AST/Node.h"
#include <utility>
#include <set>
namespace grammar {
//This function will simplify the LTL formula.
//The unary operator will be transformed into "not", "next" and "until".
//The binary operator will be transformed into conjunctions.
//The input should be the top formula.
std::pair<Node *, bool> Simplify(Node *node);

//This function should be called after Simplify.
//It will change the order of conjunctions to keep the unique representation.
//The return value is the set of all atomic propositions.
void Format(Node *node, std::set<std::string> &ap);
} // namespace grammar