/* Given an array of integers `nums` and an integer `target`, return the indices i and j such that `nums[i] + nums[j] ==
 * target` and `i != j`. You may assume that every input has exactly one pair of indices i and j that satisfy the
 * condition. Return the answer with the smaller index first.
 *
 * In this program, we will solve two sum problem using brute force method.
 * Time complexity - O(n^2)
 * Space complexity - O(1)
 */

#include <stdio.h>
#include <stdlib.h>

void two_sum(int *nums, int target, int n, int *ans) {
  ans[0] = ans[1] = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] + nums[j] == target) {
        ans[0] = i;
        ans[1] = j;
        return;
      }
    }
  }
}

int main(void) {
  int arr[] = {1, 9, 2, 8, 4};
  int target = 11;
  int ans[2];
  two_sum(arr, target, 5, ans);
  printf("%d ", ans[0]);
  printf("%d \n", ans[1]);
  return 0;
}
