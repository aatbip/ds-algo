/* You are given an array of strings tokens that represents a valid arithmetic expression in
 * Reverse Polish Notation (RPN).
 * Return the integer that represents the evaluation of the expression.
 * The operands may be integers or the results of other operations.
 * The operators include '+', '-', '*', and '/'.
 * Assume that division between integers always truncates toward zero.
 * Example - Input: tokens = ["1","2","+","3","*","4","-"]
 *           Output: 5
 *           Explanation: ((1 + 2) * 3) - 4 = 5
 *
 * In this solution, we solve the problem using stack.
 * Time complexity - O(n)
 * Space complexity - O(n)
 * */

#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

class RPN {
public:
  int eval(std::vector<std::string> &exp) {
    std::stack<int> stack;
    for (auto e : exp) {
      std::set<std::string> op{"+", "-", "*", "/"};
      if (op.count(e)) {
        int second = stack.top();
        stack.pop();
        int first = stack.top();
        stack.pop();
        if (e == "+")
          stack.push(first + second);
        if (e == "-")
          stack.push(first - second);
        if (e == "*")
          stack.push(first * second);
        if (e == "/")
          stack.push(first / second);
        continue;
      }
      stack.push(std::stoi(e));
    }
    return stack.top();
  }
};

int main(void) {
  RPN s;
  std::vector<std::string> exp = {"1", "2", "+", "3", "*", "4", "-"};
  std::cout << s.eval(exp) << "\n";

  return 0;
}
