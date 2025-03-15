
// Generated from LTL.g4 by ANTLR 4.13.2


#include "LTLVisitor.h"

#include "LTLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LTLParserStaticData final {
  LTLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LTLParserStaticData(const LTLParserStaticData&) = delete;
  LTLParserStaticData(LTLParserStaticData&&) = delete;
  LTLParserStaticData& operator=(const LTLParserStaticData&) = delete;
  LTLParserStaticData& operator=(LTLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ltlParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LTLParserStaticData> ltlParserStaticData = nullptr;

void ltlParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ltlParserStaticData != nullptr) {
    return;
  }
#else
  assert(ltlParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LTLParserStaticData>(
    std::vector<std::string>{
      "formula"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'F'", "'G'", "'X'", "'U'", "'!'", "'/\\'", "'\\/'", 
      "'->'", "'true'", "'false'"
    },
    std::vector<std::string>{
      "", "", "", "EVENTUALLY", "ALWAYS", "NEXT", "UNTIL", "NOT", "CONJUNCTION", 
      "DISJUNCTION", "IMPLICATION", "TRUE", "FALSE", "ATOM", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,37,2,0,7,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,0,3,0,18,8,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,5,
  	0,32,8,0,10,0,12,0,35,9,0,1,0,0,1,0,1,0,0,0,45,0,17,1,0,0,0,2,3,6,0,-1,
  	0,3,4,5,7,0,0,4,18,3,0,0,11,5,6,5,4,0,0,6,18,3,0,0,10,7,8,5,3,0,0,8,18,
  	3,0,0,9,9,10,5,5,0,0,10,18,3,0,0,8,11,18,5,11,0,0,12,18,5,12,0,0,13,14,
  	5,1,0,0,14,15,3,0,0,0,15,16,5,2,0,0,16,18,1,0,0,0,17,2,1,0,0,0,17,5,1,
  	0,0,0,17,7,1,0,0,0,17,9,1,0,0,0,17,11,1,0,0,0,17,12,1,0,0,0,17,13,1,0,
  	0,0,18,33,1,0,0,0,19,20,10,7,0,0,20,21,5,6,0,0,21,32,3,0,0,8,22,23,10,
  	6,0,0,23,24,5,10,0,0,24,32,3,0,0,7,25,26,10,5,0,0,26,27,5,9,0,0,27,32,
  	3,0,0,6,28,29,10,4,0,0,29,30,5,8,0,0,30,32,3,0,0,5,31,19,1,0,0,0,31,22,
  	1,0,0,0,31,25,1,0,0,0,31,28,1,0,0,0,32,35,1,0,0,0,33,31,1,0,0,0,33,34,
  	1,0,0,0,34,1,1,0,0,0,35,33,1,0,0,0,3,17,31,33
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ltlParserStaticData = std::move(staticData);
}

}

LTLParser::LTLParser(TokenStream *input) : LTLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LTLParser::LTLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LTLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ltlParserStaticData->atn, ltlParserStaticData->decisionToDFA, ltlParserStaticData->sharedContextCache, options);
}

LTLParser::~LTLParser() {
  delete _interpreter;
}

const atn::ATN& LTLParser::getATN() const {
  return *ltlParserStaticData->atn;
}

std::string LTLParser::getGrammarFileName() const {
  return "LTL.g4";
}

const std::vector<std::string>& LTLParser::getRuleNames() const {
  return ltlParserStaticData->ruleNames;
}

