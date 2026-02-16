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

int **three_sum(int *nums, int n, int *returnSize) {
  qsort(nums, n, sizeof(int), compar);
  int s = 1;
  int **res = malloc(sizeof(*res) * s);
  int counter = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > 0)
      break;
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int l = i + 1, h = n - 1;
    while (l < h) {
      int t = nums[i] + nums[l] + nums[h];
      if (t < 0) {
        l++;
      }
      if (t > 0) {
        h--;
      }
      if (t == 0) {
        int *triplet = malloc(sizeof(int) * 3);
        triplet[0] = nums[i];
        triplet[1] = nums[l];
        triplet[2] = nums[h];
        if (counter >= s) {
          res = realloc(res, sizeof(*res) * s * 2);
          s *= 2;
        }
        res[counter++] = triplet;
        l++;
        h--;
        while (l < h && nums[l] == nums[l - 1]) {
          l++;
        }
      }
    }
  }
  *returnSize = counter;
  return res;
}

int main(void) {
  int nums[] = {-1, 0, 1, 2, -1, -4, 4, 0};
  int returnSize;
  int **res = three_sum(nums, 8, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
  }
  for (int i = 0; i < returnSize; i++) {
    free(res[i]);
  }
  free(res);
  return 0;
}
