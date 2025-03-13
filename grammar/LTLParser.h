
// Generated from LTL.g4 by ANTLR 4.7.1

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

  LTLParser(antlr4::TokenStream *input);
  ~LTLParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FormulaContext; 

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FormulaContext() : antlr4::ParserRuleContext() { }
    void copyFrom(FormulaContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NotContext : public FormulaContext {
  public:
    NotContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    FormulaContext *formula();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesisContext : public FormulaContext {
  public:
    ParenthesisContext(FormulaContext *ctx);

    FormulaContext *formula();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DisjunctionContext : public FormulaContext {
  public:
    DisjunctionContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *DISJUNCTION();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NextContext : public FormulaContext {
  public:
    NextContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *NEXT();
    FormulaContext *formula();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EventuallyContext : public FormulaContext {
  public:
    EventuallyContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *EVENTUALLY();
    FormulaContext *formula();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConjunctionContext : public FormulaContext {
  public:
    ConjunctionContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *CONJUNCTION();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueContext : public FormulaContext {
  public:
    TrueContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *TRUE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AlwaysContext : public FormulaContext {
  public:
    AlwaysContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *ALWAYS();
    FormulaContext *formula();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseContext : public FormulaContext {
  public:
    FalseContext(FormulaContext *ctx);

    antlr4::tree::TerminalNode *FALSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImplicationContext : public FormulaContext {
  public:
    ImplicationContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *IMPLICATION();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UntilContext : public FormulaContext {
  public:
    UntilContext(FormulaContext *ctx);

    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *UNTIL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FormulaContext* formula();
  FormulaContext* formula(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool formulaSempred(FormulaContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

