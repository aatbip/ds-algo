/*Given two strings s and t, return the shortest substring of s such that every character in t,
 * including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".
 * You may assume that the correct output is always unique.
 *
 * Example: Input: s = "OUZODYXAZV", t = "XYZ"
 *          Output: "YXAZ"
 *
 *
 * */

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
    int window_len = INT_MAX;
    int window_start_index;

    for (int i = 0; i < s.size(); i++) {
      unordered_map<char, int> countS;
      for (int j = i; j < s.size(); j++) {
        countS[s[j]]++;

        bool valid_window = true;

        for (auto &[c, cnt] : countT) {
          if (countS[c] < cnt) {
            valid_window = false;
            break;
          }
        }

        if (valid_window && j - i + 1 < window_len) {
          window_len = j - i + 1;
          window_start_index = i;
        }
      }
    }
    if (window_len == INT_MAX)
      return "";
    return s.substr(window_start_index, window_len);
  };
};

int main(void) {
  Solution sol;
  string s = "OUXTAYBZXC";
  string t = "XYZ";
  cout << sol.minWindow(s, t) << "\n";
  return 0;
}
