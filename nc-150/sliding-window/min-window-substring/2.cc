/*Given two strings s and t, return the shortest substring of s such that every character in t,
 * including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".
 * You may assume that the correct output is always unique.
 *
 * Example: Input: s = "OUZODYXAZV", t = "XYZ"
 *          Output: "YXAZ"
 *
 * This program solves the problem using sliding window and hash map.
 *
 * Time complexity - O(n + m)
 * n = |s| -> length of string `s`
 * m = |t| -> length of string `t`
 * Now, the first for loop which increments the frequencies in `countT` has O(m) time complexity.
 * The next for loop which increments `r` has O(n) time complexity.
 * The while loop that increments `l` also increments upto length of `s` for max so it also has O(n) time complexity.
 * Now, O(n) + O(n) + O(m) = O(n + m)
 *
 * Space complexity - O(m), where 'm' is the number of unique characters in the strings
 */

#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> countT;
    for (char c : t) {
      countT[c]++;
    }
    int l = 0;
    unordered_map<char, int> window;
    int window_size = INT_MAX;
    int window_start_index;
    int have = 0;
    int need = countT.size();
    for (int r = 0; r < s.size(); r++) {
      window[s[r]]++;
      if (countT.count(s[r]) && window[s[r]] == countT[s[r]]) {
        have++;
      }
      while (have == need) {
        if (r - l + 1 < window_size) {
          window_size = r - l + 1;
          window_start_index = l;
        }
        window[s[l]]--;
        if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
          have--;
        }
        l++;
      }
    }
    if (window_size == INT_MAX)
      return "";
    return s.substr(window_start_index, window_size);
  }
};

int main(void) {
  Solution sol;
  // string s = "cabwefgewcwaefgcf";
  // string t = "cae";

  string s = "OUZODYXAZV";
  string t = "XYZO";
  cout << sol.minWindow(s, t) << "\n";
  return 0;
}
