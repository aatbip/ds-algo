
#include <stack>
#include <vector>
class Solution {
public:
  int find_unsorted_subarray(std::vector<int> &nums) {
    std::stack<int> stack;
    for (int i = 0; i < nums.size(); i++) {

      stack.push(nums[i]);
    }
  }
};
