/*Given two strings s and t, return the shortest substring of s such that every character in t,
 * including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".
 * You may assume that the correct output is always unique.
 *
 * Example: Input: s = "OUZODYXAZV", t = "XYZ"
 *          Output: "YXAZ"
 */

#include <algorithm>
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
    for (int r = 0; r < s.size(); r++) {
      window[s[r]]++;
      bool valid_window = true;
      for (auto &[c, cnt] : countT) {
        if (window[c] < cnt) {
          valid_window = false;
          break;
        }
      }
      while (valid_window) {
        window_size = min(r - l + 1, window_size);
        window_start_index = l;
        window[s[l]]--;
        l++;
        for (auto &[c, cnt] : countT) {
          if (window[c] < cnt) {
            valid_window = false;
            break;
          }
        }
      }
    }
    if (window_size == INT_MAX)
      return "";
    return s.substr(window_start_index, window_size);
  }
};

int main(void) {
  Solution sol;
  string s = "OUZODYXAZV";
  string t = "XYZ";
  cout << sol.minWindow(s, t) << "\n";
  return 0;
}
