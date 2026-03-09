#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool is_valid_parenthesis(string &s) {
    stack<char> st;
    int half = s.size() / 2;
    for (int i = 0; i < s.size(); i++) {
      while (i <= half - 1) {
        st.push(s[i]);
      }
      if (st.top() != s[i])
        return false;
      st.pop();
    }
    return true;
  }
};

int main(void) {
  Solution s;

  return 0;
}
