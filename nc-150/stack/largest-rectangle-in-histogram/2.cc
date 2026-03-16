/*You are given an array of integers heights where heights[i] represents the height of a bar.
 * The width of each bar is 1. Return the area of the largest rectangle that can be formed
 * among the bars.
 * Example- Input: heights = [7,1,7,2,2,4]
 *          Output: 8
 *
 * */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class HistogramOptimal {
public:
  int histogram_area(std::vector<int> &heights) {
    int n = heights.size();
    std::stack<int> stack;
    int maxArea = 0;
    for (int i = 0; i <= n; i++) {
      while (!stack.empty() & (i == n || heights[stack.top()] > heights[i])) {
        int height = heights[stack.top()];
        stack.pop();
        int width = stack.empty() ? i : ((i - 1) - (stack.top() + 1) + 1); // i - stack.top() + 1
        maxArea = std::max(maxArea, height * width);
      }
      stack.push(i);
    }
    return maxArea;
  }
};

int main(void) {
  HistogramOptimal h;
  std::vector<int> heights = {7, 1, 7, 2, 2, 4};
  std::cout << h.histogram_area(heights) << "\n";
  return 0;
}
