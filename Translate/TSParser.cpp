#include "TSParser.h"
namespace grammar {
std::vector<std::string> GetTokens(std::string input) {
  std::vector<std::string> tokens;
  std::string token;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      if (!token.empty()) {
        tokens.push_back(token);
        token.clear();
      }
    } else {
      token.push_back(input[i]);
    }
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }
  return tokens;
}
} // namespace grammar