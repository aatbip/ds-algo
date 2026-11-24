#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int res;
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        if (nums[i] > nums[i + 1])
          res = i;
      } else if (i == nums.size() - 1) {
        if (nums[i] > nums[i - 1])
          res = i;
      } else {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
          res = i;
      }
    }
    return res;
  }
};
