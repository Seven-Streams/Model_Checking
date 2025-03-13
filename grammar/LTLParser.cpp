
// Generated from LTL.g4 by ANTLR 4.7.1


#include "LTLVisitor.h"

#include "LTLParser.h"


using namespace antlrcpp;
using namespace antlr4;

LTLParser::LTLParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LTLParser::~LTLParser() {
  delete _interpreter;
}

std::string LTLParser::getGrammarFileName() const {
  return "LTL.g4";
}

const std::vector<std::string>& LTLParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LTLParser::getVocabulary() const {
  return _vocabulary;
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

antlrcpp::Any LTLParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::DisjunctionContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::NextContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::EventuallyContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::ConjunctionContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::TrueContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::AlwaysContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::FalseContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::ImplicationContext::accept(tree::ParseTreeVisitor *visitor) {
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

antlrcpp::Any LTLParser::UntilContext::accept(tree::ParseTreeVisitor *visitor) {
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
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, LTLParser::RuleFormula, precedence);

    

  auto onExit = finally([=] {
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
    case 0: return formulaSempred(dynamic_cast<FormulaContext *>(context), predicateIndex);

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

// Static vars and initialization.
std::vector<dfa::DFA> LTLParser::_decisionToDFA;
atn::PredictionContextCache LTLParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LTLParser::_atn;
std::vector<uint16_t> LTLParser::_serializedATN;

std::vector<std::string> LTLParser::_ruleNames = {
  "formula"
};

std::vector<std::string> LTLParser::_literalNames = {
  "", "'('", "')'", "'F'", "'G'", "'X'", "'U'", "'!'", "'/\\'", "'\\/'", 
  "'->'", "'true'", "'false'"
};

std::vector<std::string> LTLParser::_symbolicNames = {
  "", "", "", "EVENTUALLY", "ALWAYS", "NEXT", "UNTIL", "NOT", "CONJUNCTION", 
  "DISJUNCTION", "IMPLICATION", "TRUE", "FALSE", "ATOM", "WS"
};

dfa::Vocabulary LTLParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LTLParser::_tokenNames;

LTLParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x10, 0x27, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x14, 0xa, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x22, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x25, 0xb, 0x2, 0x3, 0x2, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x2, 0x2, 0x2, 0x2f, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x4, 0x5, 0x8, 
    0x2, 0x1, 0x2, 0x5, 0x6, 0x7, 0x9, 0x2, 0x2, 0x6, 0x14, 0x5, 0x2, 0x2, 
    0xd, 0x7, 0x8, 0x7, 0x6, 0x2, 0x2, 0x8, 0x14, 0x5, 0x2, 0x2, 0xc, 0x9, 
    0xa, 0x7, 0x5, 0x2, 0x2, 0xa, 0x14, 0x5, 0x2, 0x2, 0xb, 0xb, 0xc, 0x7, 
    0x7, 0x2, 0x2, 0xc, 0x14, 0x5, 0x2, 0x2, 0xa, 0xd, 0x14, 0x7, 0xd, 0x2, 
    0x2, 0xe, 0x14, 0x7, 0xe, 0x2, 0x2, 0xf, 0x10, 0x7, 0x3, 0x2, 0x2, 0x10, 
    0x11, 0x5, 0x2, 0x2, 0x2, 0x11, 0x12, 0x7, 0x4, 0x2, 0x2, 0x12, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x13, 0x4, 0x3, 0x2, 0x2, 0x2, 0x13, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x13, 0x9, 0x3, 0x2, 0x2, 0x2, 0x13, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x13, 0xd, 0x3, 0x2, 0x2, 0x2, 0x13, 0xe, 0x3, 0x2, 0x2, 0x2, 0x13, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x14, 0x23, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 
    0xc, 0x9, 0x2, 0x2, 0x16, 0x17, 0x7, 0x8, 0x2, 0x2, 0x17, 0x22, 0x5, 
    0x2, 0x2, 0xa, 0x18, 0x19, 0xc, 0x8, 0x2, 0x2, 0x19, 0x1a, 0x7, 0xc, 
    0x2, 0x2, 0x1a, 0x22, 0x5, 0x2, 0x2, 0x9, 0x1b, 0x1c, 0xc, 0x7, 0x2, 
    0x2, 0x1c, 0x1d, 0x7, 0xb, 0x2, 0x2, 0x1d, 0x22, 0x5, 0x2, 0x2, 0x8, 
    0x1e, 0x1f, 0xc, 0x6, 0x2, 0x2, 0x1f, 0x20, 0x7, 0xa, 0x2, 0x2, 0x20, 
    0x22, 0x5, 0x2, 0x2, 0x7, 0x21, 0x15, 0x3, 0x2, 0x2, 0x2, 0x21, 0x18, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 0x2, 0x5, 0x13, 0x21, 0x23, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LTLParser::Initializer LTLParser::_init;
