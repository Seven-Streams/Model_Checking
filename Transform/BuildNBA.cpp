#include "NBA.h"
#include <set>
#include <vector>
namespace grammar {

GNBA::GNBA(const States &input, Node *root_formula,
           const std::vector<std::pair<Node *, Node *>> &closure) {
  states = input;
  // Since the root formula must be the longest one.
  unsigned long long root_hash = root_formula->hash();
  for (auto state : states) {
    if (state.back()->hash() == root_hash) {
      init_states.push_back(state);
    }
  }
  // Check the final states of Until.
  for (auto formula : closure) {
    if (typeid(*formula.first) == typeid(BinaryNode)) {
      BinaryNode *binary = dynamic_cast<BinaryNode *>(formula.first);
      if (binary->getOperator() == BinaryOperator::UNTIL) {
        unsigned long long until_hash = binary->hash();
        unsigned long long right_hash = binary->getRight()->hash();
        States terminal;
        for (auto state : states) {
          bool flag = true;
          for (auto subformula : state) {
            // \phi_2 \in B.
            if (subformula->hash() == right_hash) {
              flag = true;
              break;
            }
            // \phi_1 U \phi_2 \in B.F
            if (until_hash == subformula->hash()) {
              flag = false;
            }
          }
          if (flag) {
            terminal.push_back(state);
          }
        }
        final_states.push_back(terminal);
      }
    }
  }
  // Build the transitions.
  for (auto state : states) {
    transitions[state] = std::set<State>();
    for (auto formula : state) {
      if (typeid(*formula) == typeid(UnaryNode)) {
        UnaryNode *unary = dynamic_cast<UnaryNode *>(formula);
        // X\phi \in B -> \phi \in B'
        if (unary->getOperator() == UnaryOperator::NEXT) {
          unsigned long long unary_hash = unary->hash();
          for (auto next_state : states) {
            bool flag = false;
            for (auto next_formula : next_state) {
              if (unary_hash == next_formula->hash()) {
                flag = true;
                break;
              }
            }
            if (flag) {
              transitions[state].insert(next_state);
            }
          }
        }
        if (unary->getOperator() == UnaryOperator::NOT) {
          auto child = unary->getChild();
          if (typeid(*child) == typeid(BinaryNode)) {
            BinaryNode *binary = dynamic_cast<BinaryNode *>(child);
            if (binary->getOperator() == BinaryOperator::UNTIL) {
              unsigned long long binary_hash = binary->hash();
              unsigned long long left_hash = binary->getLeft()->hash();
              unsigned long long right_hash = binary->getRight()->hash();
              bool left_in = false;
              for (auto sub_formula : state) {
                unsigned long long hash = sub_formula->hash();
                if (hash == left_hash) {
                  left_in = true;
                  break;
                }
              }
              if (left_in) {
                for (auto next_state : states) {
                  bool flag = true;
                  for (auto next_formula : next_state) {
                    if (next_formula->hash() == binary_hash) {
                      flag = false;
                      break;
                    }
                  }
                  if (flag) {
                    transitions[state].insert(next_state);
                  }
                }
              } else {
                for (auto next_state : states) {
                  transitions[state].insert(next_state);
                }
              }
            }
          }
          if (typeid(*child) == typeid(UnaryNode)) {
            UnaryNode *child_unary = dynamic_cast<UnaryNode *>(child);
            if (child_unary->getOperator() == UnaryOperator::NEXT) {
              unsigned long long child_hash = child_unary->getChild()->hash();
              for (auto next_state : states) {
                bool flag = true;
                for (auto next_formula : next_state) {
                  if (child_hash == next_formula->hash()) {
                    flag = false;
                    break;
                  }
                }
                if (flag) {
                  transitions[state].insert(next_state);
                }
              }
            }
          }
        }
      }
      // \phi_1 U \phi_2 \in B -> \phi_2 \in B or \phi_1 \in B and
      // \phi_1 U \phi_2 \in B'
      if (typeid(*formula) == typeid(BinaryNode)) {
        BinaryNode *binary = dynamic_cast<BinaryNode *>(formula);
        if (binary->getOperator() == BinaryOperator::UNTIL) {
          unsigned long long binary_hash = binary->hash();
          unsigned long long left_hash = binary->getLeft()->hash();
          unsigned long long right_hash = binary->getRight()->hash();
          bool left_in = false;
          bool right_in = false;
          for (auto formula : state) {
            unsigned long long hash = formula->hash();
            if (hash == right_hash) {
              right_in = true;
            }
            if (hash == binary_hash) {
              left_in = true;
            }
          }
          // Everything state can be reached.
          if (right_in) {
            for (auto next_state : states) {
              transitions[state].insert(next_state);
            }
          } else {
            // if \phi_1 U \phi_2 \in B', then B' can be reached.
            if (left_in) {
              for (auto next_state : states) {
                for (auto next_formula : next_state) {
                  if (next_formula->hash() == binary_hash) {
                    transitions[state].insert(next_state);
                    break;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void GNBA::print() const {
  std::cout << "states:" << std::endl;
  for (auto state : states) {
    for (auto formula : state) {
      formula->print();
      std::cout << " ,";
    }
    std::cout << std::endl;
  }
  std::cout << "init_states:" << std::endl;
  for (auto state : init_states) {
    for (auto formula : state) {
      formula->print();
      std::cout << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "transitions:" << std::endl;
  for (auto transition : transitions) {
    for (auto state : transition.first) {
      state->print();
      std::cout << " ";
    }
    std::cout << " -> ";
    for (auto state : transition.second) {
      for (auto formula : state) {
        formula->print();
        std::cout << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << "final_states:" << std::endl;
  for (auto final : final_states) {
    for (auto state : final) {
      for (auto formula : state) {
        formula->print();
        std::cout << " ";
      }
      std::cout << std::endl;
    }
  }
  return;
}

NBA::NBA(GNBA GNBA) {
  if (GNBA.final_states.empty()) {
    GNBA.final_states.push_back(std::vector<std::vector<Node *>>());
  }
  int final_states_size = GNBA.final_states.size();
  // Add all the states from GNBA to NBA.

  for (int i = 0; i < final_states_size; i++) {
    for (auto state : GNBA.states) {
      NBAState nba_state = std::make_pair(state, i);
      transitions[nba_state] = std::set<NBAState>();
      states.insert(nba_state);
    }
  }
  // Add all the init_states from GNBA to NBA.
  for (auto state : GNBA.init_states) {
    NBAState nba_state = std::make_pair(state, 0);
    init_states.insert(nba_state);
  }
  // Add all the final_states from GNBA to NBA.
  for (auto state : GNBA.final_states[0]) {
    NBAState nba_state = std::make_pair(state, 0);
    final_states.insert(nba_state);
  }

  // Build the transitions.
  // The final States are connected to the next duplicate state of itself.
  for (int i = 0; i < final_states_size; i++) {
    for (auto transition : GNBA.transitions) {
      NBAState from = std::pair(transition.first, i);
      bool flag = false;
      if (final_states_size != 1) {
        for (auto final_i : GNBA.final_states[i]) {
          if (transition.second.find(final_i) != transition.second.end()) {
            flag = true;
            break;
          }
        }
      }
      if (flag) {
        if (i + 1 < final_states_size) {
          NBAState to = std::pair(transition.first, i + 1);
          transitions[from].insert(to);
        } else {
          NBAState to = std::pair(transition.first, 0);
          transitions[from].insert(to);
        }
      } else {
        for (auto trans : transition.second) {
          NBAState to = std::pair(trans, i);
          transitions[from].insert(to);
        }
      }
    }
  }
}

void NBA::print() {
  std::cout << "states:" << std::endl;
  for (auto state : states) {
    for (auto formula : state.first) {
      formula->print();
      std::cout << " ";
    }
    std::cout << " " << state.second << std::endl;
  }
  std::cout << "init_states:" << std::endl;
  for (auto state : init_states) {
    for (auto formula : state.first) {
      formula->print();
      std::cout << " ";
    }
    std::cout << " " << state.second << std::endl;
  }
  std::cout << "transitions:" << std::endl;
  for (auto transition : transitions) {
    for (auto state : transition.second) {
      for (auto from_state : transition.first.first) {
        from_state->print();
        std::cout << " ";
      }
      std::cout << " " << transition.first.second << " -> " << std::endl;
      for (auto formula : state.first) {
        formula->print();
        std::cout << " ";
      }
      std::cout << " " << state.second << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << "final_states:" << std::endl;
  for (auto final : final_states) {
    for (auto state : final.first) {
      state->print();
      std::cout << " ";
    }
    std::cout << " " << final.second << std::endl;
  }
  return;
}
} // namespace grammar