/*You are given an array of non-negative integers height which represent an elevation map.
 * Each value height[i] represents the height of a bar, which has a width of 1.
 * Return the maximum area of water that can be trapped between the bars.
 *
 * Example- Input: height = [0,2,0,3,1,0,1,3,2,1]
 *                 Output: 9
 *
 * In this program we solve the problem using two pointer approach. We are calculating the area of water
 * each ith bar can hold and summing it all up.
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 */

#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int max_area(int *height, int n) {
  int area = 0;
  int l = 0, r = n - 1;
  int maxLeft = height[l];
  int maxRight = height[r];
  while (l < r) {
    if (maxLeft < maxRight) {
      l++;
      if (height[l] > maxLeft) {
        maxLeft = height[l];
      }
      area += maxLeft - height[l];
    } else {
      r--;
      if (height[r] > maxRight) {
        maxRight = height[r];
      }
      area += maxRight - height[r];
    }
  }
  return area;
}

int main(void) {
  int height[] = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
  printf("%d\n", max_area(height, 10));
  return 0;
}
