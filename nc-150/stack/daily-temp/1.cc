/* You are given an array of integers temperatures where temperatures[i] represents the daily
 * temperatures on the ith day.
 * Return an array result where result[i] is the number of days after the ith day before a warmer
 * temperature appears on a future day. If there is no day in the future where a warmer temperature will
 * appear for the ith day, set result[i] to 0 instead.
 *
 * Example - Input: temperatures = [30,38,30,36,35,40,28]
 *           Output: [1,4,1,2,1,0,0]
 **/

#include <stack>
#include <utility>
#include <vector>

class DailyTemp {
public:
  std::vector<int> get_daily(std::vector<int> &temp) {
    std::vector<int> res;
    std::stack<std::pair<int, int>> stack;
    for (int i = 0; i < temp.size(); i++) {
      while (!stack.empty() && temp[i] > stack.top().first) {
        auto t = stack.top();
        res[t.second] = i - t.second;
        stack.pop();
      }
      stack.push({temp[i], i});
    }
    return res;
  }
};

int main(void) { return 0; }
