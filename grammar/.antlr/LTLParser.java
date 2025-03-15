// Generated from /home/yuchuan/Model_Checking/grammar/LTL.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class LTLParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, EVENTUALLY=3, ALWAYS=4, NEXT=5, UNTIL=6, NOT=7, CONJUNCTION=8, 
		DISJUNCTION=9, IMPLICATION=10, TRUE=11, FALSE=12, ATOM=13, WS=14;
	public static final int
		RULE_formula = 0;
	private static String[] makeRuleNames() {
		return new String[] {
			"formula"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'F'", "'G'", "'X'", "'U'", "'!'", "'/\\'", "'\\/'", 
			"'->'", "'true'", "'false'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "EVENTUALLY", "ALWAYS", "NEXT", "UNTIL", "NOT", "CONJUNCTION", 
			"DISJUNCTION", "IMPLICATION", "TRUE", "FALSE", "ATOM", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "LTL.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public LTLParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FormulaContext extends ParserRuleContext {
		public FormulaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formula; }
	 
		public FormulaContext() { }
		public void copyFrom(FormulaContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NotContext extends FormulaContext {
		public TerminalNode NOT() { return getToken(LTLParser.NOT, 0); }
		public FormulaContext formula() {
			return getRuleContext(FormulaContext.class,0);
		}
		public NotContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParenthesisContext extends FormulaContext {
		public FormulaContext formula() {
			return getRuleContext(FormulaContext.class,0);
		}
		public ParenthesisContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DisjunctionContext extends FormulaContext {
		public List<FormulaContext> formula() {
			return getRuleContexts(FormulaContext.class);
		}
		public FormulaContext formula(int i) {
			return getRuleContext(FormulaContext.class,i);
		}
		public TerminalNode DISJUNCTION() { return getToken(LTLParser.DISJUNCTION, 0); }
		public DisjunctionContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NextContext extends FormulaContext {
		public TerminalNode NEXT() { return getToken(LTLParser.NEXT, 0); }
		public FormulaContext formula() {
			return getRuleContext(FormulaContext.class,0);
		}
		public NextContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EventuallyContext extends FormulaContext {
		public TerminalNode EVENTUALLY() { return getToken(LTLParser.EVENTUALLY, 0); }
		public FormulaContext formula() {
			return getRuleContext(FormulaContext.class,0);
		}
		public EventuallyContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConjunctionContext extends FormulaContext {
		public List<FormulaContext> formula() {
			return getRuleContexts(FormulaContext.class);
		}
		public FormulaContext formula(int i) {
			return getRuleContext(FormulaContext.class,i);
		}
		public TerminalNode CONJUNCTION() { return getToken(LTLParser.CONJUNCTION, 0); }
		public ConjunctionContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TrueContext extends FormulaContext {
		public TerminalNode TRUE() { return getToken(LTLParser.TRUE, 0); }
		public TrueContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AlwaysContext extends FormulaContext {
		public TerminalNode ALWAYS() { return getToken(LTLParser.ALWAYS, 0); }
		public FormulaContext formula() {
			return getRuleContext(FormulaContext.class,0);
		}
		public AlwaysContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FalseContext extends FormulaContext {
		public TerminalNode FALSE() { return getToken(LTLParser.FALSE, 0); }
		public FalseContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ImplicationContext extends FormulaContext {
		public List<FormulaContext> formula() {
			return getRuleContexts(FormulaContext.class);
		}
		public FormulaContext formula(int i) {
			return getRuleContext(FormulaContext.class,i);
		}
		public TerminalNode IMPLICATION() { return getToken(LTLParser.IMPLICATION, 0); }
		public ImplicationContext(FormulaContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UntilContext extends FormulaContext {
		public List<FormulaContext> formula() {
			return getRuleContexts(FormulaContext.class);
		}
		public FormulaContext formula(int i) {
			return getRuleContext(FormulaContext.class,i);
		}
		public TerminalNode UNTIL() { return getToken(LTLParser.UNTIL, 0); }
		public UntilContext(FormulaContext ctx) { copyFrom(ctx); }
	}

	public final FormulaContext formula() throws RecognitionException {
		return formula(0);
	}

	private FormulaContext formula(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		FormulaContext _localctx = new FormulaContext(_ctx, _parentState);
		FormulaContext _prevctx = _localctx;
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_formula, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(17);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NOT:
				{
				_localctx = new NotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(3);
				match(NOT);
				setState(4);
				formula(11);
				}
				break;
			case ALWAYS:
				{
				_localctx = new AlwaysContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(5);
				match(ALWAYS);
				setState(6);
				formula(10);
				}
				break;
			case EVENTUALLY:
				{
				_localctx = new EventuallyContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(7);
				match(EVENTUALLY);
				setState(8);
				formula(9);
				}
				break;
			case NEXT:
				{
				_localctx = new NextContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(9);
				match(NEXT);
				setState(10);
				formula(8);
				}
				break;
			case TRUE:
				{
				_localctx = new TrueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(11);
				match(TRUE);
				}
				break;
			case FALSE:
				{
				_localctx = new FalseContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(12);
				match(FALSE);
				}
				break;
			case T__0:
				{
				_localctx = new ParenthesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(13);
				match(T__0);
				setState(14);
				formula(0);
				setState(15);
				match(T__1);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(33);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(31);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new UntilContext(new FormulaContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_formula);
						setState(19);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(20);
						match(UNTIL);
						setState(21);
						formula(8);
						}
						break;
					case 2:
						{
						_localctx = new ImplicationContext(new FormulaContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_formula);
						setState(22);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(23);
						match(IMPLICATION);
						setState(24);
						formula(7);
						}
						break;
					case 3:
						{
						_localctx = new DisjunctionContext(new FormulaContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_formula);
						setState(25);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(26);
						match(DISJUNCTION);
						setState(27);
						formula(6);
						}
						break;
					case 4:
						{
						_localctx = new ConjunctionContext(new FormulaContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_formula);
						setState(28);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(29);
						match(CONJUNCTION);
						setState(30);
						formula(5);
						}
						break;
					}
					} 
				}
				setState(35);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return formula_sempred((FormulaContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean formula_sempred(FormulaContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u000e%\u0002\u0000\u0007\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0003\u0000\u0012\b\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0005\u0000 \b\u0000\n\u0000\f\u0000#\t"+
		"\u0000\u0001\u0000\u0000\u0001\u0000\u0001\u0000\u0000\u0000-\u0000\u0011"+
		"\u0001\u0000\u0000\u0000\u0002\u0003\u0006\u0000\uffff\uffff\u0000\u0003"+
		"\u0004\u0005\u0007\u0000\u0000\u0004\u0012\u0003\u0000\u0000\u000b\u0005"+
		"\u0006\u0005\u0004\u0000\u0000\u0006\u0012\u0003\u0000\u0000\n\u0007\b"+
		"\u0005\u0003\u0000\u0000\b\u0012\u0003\u0000\u0000\t\t\n\u0005\u0005\u0000"+
		"\u0000\n\u0012\u0003\u0000\u0000\b\u000b\u0012\u0005\u000b\u0000\u0000"+
		"\f\u0012\u0005\f\u0000\u0000\r\u000e\u0005\u0001\u0000\u0000\u000e\u000f"+
		"\u0003\u0000\u0000\u0000\u000f\u0010\u0005\u0002\u0000\u0000\u0010\u0012"+
		"\u0001\u0000\u0000\u0000\u0011\u0002\u0001\u0000\u0000\u0000\u0011\u0005"+
		"\u0001\u0000\u0000\u0000\u0011\u0007\u0001\u0000\u0000\u0000\u0011\t\u0001"+
		"\u0000\u0000\u0000\u0011\u000b\u0001\u0000\u0000\u0000\u0011\f\u0001\u0000"+
		"\u0000\u0000\u0011\r\u0001\u0000\u0000\u0000\u0012!\u0001\u0000\u0000"+
		"\u0000\u0013\u0014\n\u0007\u0000\u0000\u0014\u0015\u0005\u0006\u0000\u0000"+
		"\u0015 \u0003\u0000\u0000\b\u0016\u0017\n\u0006\u0000\u0000\u0017\u0018"+
		"\u0005\n\u0000\u0000\u0018 \u0003\u0000\u0000\u0007\u0019\u001a\n\u0005"+
		"\u0000\u0000\u001a\u001b\u0005\t\u0000\u0000\u001b \u0003\u0000\u0000"+
		"\u0006\u001c\u001d\n\u0004\u0000\u0000\u001d\u001e\u0005\b\u0000\u0000"+
		"\u001e \u0003\u0000\u0000\u0005\u001f\u0013\u0001\u0000\u0000\u0000\u001f"+
		"\u0016\u0001\u0000\u0000\u0000\u001f\u0019\u0001\u0000\u0000\u0000\u001f"+
		"\u001c\u0001\u0000\u0000\u0000 #\u0001\u0000\u0000\u0000!\u001f\u0001"+
		"\u0000\u0000\u0000!\"\u0001\u0000\u0000\u0000\"\u0001\u0001\u0000\u0000"+
		"\u0000#!\u0001\u0000\u0000\u0000\u0003\u0011\u001f!";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}