const dfa::Vocabulary& LTLParser::getVocabulary() const {
  return ltlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LTLParser::getSerializedATN() const {
  return ltlParserStaticData->serializedATN;
}


//----------------- FormulaContext ------------------------------------------------------------------

LTLParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LTLParser::FormulaContext::getRuleIndex() const {
  return LTLParser::RuleFormula;
}

void LTLParser::FormulaContext::copyFrom(FormulaContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NotContext ------------------------------------------------------------------

tree::TerminalNode* LTLParser::NotContext::NOT() {
  return getToken(LTLParser::NOT, 0);
}

LTLParser::FormulaContext* LTLParser::NotContext::formula() {
  return getRuleContext<LTLParser::FormulaContext>(0);
}

LTLParser::NotContext::NotContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

LTLParser::FormulaContext* LTLParser::ParenthesisContext::formula() {
  return getRuleContext<LTLParser::FormulaContext>(0);
}

LTLParser::ParenthesisContext::ParenthesisContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DisjunctionContext ------------------------------------------------------------------

std::vector<LTLParser::FormulaContext *> LTLParser::DisjunctionContext::formula() {
  return getRuleContexts<LTLParser::FormulaContext>();
}

LTLParser::FormulaContext* LTLParser::DisjunctionContext::formula(size_t i) {
  return getRuleContext<LTLParser::FormulaContext>(i);
}

tree::TerminalNode* LTLParser::DisjunctionContext::DISJUNCTION() {
  return getToken(LTLParser::DISJUNCTION, 0);
}

LTLParser::DisjunctionContext::DisjunctionContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::DisjunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitDisjunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NextContext ------------------------------------------------------------------

tree::TerminalNode* LTLParser::NextContext::NEXT() {
  return getToken(LTLParser::NEXT, 0);
}

LTLParser::FormulaContext* LTLParser::NextContext::formula() {
  return getRuleContext<LTLParser::FormulaContext>(0);
}

LTLParser::NextContext::NextContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::NextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitNext(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EventuallyContext ------------------------------------------------------------------

tree::TerminalNode* LTLParser::EventuallyContext::EVENTUALLY() {
  return getToken(LTLParser::EVENTUALLY, 0);
}

LTLParser::FormulaContext* LTLParser::EventuallyContext::formula() {
  return getRuleContext<LTLParser::FormulaContext>(0);
}

LTLParser::EventuallyContext::EventuallyContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::EventuallyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitEventually(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConjunctionContext ------------------------------------------------------------------

std::vector<LTLParser::FormulaContext *> LTLParser::ConjunctionContext::formula() {
  return getRuleContexts<LTLParser::FormulaContext>();
}

LTLParser::FormulaContext* LTLParser::ConjunctionContext::formula(size_t i) {
  return getRuleContext<LTLParser::FormulaContext>(i);
}

tree::TerminalNode* LTLParser::ConjunctionContext::CONJUNCTION() {
  return getToken(LTLParser::CONJUNCTION, 0);
}

LTLParser::ConjunctionContext::ConjunctionContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::ConjunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitConjunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueContext ------------------------------------------------------------------

tree::TerminalNode* LTLParser::TrueContext::TRUE() {
  return getToken(LTLParser::TRUE, 0);
}

LTLParser::TrueContext::TrueContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::TrueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitTrue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AlwaysContext ------------------------------------------------------------------

tree::TerminalNode* LTLParser::AlwaysContext::ALWAYS() {
  return getToken(LTLParser::ALWAYS, 0);
}

LTLParser::FormulaContext* LTLParser::AlwaysContext::formula() {
  return getRuleContext<LTLParser::FormulaContext>(0);
}

LTLParser::AlwaysContext::AlwaysContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::AlwaysContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitAlways(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseContext ------------------------------------------------------------------

tree::TerminalNode* LTLParser::FalseContext::FALSE() {
  return getToken(LTLParser::FALSE, 0);
}

LTLParser::FalseContext::FalseContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::FalseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitFalse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImplicationContext ------------------------------------------------------------------

std::vector<LTLParser::FormulaContext *> LTLParser::ImplicationContext::formula() {
  return getRuleContexts<LTLParser::FormulaContext>();
}

LTLParser::FormulaContext* LTLParser::ImplicationContext::formula(size_t i) {
  return getRuleContext<LTLParser::FormulaContext>(i);
}

tree::TerminalNode* LTLParser::ImplicationContext::IMPLICATION() {
  return getToken(LTLParser::IMPLICATION, 0);
}

LTLParser::ImplicationContext::ImplicationContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::ImplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitImplication(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UntilContext ------------------------------------------------------------------

std::vector<LTLParser::FormulaContext *> LTLParser::UntilContext::formula() {
  return getRuleContexts<LTLParser::FormulaContext>();
}

LTLParser::FormulaContext* LTLParser::UntilContext::formula(size_t i) {
  return getRuleContext<LTLParser::FormulaContext>(i);
}

tree::TerminalNode* LTLParser::UntilContext::UNTIL() {
  return getToken(LTLParser::UNTIL, 0);
}

LTLParser::UntilContext::UntilContext(FormulaContext *ctx) { copyFrom(ctx); }


std::any LTLParser::UntilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LTLVisitor*>(visitor))
    return parserVisitor->visitUntil(this);
  else
    return visitor->visitChildren(this);
}

LTLParser::FormulaContext* LTLParser::formula() {
   return formula(0);
}

LTLParser::FormulaContext* LTLParser::formula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LTLParser::FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, parentState);
  LTLParser::FormulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, LTLParser::RuleFormula, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(17);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LTLParser::NOT: {
        _localctx = _tracker.createInstance<NotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(3);
        match(LTLParser::NOT);
        setState(4);
        formula(11);
        break;
      }

      case LTLParser::ALWAYS: {
        _localctx = _tracker.createInstance<AlwaysContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(5);
        match(LTLParser::ALWAYS);
        setState(6);
        formula(10);
        break;
      }

      case LTLParser::EVENTUALLY: {
        _localctx = _tracker.createInstance<EventuallyContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(7);
        match(LTLParser::EVENTUALLY);
        setState(8);
        formula(9);
        break;
      }

      case LTLParser::NEXT: {
        _localctx = _tracker.createInstance<NextContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(9);
        match(LTLParser::NEXT);
        setState(10);
        formula(8);
        break;
      }

      case LTLParser::TRUE: {
        _localctx = _tracker.createInstance<TrueContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(11);
        match(LTLParser::TRUE);
        break;
      }

      case LTLParser::FALSE: {
        _localctx = _tracker.createInstance<FalseContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(12);
        match(LTLParser::FALSE);
        break;
      }

      case LTLParser::T__0: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(13);
        match(LTLParser::T__0);
        setState(14);
        formula(0);
        setState(15);
        match(LTLParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(33);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(31);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<UntilContext>(_tracker.createInstance<FormulaContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleFormula);
          setState(19);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(20);
          match(LTLParser::UNTIL);
          setState(21);
          formula(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ImplicationContext>(_tracker.createInstance<FormulaContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleFormula);
          setState(22);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(23);
          match(LTLParser::IMPLICATION);
          setState(24);
          formula(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<DisjunctionContext>(_tracker.createInstance<FormulaContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleFormula);
          setState(25);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(26);
          match(LTLParser::DISJUNCTION);
          setState(27);
          formula(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ConjunctionContext>(_tracker.createInstance<FormulaContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleFormula);
          setState(28);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(29);
          match(LTLParser::CONJUNCTION);
          setState(30);
          formula(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(35);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool LTLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return formulaSempred(antlrcpp::downCast<FormulaContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LTLParser::formulaSempred(FormulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void LTLParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ltlParserInitialize();
#else
  ::antlr4::internal::call_once(ltlParserOnceFlag, ltlParserInitialize);
#endif
}
