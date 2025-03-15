#include "AST/Bkornblume.h"
#include "AST/Node.h"
#include "Transform/Transformer.h"
#include "antlr4-runtime.h"
#include "grammar/LTLLexer.h"
#include "grammar/LTLParser.h"
#include <any>
#include <fstream>
#include <iostream>
#include <set>
#include "Translate/TSParser.h"
using namespace antlr4;

int main(int argc, const char *argv[]) {
  std::ifstream stream;
  stream.open("input.txt");

  ANTLRInputStream input(stream);
  LTLLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  LTLParser parser(&tokens);

  tree::ParseTree *tree = parser.formula();
  std::cout << tree->toStringTree(&parser) << std::endl;

  grammar::Bkornblume visitor;
  visitor.visit(tree);
  grammar::Node *output = std::any_cast<grammar::Node *>(visitor.visit(tree));
  while (true) {
    auto [new_output, changed] = grammar::Simplify(output);
    if (changed) {
      output = new_output;
    } else {
      break;
    }
  }
  output->print();
  std::set<std::string> ap;
  grammar::Format(output, ap);
  for (const auto &i : ap) {
    std::cout << i << std::endl;
  }
  unsigned long long hash = output->hash();
  std::cout << hash << std::endl;
  grammar::TSParser ts_parser("ts.txt");
  ts_parser.Print();
  return 0;
}