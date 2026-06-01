#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double medianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int l = 0, r = nums1.size();
    while (1) {
      int part1 = (l + r) / 2;
      int part2 = (nums1.size() + nums2.size() + 1) / 2 - part1;
      int max_left1 = max(nums1[0], nums1[part1 - 1]);
      int max_left2 = max(nums2[0], nums2[part2 - 1]);
      int min_right1 = min(nums1[part1], nums1[nums1.size() - 1]);
      int min_right2 = min(nums2[part2], nums2[nums2.size() - 1]);

      if (max_left1 <= min_right2 && max_left2 <= min_right1) {
      }

      if (max_left1 > min_right2) {
        r = part1 - 1;
      } else {
        l = part1 + 1;
      }
    }

    return 0;
  }
};

int main(void) {
  Solution s;
  vector<int> nums1 = {1, 3, 8};
  vector<int> nums2 = {7, 9, 10, 11};

  cout << s.medianSortedArrays(nums1, nums2) << "\n";

  return 0;
}
