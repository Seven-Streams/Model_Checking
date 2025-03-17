#include "Product.h"
#include <queue>
#include <stack>
namespace grammar {
Product::Product(TSParser &ts_parser, NBA &nba, Node *_root_formula) {
  root_formula = _root_formula;
  unsigned long long root_hash = root_formula->hash();
  // Initialize the states.
  for (int i = 0; i < ts_parser.state_num; i++) {
    // Initialize the properties of the state of TS.
    states[i] = std::set<NBAState>();
    auto int_properties = ts_parser.state_properties[i];
    std::set<std::string> str_properties;
    for (auto p : int_properties) {
      str_properties.insert(ts_parser.properties[p]);
    }
    // Check the consistency of the properties between the TS state and the
    // NBA state.
    for (auto nba_state : nba.states) {
      bool consistent = true;
      for (auto p : nba_state.first) {
        if (typeid(*p) == typeid(AtomNode)) {
          auto atom = dynamic_cast<AtomNode *>(p);
          if (!atom->IsConst()) {
            if (str_properties.count(atom->GetName()) == 0) {
              consistent = false;
              break;
            }
          }
        }
        if (typeid(*p) == typeid(UnaryNode)) {
          auto unary = dynamic_cast<UnaryNode *>(p);
          if (unary->getOperator() == UnaryOperator::NOT) {
            auto child = unary->getChild();
            if (typeid(*child) == typeid(AtomNode)) {
              auto atom = dynamic_cast<AtomNode *>(child);
              if (!atom->IsConst()) {
                if (str_properties.count(atom->GetName()) != 0) {
                  consistent = false;
                  break;
                }
              }
            }
          }
        }
      }
      if (consistent) {
        if (root_hash == nba_state.first.back()->hash()) {
          formula_hold[ProductState(i, nba_state)] = true;
        } else {
          formula_hold[ProductState(i, nba_state)] = false;
        }
        states[i].insert(nba_state);
      }
    }
  }

  // Initialize the transitions.
  // First, check the transitions in TS.
  for (auto t : ts_parser.transitions) {
    int from = t.first;
    for (auto des_pair : t.second) {
      int des = des_pair.second;
      // Check the transitions in NBA.
      for (auto from_nba_state : states[from]) {
        for (auto des_nba_state : states[des]) {
          std::set<NBAState> from_nba_trans = nba.transitions[from_nba_state];
          if (from_nba_trans.find(des_nba_state) != from_nba_trans.end()) {
            // If the transition is both valid in TS and NBA, then add it to
            // the product.
            if (transitions.find(ProductState(from, from_nba_state)) ==
                transitions.end()) {
              transitions[ProductState(from, from_nba_state)] =
                  std::set<ProductState>();
            }
            transitions[ProductState(from, from_nba_state)].insert(
                ProductState(des, des_nba_state));
          }
        }
      }
    }
  }

  // Initialize the initial states.
  for (auto start : ts_parser.init_states) {
    // Initialize the properties of the initial state of TS.
    auto int_properties = ts_parser.state_properties[start];
    std::set<std::string> str_properties;
    for (auto p : int_properties) {
      str_properties.insert(ts_parser.properties[p]);
    }

    // Check all the initial states of NBA.
    for (auto nba_init_state : nba.init_states) {
      auto nba_trans = nba.transitions[nba_init_state];
      for (auto nba_trans_des : nba_trans) {
        bool consistent = true;
        // Check if the state can be reached by the initial state of TS.
        for (auto formula : nba_trans_des.first) {
          if (typeid(*formula) == typeid(AtomNode)) {
            auto atom = dynamic_cast<AtomNode *>(formula);
            if (!atom->IsConst()) {
              if (str_properties.count(atom->GetName()) == 0) {
                consistent = false;
                break;
              }
            }
          }
          if (typeid(*formula) == typeid(UnaryNode)) {
            auto unary = dynamic_cast<UnaryNode *>(formula);
            if (unary->getOperator() == UnaryOperator::NOT) {
              auto child = unary->getChild();
              if (typeid(*child) == typeid(AtomNode)) {
                auto atom = dynamic_cast<AtomNode *>(child);
                if (!atom->IsConst()) {
                  if (str_properties.count(atom->GetName()) != 0) {
                    consistent = false;
                    break;
                  }
                }
              }
            }
          }
        }
        if (consistent) {
          init_states.insert(std::pair(start, nba_trans_des));
        }
      }
    }
  }
}
bool Product::reachable_cycle(ProductState s, std::set<ProductState> &R) {
  std::stack<ProductState> U;
  U.push(s);
  R.insert(s);
  bool cycle_found = false;
  while (!U.empty()) {
    if (cycle_found) {
      break;
    }
    ProductState current = U.top();
    std::cout << "Now At " << current.first << " ";
    for (auto j : current.second.first) {
      j->print();
      std::cout << " ";
    }
    std::cout << current.second.second << std::endl;
    bool all_in_R = true;
    for (auto next : transitions[current]) {
      if (R.find(next) == R.end()) {
        all_in_R = false;
        U.push(next);
        R.insert(next);
      }
    }
    if (all_in_R) {
      U.pop();
    }
    if (!formula_hold[current]) {
      cycle_found = cycle_check(current);
    }
  }
  return cycle_found;
}

bool Product::cycle_check(ProductState s) {
  bool cycle_found = false;
  std::set<ProductState> T;
  std::stack<ProductState> V;
  V.push(s);
  T.insert(s);
  while (!(V.empty())) {
    if (cycle_found) {
      break;
    }
    ProductState current = V.top();
    std::cout << "Now At " << current.first << " ";
    for (auto j : current.second.first) {
      j->print();
      std::cout << " ";
    }
    std::cout << current.second.second << std::endl;
    if (transitions[current].find(s) != transitions[current].end()) {
      cycle_found = true;
      break;
    } else {
      bool all_in_T = true;
      for (auto next : transitions[current]) {
        if (T.find(next) == T.end()) {
          all_in_T = false;
          V.push(next);
          T.insert(next);
        }
      }
      if (all_in_T) {
        V.pop();
      }
    }
  }
  return cycle_found;
}

bool Product::Check() {
  std::set<ProductState> R;
  bool cycle_found = false;
  assert(init_states.size() != 0);
  for (auto init : init_states) {
    if (cycle_found) {
      break;
    }
    if (R.find(init) != R.end()) {
      continue;
    }
    reachable_cycle(init, R);
  }
  return !cycle_found;
}

bool Product::Check(int state) {
  unsigned long long root_hash = root_formula->hash();
  std::set<ProductState> R;
  std::queue<ProductState> Q;
  for (auto init : init_states) {
    R.insert(init);
    Q.push(init);
  }
  while (!Q.empty()) {
    ProductState current = Q.front();
    Q.pop();
    if (current.first == state) {
      unsigned long long hash = current.second.first.back()->hash();
      if (hash != root_hash) {
        return false;
      }
    }
    for (auto next : transitions[current]) {
      if (R.find(next) == R.end()) {
        R.insert(next);
        Q.push(next);
      }
    }
  }
  return true;
}
} // namespace grammar