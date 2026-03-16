/*You are given an array of integers heights where heights[i] represents the height of a bar.
 * The width of each bar is 1. Return the area of the largest rectangle that can be formed
 * among the bars.
 * Example- Input: heights = [7,1,7,2,2,4]
 *          Output: 8
 * */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
class Histogram {
public:
  int histogram_area(std::vector<int> &heights) {
    int n = heights.size();
    std::stack<int> stack;
    std::vector<int> leftMost(n, -1);
    std::vector<int> rightMost(n, n);

    for (int i = 0; i < n - 1; i++) {
      while (!stack.empty() && heights[stack.top()] >= heights[i]) {
        stack.pop();
      }
      if (!stack.empty()) {
        leftMost[i] = stack.top();
      }
      stack.push(i);
    }

    for (int i = n - 1; i >= 0; i--) {
      while (!stack.empty() && heights[stack.top()] >= heights[i]) {
        stack.pop();
      }
      if (!stack.empty()) {
        rightMost[i] = stack.top();
      }
      stack.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      leftMost[i] += 1;
      rightMost[i] -= 1;
      maxArea = std::max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1));
    }
    return maxArea;
  }
};

int main(void) {
  Histogram h;
  std::vector<int> heights = {7, 1, 7, 2, 2, 4};
  std::cout << h.histogram_area(heights) << "\n";
  return 0;
}
