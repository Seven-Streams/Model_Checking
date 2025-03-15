#pragma once
#include "../grammar/LTLBaseVisitor.h"
#include "Node.h"
#include <cassert>
namespace grammar {
// This class is used to build the AST from the parse tree.
class Bkornblume : public LTLBaseVisitor {
  std::any visitNot(LTLParser::NotContext *ctx) override {
    UnaryNode *node = new UnaryNode(
        std::any_cast<Node *>(visit(ctx->children[1])), UnaryOperator::NOT);
    return static_cast<Node *>(node);
  }

  std::any visitParenthesis(LTLParser::ParenthesisContext *ctx) override {
    return visit(ctx->children[1]);
  }

  std::any visitDisjunction(LTLParser::DisjunctionContext *ctx) override {
    BinaryNode *node = new BinaryNode(
        std::any_cast<Node *>(visit(ctx->children[0])),
        std::any_cast<Node *>(visit(ctx->children[2])), BinaryOperator::OR);
    return static_cast<Node *>(node);
  }

  std::any visitNext(LTLParser::NextContext *ctx) override {
    UnaryNode *node = new UnaryNode(
        std::any_cast<Node *>(visit(ctx->children[1])), UnaryOperator::NEXT);
    return static_cast<Node *>(node);
  }

  std::any visitEventually(LTLParser::EventuallyContext *ctx) override {
    UnaryNode *node =
        new UnaryNode(std::any_cast<Node *>(visit(ctx->children[1])),
                      UnaryOperator::EVENTUALLY);
    return static_cast<Node *>(node);
  }

  std::any visitConjunction(LTLParser::ConjunctionContext *ctx) override {
    BinaryNode *node = new BinaryNode(
        std::any_cast<Node *>(visit(ctx->children[0])),
        std::any_cast<Node *>(visit(ctx->children[2])), BinaryOperator::AND);
    return static_cast<Node *>(node);
  }

  std::any visitTrue(LTLParser::TrueContext *ctx) override {
    AtomNode *node = new AtomNode("", true, true);
    return static_cast<Node *>(node);
  }

  std::any visitAlways(LTLParser::AlwaysContext *ctx) override {
    UnaryNode *node = new UnaryNode(
        std::any_cast<Node *>(visit(ctx->children[1])), UnaryOperator::ALWAYS);
    return static_cast<Node *>(node);
  }

  std::any visitFalse(LTLParser::FalseContext *ctx) override {
    AtomNode *node = new AtomNode("", false, true);
    return static_cast<Node *>(node);
  }

  std::any visitImplication(LTLParser::ImplicationContext *ctx) override {
    BinaryNode *node =
        new BinaryNode(std::any_cast<Node *>(visit(ctx->children[0])),
                       std::any_cast<Node *>(visit(ctx->children[2])),
                       BinaryOperator::IMPLIES);
    return static_cast<Node *>(node);
  }

  std::any visitAtom(LTLParser::AtomContext *ctx) override {
    AtomNode *node = new AtomNode(ctx->getText(), false, false);
    return static_cast<Node *>(node);
  }

  std::any visitUntil(LTLParser::UntilContext *ctx) override {
    BinaryNode *node = new BinaryNode(
        std::any_cast<Node *>(visit(ctx->children[0])),
        std::any_cast<Node *>(visit(ctx->children[2])), BinaryOperator::UNTIL);
    return static_cast<Node *>(node);
  }
};
} // namespace grammar
