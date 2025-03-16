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
  std::map<ProductState, bool> formula_hold;
  std::map<ProductState, std::set<ProductState>> transitions;

public:
  Product(TSParser &ts_parser, NBA &nba, Node *root_formula);
};
} // namespace grammar