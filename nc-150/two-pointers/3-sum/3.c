/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where,
 * nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
 * The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
 *
 * Example- Input: vector<int> nums = {-1,0,1,2,-1,-4}
 *          Output: {{-1,-1,2},{-1,0,1}}
 */

#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b) {
  int n1 = *(int *)(a);
  int n2 = *(int *)(b);
  return n1 - n2;
}

int **three_sum(int *nums, int n, int *returnSize) { qsort(nums, n, sizeof(int), compar); }

int main(void) {
  int nums[] = {-1, 0, 1, 2, -1, -4, 4, 0};
  return 0;
}
