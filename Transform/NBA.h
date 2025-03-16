#pragma once
#include "../AST/Node.h"
#include <cassert>
#include <map>
#include <utility>
#include <vector>
namespace grammar {
class GNBA {
private:
  using State = std::vector<Node *>;
  using States = std::vector<State>;
  States states;
  States init_states;
  std::map<State, std::set<State>> transitions;
  std::vector<States> final_states;

public:
  GNBA(const States &input, Node *root_formula,
       const std::vector<std::pair<Node *, Node *>> &closure);
  void print() const;
  friend class NBA;
};

class NBA {
private:
  using State = std::vector<Node *>;
  using NBAState = std::pair<State, int>;
  using NBAStates = std::set<NBAState>;
  NBAStates states;
  NBAStates init_states;
  std::map<NBAState, std::set<NBAState>> transitions;
  NBAStates final_states;

public:
  NBA(const GNBA &GNBA);

  void print();
};
} // namespace grammar
