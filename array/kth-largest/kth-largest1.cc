/*Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Ex: Input: nums = [3,2,1,5,6,4], k = 2
 *     Output: 5
 *
 * In this program, we will solve the problem using quickselect algorithm. Quickselect algorithm
 * is similar to the quicksort algorithm but quickselect doesn't sort the array completely
 * and we only focus on once side (depending on p>k or p<k). Quickselect is mostly useful to
 * find kth-largest, kth-smallest, median in an array.
 *
 * Time complexity-
 * O(n) in average and best case while O(n^2) in worst case
 * Space complexity-
 * O(1)
 *
 */

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int kth_largest(vector<int> &nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
      int pivot_index = rand() % (right - left + 1) + left;
      int p = partition(nums, left, right, pivot_index);
      if (p == nums.size() - k) {
        return nums[p];
      } else if (p < nums.size() - k) {
        left = p + 1;
      } else {
        right = p - 1;
      }
    }
  }

private:
  int partition(vector<int> &nums, int left, int right, int pivot_index) {
    int pivot = nums[pivot_index];
    swap(nums[pivot_index], nums[right]);
    int p = left;
    for (int i = left; i < right; i++) {
      if (nums[i] < pivot) {
        swap(nums[i], nums[p]);
        p++;
      }
    }
    swap(nums[right], nums[p]);
    return p;
  }
};

int main(void) {
  Solution s;
  // vector<int> nums = {3, 2, 1, 5, 6, 4};
  // cout << s.kth_largest(nums, 2) << "\n";

  vector<int> nums;
  for (int i = 0; i <= 10000000; i++) {
    nums.push_back(i);
  }

  auto start = chrono::high_resolution_clock::now();
  for (int i = 1; i <= 100; i++) {
    printf("%d\n", s.kth_largest(nums, i));
  }
  auto end = chrono::high_resolution_clock::now();
  auto duration_ms = chrono::duration_cast<chrono::milliseconds>(end - start);
  cout << "Time: " << duration_ms.count() << " ms\n";

  return 0;
}
