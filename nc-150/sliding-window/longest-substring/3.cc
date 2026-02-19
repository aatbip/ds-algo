/* Given a string s, find the length of the longest substring without duplicate characters.
 * A substring is a contiguous sequence of characters within a string.
 * Example- Input: s = "zxyzxyz"
 *          Output: 3
 *          Explanation: The string "xyz" is the longest without duplicate characters.
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longest_substring_len(string &s) {
    int res;
    int l = 0;
    unordered_map<char, int> map; // map to store frequency of each character
    for (int r = 0; r < s.size(); r++) {
      if (map.find(s[r]) != map.end()) {
        l = max(l, s[r] + 1); // move l to next position
      }
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
