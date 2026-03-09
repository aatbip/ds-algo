#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool is_valid_parenthesis(string &s) {
    unordered_map<char, char> map = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (map.count(s[i])) {
        st.push(map[s[i]]);
      } else {
        if (st.top() != s[i])
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
