/* Given a string s, find the length of the longest substring without duplicate characters.
 * A substring is a contiguous sequence of characters within a string.
 * Example- Input: s = "zxyzxyz"
 *          Output: 3
 *          Explanation: The string "xyz" is the longest without duplicate characters.
 *
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int longest_substring_len(string &s) {
    int l = 0, r = 0;
    int res = 0;
    unordered_set<int> set;
    for (int i = 0; i < s.size(); i++) {
      while (set.find(s[r]) != set.end()) {
        set.erase(s[l]);
        l++;
      }
      set.insert(s[r]);
      res = max(res, r - l + 1);
      r++;
    }
    return res;
  }
};

int main(void) {
  Solution s;
  string str = "aybca";
  cout << s.longest_substring_len(str) << "\n";
  return 0;
}
