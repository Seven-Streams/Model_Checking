#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "grammar/LTLLexer.h"
#include "grammar/LTLParser.h"
#include "grammar/LTLBaseVisitor.h"

using namespace antlr4;

class MyLTLVisitor : public LTLBaseVisitor {
public:
    antlrcpp::Any visitNot(LTLParser::NotContext *ctx) override {
        std::cout << "Visiting Not node" << std::endl;
        return visitChildren(ctx);
    }

    // 你可以在这里添加更多的访问方法来处理不同的节点类型
};

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.ltl");

    ANTLRInputStream input(stream);
    LTLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LTLParser parser(&tokens);

    tree::ParseTree* tree = parser.formula();
    std::cout << tree->toStringTree(&parser) << std::endl;

    MyLTLVisitor visitor;
    visitor.visit(tree);

    return 0;
}