#pragma once
#include "../grammar/LTLBaseVisitor.h"
namespace grammar {
class Blornblume : public LTLBaseVisitor {
  std::any visitNot(LTLParser::NotContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitParenthesis(LTLParser::ParenthesisContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitDisjunction(LTLParser::DisjunctionContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitNext(LTLParser::NextContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitEventually(LTLParser::EventuallyContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitConjunction(LTLParser::ConjunctionContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitTrue(LTLParser::TrueContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitAlways(LTLParser::AlwaysContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitFalse(LTLParser::FalseContext *ctx)  {
    return visitChildren(ctx->children[1]);
  }

  std::any visitImplication(LTLParser::ImplicationContext *ctx)  {
    return visitChildren(ctx);
  }

  std::any visitUntil(LTLParser::UntilContext *ctx)  {
    return visitChildren(ctx);
  }
};
} // namespace grammar
