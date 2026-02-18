/*You are given an integer array heights where heights[i] represents the height of the ith bar.
 * You may choose any two bars to form a container. Return the maximum amount of water a container can store.
 *
 * Example: Input: height = [1,7,2,5,4,7,3,6]
 *                 Output: 36
 *                 Because, area = min(height[l],height[r]) * distance where distance = r-l
 *                 so, area = min(height[1], height[7]) * 7-1 = min(7, 6) * 6 = 36
 *
 * This program solves the problem using the two pointer approach. We use the height * distance formula to calculate
 * the total area of water that two bars can store. Using two pointer, we will increment or decrement the rightmost
 * or the leftmost pointers as per the condition to reach the optimal solution faster.
 * We can solve this using brute force in O(n^2) time where we will compare the area for each integer with all others.
 *
 * This is a greedy approach because at each step we make a locally optimal choic that safely eliminates impossible
 * candidates for the global maximum. We compute the area formed by the current left and right boundaries. Since the
 * area is limited by the smaller height, moving the taller pointer cannot increase the area — because the width
 * decreases while the limiting height remains the same. Therefore, we move the pointer at the smaller height, since
 * increasing the limiting height is the only way the area can improve. This greedy elimination works because we can
 * mathematically prove that no optimal solution is discarded.
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 *
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
