/* Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except
 * nums[i]. Each product is guaranteed to fit in a 32-bit integer.
 * Example: Input: nums = [1,2,4,6]
 *          Output: [48,24,12,8]
 *
 * This problem can be solved using brute force approach which gives time complexity of O(n^2). In this program, we will
 * be using prefex-suffix (prefix sum) technique to solve this problem.
 * */

int *prod(int *arr, int n) {
  int prefix_arr[n];
  int suffix_arr[n];
  int prod[n];
  int i = 0;
  prefix_arr[i] = 1;
  suffix_arr[n - 1] = 1;
}

int main(void) {
  int arr[] = {1, 2, 3, 2};

  return 0;
}
