#include "MCInclude.h"
#include <cassert>
using namespace antlr4;

int main() {
  int global_formula, partial_formula;
  grammar::TSParser ts_parser("ts.txt");
  std::fstream file("input.txt");
  std::string res;
  file >> global_formula >> partial_formula;
  file.ignore();
  for (int i = 0; i < global_formula; i++) {
    std::string formula;
    getline(file, formula);
    ANTLRInputStream input(formula);
    LTLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LTLParser parser(&tokens);
    tree::ParseTree *tree = parser.formula();
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
    std::set<std::string> ap;
    std::set<grammar::Node *> closure;
    std::set<unsigned long long> hashs;
    grammar::Format(output, ap);
    unsigned long long hash = output->hash();
    grammar::BuildClosure(output, closure, hashs);
    std::vector<std::pair<grammar::Node *, grammar::Node *>> pairs;
    auto element_set = grammar::GetElementSet(closure, pairs);
    grammar::GNBA gnba(element_set, output, pairs);
    grammar::NBA nba(gnba);
    grammar::Product product(ts_parser, nba, output);
    nba.print();
    product.PrintInit();
    product.PrintAllTransitions();
    product.check_hold();
    std::cout << product.Check() << std::endl;
  }
  for (int i = 0; i < partial_formula; i++) {
    int state_id;
    std::string formula;
    file >> state_id;
    file.ignore();
    std::getline(file, formula);
    ANTLRInputStream input(formula);
    LTLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LTLParser parser(&tokens);
    tree::ParseTree *tree = parser.formula();
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
    std::set<std::string> ap;
    std::set<grammar::Node *> closure;
    std::set<unsigned long long> hashs;
    grammar::Format(output, ap);
    unsigned long long hash = output->hash();
    grammar::BuildClosure(output, closure, hashs);
    std::vector<std::pair<grammar::Node *, grammar::Node *>> pairs;
    auto element_set = grammar::GetElementSet(closure, pairs);
    grammar::GNBA gnba(element_set, output, pairs);
    grammar::NBA nba(gnba);
    grammar::Product product(ts_parser, nba, output);
    std::cout << product.Check(state_id) << std::endl;
  }
  fclose(stdin);
  return 0;
}