// Generated from /home/yuchuan/Model_Checking/grammar/LTL.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link LTLParser}.
 */
public interface LTLListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by the {@code Not}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterNot(LTLParser.NotContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Not}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitNot(LTLParser.NotContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Parenthesis}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterParenthesis(LTLParser.ParenthesisContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Parenthesis}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitParenthesis(LTLParser.ParenthesisContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Disjunction}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterDisjunction(LTLParser.DisjunctionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Disjunction}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitDisjunction(LTLParser.DisjunctionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Next}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterNext(LTLParser.NextContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Next}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitNext(LTLParser.NextContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Eventually}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterEventually(LTLParser.EventuallyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Eventually}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitEventually(LTLParser.EventuallyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Conjunction}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterConjunction(LTLParser.ConjunctionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Conjunction}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitConjunction(LTLParser.ConjunctionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code True}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterTrue(LTLParser.TrueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code True}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitTrue(LTLParser.TrueContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Always}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterAlways(LTLParser.AlwaysContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Always}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitAlways(LTLParser.AlwaysContext ctx);
	/**
	 * Enter a parse tree produced by the {@code False}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterFalse(LTLParser.FalseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code False}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitFalse(LTLParser.FalseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Implication}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterImplication(LTLParser.ImplicationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Implication}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitImplication(LTLParser.ImplicationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Until}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterUntil(LTLParser.UntilContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Until}
	 * labeled alternative in {@link LTLParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitUntil(LTLParser.UntilContext ctx);
}