#pragma once
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
namespace grammar {
std::vector<std::string> GetTokens(std::string input);

class TSParser {
private:
  int state_num = 0;
  int trans_num = 0;
  std::vector<int> actions;
  std::vector<std::string> properties;
  std::set<int> init_states;
  std::map<int, std::vector<std::pair<int, int>>> transitions;
  std::map<int, std::set<int>> state_properties;

public:
  friend class Product;
  TSParser(const std::string &file_path) {
    freopen(file_path.c_str(), "r", stdin);
    std::string line;
    std::cin >> state_num;
    std::cin >> trans_num;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    auto tokens = GetTokens(line);
    for (auto &token : tokens) {
      init_states.insert(std::stoi(token));
    }
    std::getline(std::cin, line);
    tokens = GetTokens(line);
    for (auto &token : tokens) {
      actions.push_back(std::stoi(token));
    }

    std::getline(std::cin, line);
    tokens = GetTokens(line);
    for (auto &token : tokens) {
      properties.push_back(token);
    }

    for (int i = 0; i < state_num; i++) {
      transitions[i] = std::vector<std::pair<int, int>>();
    }

    for (int i = 0; i < trans_num; i++) {
      int from, to, action;
      std::cin >> from >> action >> to;
      transitions[from].push_back({action, to});
    }

    std::getline(std::cin, line);
    for (int i = 0; i < state_num; i++) {
      std::getline(std::cin, line);
      auto tokens = GetTokens(line);
      state_properties[i] = std::set<int>();
      if (tokens.size() == 1 && tokens[0] == "-1") {
        continue;
      } else {
        for (auto &token : tokens) {
          state_properties[i].insert(std::stoi(token));
        }
      }
    }
    fclose(stdin);
  }

  void Print() {
    std::cout << "State num: " << state_num << std::endl;
    std::cout << "Trans num: " << trans_num << std::endl;
    std::cout << "Init states: ";
    for (auto &state : init_states) {
      std::cout << state << " ";
    }
    std::cout << std::endl;
    std::cout << "Actions: ";
    for (auto &action : actions) {
      std::cout << action << " ";
    }
    std::cout << std::endl;
    std::cout << "Properties: ";
    for (auto &property : properties) {
      std::cout << property << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < state_num; i++) {
      for (auto &trans : transitions[i]) {
        std::cout << i << "--" << trans.first << "->" << trans.second
                  << std::endl;
      }
    }
    for (int i = 0; i < state_num; i++) {
      std::cout << i << ": ";
      for (auto &property : state_properties[i]) {
        std::cout << property << " ";
      }
      std::cout << std::endl;
    }
  }
};

} // namespace grammar