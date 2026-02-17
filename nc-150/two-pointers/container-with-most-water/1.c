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
