#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  int well_performing_days(std::vector<int> &hours) {
    std::stack<int> s;
    int ans = INT_MIN;
    for (int i = 0; i < hours.size(); i++) {
      if (s.empty()) {
        s.push(hours[i]);
        continue;
      }

      if (hours[i] > 8)
        s.push(hours[i]);

      if (s.top() > hours[i]) {
        ans = std::max<int>(ans, s.size() + 1);
        while (!s.empty()) {
          s.pop();
        }
      }
    }
    return ans == INT_MIN ? 0 : ans;
  }
};

int main(void) {
  Solution s;

  std::vector<int> hours = {9, 9, 6, 0, 6, 6, 9};

  std::cout << s.well_performing_days(hours) << "\n";

  return 0;
}
