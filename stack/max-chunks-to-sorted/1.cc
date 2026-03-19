/* You are given an integer array arr of length n that represents a permutation of the integers
 * in the range [0, n - 1]. We split arr into some number of chunks (i.e., partitions), and
 * individually sort each chunk. After concatenating them, the result should equal the sorted array.
 * Return the largest number of chunks we can make to sort the array.
 *
 * Example- Input: arr = [4,3,2,1,0]
 *          Output: 1
 *          Explanation:
 *          Splitting into two or more chunks will not return the required result.
 *          For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
 *
 * This program uses monotonic increasing stack to solve the problem. The size of the stack is the max number of
 * chunks that should be made. The elements in the stack by the end of processing are the maximun values. We chunk the
 * array with respect to the maximum values and number of elements (i.e. the maximum values left in the stack by the
 * end) tells us how many chunks to make.
 *
 * For ex: arr[]= {2, 0, 5, 4 , 9}
 * In the above example array, there are 3 maximum chunks that can be made that are {2, 0}, {5, 4} and {9}. With the
 * below program, the monotonic stack becomes {2, 5, 9} and the size of stack gives the number of chunks.
 * In the program these lines are critical -
 * int top = stack.top();
 * ..
 * stack.push(top);
 *
 * We have to keep the top element so that we can push it back. Because, the top element is the maximum element of the
 * chunk and pushing it back gives us the accurate no. of chunks later.
 *
 * Time complexity - O(n)
 * Space complexity - O(n)
 *
 * */

#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  int max_chunk(std::vector<int> &nums) {
    std::stack<int> stack;
    for (int i = 0; i < nums.size(); i++) {
      if (!stack.empty() && stack.top() >= nums[i]) {
        int top = stack.top();
        while (!stack.empty() && stack.top() >= nums[i]) {
          stack.pop();
        }
        stack.push(top);
      } else {
        stack.push(nums[i]);
      }
    }
    return stack.size();
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {2, 0, 5, 4, 9};
  std::cout << s.max_chunk(nums) << "\n";
}
