/*You are given an integer array heights where heights[i] represents the height of the ith bar.
 * You may choose any two bars to form a container. Return the maximum amount of water a container can store.
 *
 * Example: Input: height = [1,7,2,5,4,7,3,6]
 *                 Output: 36
 *                 Because, area = min(height[l],height[r]) * distance where distance = r-l
 *                 so, area = min(height[1], height[7]) * 7-1 = min(7, 6) * 6 = 36
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 * */

#include <math.h>
#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int max_area(int *height, int n) {
  int l = 0, r = n - 1;
  int area = 0;
  while (l < r) {
    int temp_area = min(height[l], height[r]) * (r - l);
    if (temp_area >= area)
      area = temp_area;
    if (height[l] <= height[r]) {
      l++;
    } else {
      r--;
    }
  }
  return area;
}

int main(void) {
  int height[] = {0, 2};
  printf("%d\n", max_area(height, 2));
  return 0;
}
