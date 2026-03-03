#include <stdio.h>

int binary_search(int *arr, int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (key > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main(void) {
  // int arr[] = {2, 6, 5, 3, 10, 41, 21, 9};
  int arr[] = {2, 3, 5, 6, 9, 10, 21, 41};
  printf("%d\n", binary_search(arr, 8, 5));
  return 0;
}
