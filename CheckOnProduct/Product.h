#pragma once
#include "../Transform/NBA.h"
#include "../Translate/TSParser.h"
namespace grammar {
class Product {
private:
  using State = std::vector<Node *>;
  using NBAState = std::pair<State, int>;
  using NBAStates = std::set<NBAState>;

  // The first element is the state of the transition system, and the second
  // element is the state of the NBA.
  using ProductState = std::pair<int, NBAState>;

  std::map<int, std::set<NBAState>> states;
  std::set<ProductState> init_states;
  std::map<ProductState, bool> not_finals;
  std::map<ProductState, std::set<ProductState>> transitions;
  Node *root_formula;

  bool cycle_check(ProductState s);

  bool reachable_cycle(ProductState s, std::set<ProductState> &R);

public:
  Product(TSParser &ts_parser, NBA &nba, Node *root_formula);
  // If it holds, return true; otherwise, return false.
  bool Check();

  void check_hold() {
    for (auto i : not_finals) {
      std::cout << i.first.first << " ";
      for (auto j : i.first.second.first) {
        j->print();
        std::cout << " ";
      }
      std::cout << i.first.second.second << ":" << " " << i.second << std::endl;
    }
    return;
  }

  void PrintInit() {
    std::cout << "Init States:" << std::endl;
    for (auto i : init_states) {
      std::cout << i.first << " ";
      for (auto j : i.second.first) {
        j->print();
        std::cout << " ";
      }
      std::cout << i.second.second << std::endl;
    }
  }

  void PrintAllTransitions() {
    std::cout << "All Transitions:" << std::endl;
    for (auto t : transitions) {
      for (auto des : t.second) {
        std::cout << t.first.first << " ";
        for (auto j : t.first.second.first) {
          j->print();
          std::cout << " ";
        }
        std::cout << t.first.second.second << " -> " << std::endl;
        std::cout << des.first << " ";
        for (auto j : des.second.first) {
          j->print();
          std::cout << " ";
        }
        std::cout << des.second.second << std::endl;
      }
      std::cout << std::endl;
    }
  }

};
} // namespace grammar