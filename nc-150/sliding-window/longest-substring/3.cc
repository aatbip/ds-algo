/* Given a string s, find the length of the longest substring without duplicate characters.
 * A substring is a contiguous sequence of characters within a string.
 * Example- Input: s = "zxyzxyz"
 *          Output: 3
 *          Explanation: The string "xyz" is the longest without duplicate characters.
 *
 * In this program we solve the problem using sliding window but in a more optimal way then in 2.cc program.
 * We make use of a hash map to store last index of the character so that we can move the 'l' pointer to
 * the index beyond in one go without having to use a while loop internally.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longest_substring_len(string &s) {
    int res = 0;
    int l = 0;
    unordered_map<char, int> map; // map to store last index of each character
    for (int r = 0; r < s.size(); r++) {
      if (map.find(s[r]) != map.end()) {
        l = max(l, map[s[r]] + 1); // move l to next position
      }
      map[s[r]] = r;
      res = max(res, r - l + 1);
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
