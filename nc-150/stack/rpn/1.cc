/* You are given an array of strings tokens that represents a valid arithmetic expression in
 * Reverse Polish Notation (RPN).
 * Return the integer that represents the evaluation of the expression.
 * The operands may be integers or the results of other operations.
 * The operators include '+', '-', '*', and '/'.
 * Assume that division between integers always truncates toward zero.
 * Example - Input: tokens = ["1","2","+","3","*","4","-"]
 *           Output: 5
 *           Explanation: ((1 + 2) * 3) - 4 = 5
 * */

#include <stack>
#include <string>
#include <vector>

class RPN {
public:
  int eval(std::vector<std::string> &exp) {
    std::stack<std::string> stack;
    for (auto e : exp) {
      std::vector<std::string> op{"+", "-", "/", "*"};
      stack.push(e);
    }
  }
};

int main(void) {
  RPN s;
  std::vector<std::string> exp = {"1", "2", "+", "3", "*", "4", "-"};

  return 0;
}
