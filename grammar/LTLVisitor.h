
// Generated from LTL.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "LTLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LTLParser.
 */
class  LTLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LTLParser.
   */
    virtual antlrcpp::Any visitNot(LTLParser::NotContext *context) = 0;

    virtual antlrcpp::Any visitParenthesis(LTLParser::ParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitDisjunction(LTLParser::DisjunctionContext *context) = 0;

    virtual antlrcpp::Any visitNext(LTLParser::NextContext *context) = 0;

    virtual antlrcpp::Any visitEventually(LTLParser::EventuallyContext *context) = 0;

    virtual antlrcpp::Any visitConjunction(LTLParser::ConjunctionContext *context) = 0;

    virtual antlrcpp::Any visitTrue(LTLParser::TrueContext *context) = 0;

    virtual antlrcpp::Any visitAlways(LTLParser::AlwaysContext *context) = 0;

    virtual antlrcpp::Any visitFalse(LTLParser::FalseContext *context) = 0;

    virtual antlrcpp::Any visitImplication(LTLParser::ImplicationContext *context) = 0;

    virtual antlrcpp::Any visitUntil(LTLParser::UntilContext *context) = 0;


};

