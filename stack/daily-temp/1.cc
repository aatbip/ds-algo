#include <iostream>
#include <stack>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> daily_temp(std::vector<int> &temperatures) {
    std::stack<std::pair<int, int>> s;
    std::vector<int> ans(temperatures.size());
    for (int i = 0; i < temperatures.size(); i++) {
      while (!s.empty() && temperatures[i] > s.top().second) {
        ans[s.top().first] = i - s.top().first;
        s.pop();
      }
      s.push({i, temperatures[i]});
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
