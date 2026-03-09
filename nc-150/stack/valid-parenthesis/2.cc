/* You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.
 * The input string s is valid if and only if:
 * 1. Every open bracket is closed by the same type of close bracket.
 * 2. Open brackets are closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 * Return `true` if s is a valid string, and false otherwise.
 *
 * This program solves the problem using only stack.
 *
 * Time complexity - O(n)
 * Space complexity - O(n)
 *
 * */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int valid_parenthesis(string &s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(')');
      } else if (s[i] == '{') {
        st.push('}');
      } else if (s[i] == '[') {
        st.push(']');
      } else {
        if (st.empty() || st.top() != s[i]) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};

int main(void) {
  Solution s;
  string input = "((";
  cout << s.valid_parenthesis(input) << "\n";
  return 0;
}
