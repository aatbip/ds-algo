#include <iostream>
#include <vector>

class Solution {

  int find_last(std::vector<int> &nums, int target) {
    int res = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        res = mid;
        low = mid + 1;
      } else if (target > nums[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

  int find_first(std::vector<int> &nums, int target) {
    int res = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        res = mid;
        high = mid - 1;
      } else if (target > nums[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

public:
  std::vector<int> search_range(std::vector<int> &nums, int target) {
    int first = find_first(nums, target);
    if (first == -1) {
      return {-1, -1};
    }
    return {first, find_last(nums, target)};
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  std::vector<int> res = s.search_range(nums, 8);
  for (int &n : res) {
    std::cout << n << " ";
  }
  return 0;
}
