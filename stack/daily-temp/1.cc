#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> daily_temp(std::vector<int> &temperatures) {
    std::stack<int> s;
    std::vector<int> ans;
    for (int i = 0; i < temperatures.size(); i++) {
      int k = i + 1;
      if (s.empty()) {
        s.push(temperatures[i]);
      }
      int t = 0;
      if (t + k < temperatures.size() - 1 && s.top() > temperatures[t + k]) {
        int target = s.top();
        while (target > temperatures[t + k]) {
          s.pop();
          s.push(temperatures[t + k]);
          t++;
        }
        ans.push_back(t + 1);
      } else {
        s.pop();
        ans.push_back(k - i);
        k++;
      }
    }
    return ans;
  }
};

int main(void) {
  Solution s;
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 71, 76, 73};
  std::vector<int> ans = s.daily_temp(temperatures);
  for (int n : ans) {
    std::cout << n << " ";
  }
  return 0;
}
