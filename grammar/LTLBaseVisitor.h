
// Generated from LTL.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "LTLVisitor.h"


/**
 * This class provides an empty implementation of LTLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LTLBaseVisitor : public LTLVisitor {
public:

  virtual antlrcpp::Any visitNot(LTLParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesis(LTLParser::ParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDisjunction(LTLParser::DisjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNext(LTLParser::NextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEventually(LTLParser::EventuallyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConjunction(LTLParser::ConjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrue(LTLParser::TrueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlways(LTLParser::AlwaysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalse(LTLParser::FalseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImplication(LTLParser::ImplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUntil(LTLParser::UntilContext *ctx) override {
    return visitChildren(ctx);
  }


};

