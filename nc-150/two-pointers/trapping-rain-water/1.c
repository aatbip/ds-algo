/*You are given an array of non-negative integers height which represent an elevation map.
 * Each value height[i] represents the height of a bar, which has a width of 1.
 * Return the maximum area of water that can be trapped between the bars.
 *
 * Example- Input: height = [0,2,0,3,1,0,1,3,2,1]
 *                 Output: 9
 *
 * */

int max_area(int *height, int n) {
  int area = 0;
  int maxRight = 0;
  int maxLeft = 0;
  for (int i = 0; i < n; i++) {

    for (int j = i + 1; j < n; j++) {
      if (height[j] > maxRight)
        maxRight = height[j];
    }
    for (int j = 0; j < i - 1; j++) {
      if (height[j] > maxLeft)
        maxLeft = height[j];
    }
  }
  return area;
}

int main(void) {
  int height[] = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};

  return 0;
}
