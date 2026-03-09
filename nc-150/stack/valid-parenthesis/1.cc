#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool is_valid_parenthesis(string &s) {
    stack<char> st;
    int half = s.size() / 2;
    cout << (int)'[' << (int)']' << "\n";
    for (int i = 0; i < s.size(); i++) {
      if (i <= half - 1) {
        st.push(s[i]);
      }
      if (i >= half) {
        if (st.top() - s[i] > 0)
          return false;
        st.pop();
      }
    }
    return true;
  }
};

int main(void) {
  Solution s;
  string input = "(]";
  cout << s.is_valid_parenthesis(input) << "\n";
  return 0;
}
