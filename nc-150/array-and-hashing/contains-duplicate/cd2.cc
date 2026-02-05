/* Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
 *
 * This problem can be solved using a hashing data structure in order to search for already encountered elements of the
 * array. We will make use of unordered_set since we can search for the element in constant time complexity. With this
 * approach the complexity analysis is as follows -
 * Time complexity: O(n)
 * Space complexity: O(n), because we create the set data structure which will possibly store all the elements at most
 * */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int contains_duplicate(vector<int> &arr) {
    unordered_set<int> s;
    for (auto el : arr) {
      auto ch = s.find(el);
      if (ch != s.end()) {
        if (*ch == el) {
          return 1;
        }
      }
      s.insert(el);
    }
    return 0;
  }
};

int main(void) {
  vector<int> arr = {99, 1, 3, 4, 99};
  Solution s;
  cout << s.contains_duplicate(arr) << "\n";
  return 0;
}
