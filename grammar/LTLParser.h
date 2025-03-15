
// Generated from LTL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LTLParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, EVENTUALLY = 3, ALWAYS = 4, NEXT = 5, UNTIL = 6, 
    NOT = 7, CONJUNCTION = 8, DISJUNCTION = 9, IMPLICATION = 10, TRUE = 11, 
    FALSE = 12, ATOM = 13, WS = 14
  };

  enum {
    RuleFormula = 0
  };

  explicit LTLParser(antlr4::TokenStream *input);

  LTLParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LTLParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FormulaContext; 

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FormulaContext() = default;
    void copyFrom(FormulaContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NotContext : public FormulaContext {
  public:
    NotContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    FormulaContext *formula();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesisContext : public FormulaContext {
  public:
    ParenthesisContext(FormulaContext *ctx);

    FormulaContext *formula();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DisjunctionContext : public FormulaContext {
  public:
    DisjunctionContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *DISJUNCTION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NextContext : public FormulaContext {
  public:
    NextContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *NEXT();
    FormulaContext *formula();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EventuallyContext : public FormulaContext {
  public:
    EventuallyContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *EVENTUALLY();
    FormulaContext *formula();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConjunctionContext : public FormulaContext {
  public:
    ConjunctionContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *CONJUNCTION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueContext : public FormulaContext {
  public:
    TrueContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *TRUE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AlwaysContext : public FormulaContext {
  public:
    AlwaysContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *ALWAYS();
    FormulaContext *formula();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseContext : public FormulaContext {
  public:
    FalseContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *FALSE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImplicationContext : public FormulaContext {
  public:
    ImplicationContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *IMPLICATION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UntilContext : public FormulaContext {
  public:
    UntilContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *UNTIL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FormulaContext* formula();
  FormulaContext* formula(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool formulaSempred(FormulaContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

