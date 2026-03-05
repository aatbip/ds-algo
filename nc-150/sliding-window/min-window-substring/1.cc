/*Given two strings s and t, return the shortest substring of s such that every character in t,
 * including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".
 * You may assume that the correct output is always unique.
 *
 * Example: Input: s = "OUZODYXAZV", t = "XYZ"
 *          Output: "YXAZ"
 * */

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
    for (int i = 0; i < s.size(); i++) {
      unordered_map<char, int> countS;
      for (int j = i; j < s.size(); j++) {
        countS[s[j]]++;
        bool valid_window = true;
        for (auto &[c, cnt] : countT) {
          if (countS[c] < cnt) {
            valid_window = false;
          }
        }
      }
    }
  };
};

int main(void) { Solution s; }
