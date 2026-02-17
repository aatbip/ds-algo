/*You are given an array of non-negative integers height which represent an elevation map.
 * Each value height[i] represents the height of a bar, which has a width of 1.
 * Return the maximum area of water that can be trapped between the bars.
 *
 * Example- Input: height = [0,2,0,3,1,0,1,3,2,1]
 *                 Output: 9
 *
 * In this program we solve the problem using brute force approach. We will calculate how much water
 * can a ith bar hold using the formula `min(maxRight, maxLeft) - height[i]` then sum the result to
 * get the final total area of water.
 *
 * Time complexity- O(n^2)
 * Space complexity- O(1)
 *
 * */

#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int max_area(int *height, int n) {
  int area = 0;
  for (int i = 0; i < n; i++) {
    int maxRight = height[i];
    int maxLeft = height[i];
    for (int j = 0; j < i; j++) {
      if (height[j] > maxLeft)
        maxLeft = height[j];
    }
    for (int j = i + 1; j < n; j++) {
      if (height[j] > maxRight)
        maxRight = height[j];
    }
    area += min(maxRight, maxLeft) - height[i];
  }
  return area;
}

int main(void) {
  int height[] = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
  printf("%d\n", max_area(height, 10));
  return 0;
}
