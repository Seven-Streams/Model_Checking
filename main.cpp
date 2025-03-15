#include "MCInclude.h"
#include "Transform/NBA.h"
#include <utility>
#include <vector>
using namespace antlr4;

int main() {
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
  std::set<grammar::Node*> closure;
  std::set<unsigned long long> hashs;
  grammar::Format(output, ap);
  for (const auto &i : ap) {
    std::cout << i << std::endl;
  }
  unsigned long long hash = output->hash();
  grammar::TSParser ts_parser("ts.txt");
  ts_parser.Print();
  ap.clear();
  grammar::BuildClosure(output, closure, hashs);
  std::vector<std::pair<grammar::Node *, grammar::Node*>> pairs;
  auto element_set = grammar::GetElementSet(closure, pairs);
  for (const auto &i : element_set) {
    for (const auto &j : i) {
      j->print();
      std::cout << " ";
    }
    std::cout << std::endl;
  }
  grammar::GNBA gnba(element_set, output, pairs);
  gnba.print();
  return 0;
}