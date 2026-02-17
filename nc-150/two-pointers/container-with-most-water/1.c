#include <math.h>

int min(int a, int b) { return a < b ? a : b; }

int water_content(int *heights, int n) {
  int l = 0, r = n - 1;
  int am = 0;
  while (l <= r) {
    if (l == r) {
      am = heights[r] * 1;
    }
    if (heights[l] == 0) {
      l++;
    }
    if (heights[r] == 0) {
      r--;
    }
    int temp = min(heights[l], heights[r]) * (r - l);
    if (temp > am)
      am = temp;
    l++;
    r--;
  }
  return am;
}

int main(void) {
  int heights[] = {1, 7, 2, 5, 4, 7, 3, 6};

  return 0;
}
