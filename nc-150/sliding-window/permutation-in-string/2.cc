/*You are given two strings s1 and s2.
 * Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a
 * substring of s2, then return true. Both strings only contain lowercase letters.
 * Example 1: Input: s1 = "abc", s2 = "lecabee"
 *            Output: true
 * */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool permutation(string &s1, string &s2) {
    if (s1.size() > s2.size())
      return false;
    vector<int> s1_count(26, 0);
    vector<int> s2_count(26, 0);
    for (auto c : s1) {
      s1_count[c - 'a']++;
    }
    int matches = 0;
    for (int i = 0; i < 26; i++) {
      if (s1_count[i] == s2_count[i])
        matches++;
    }
    int l = 0;
    for (int r = 0; r < s2.size(); r++) {
      if (matches == 26)
        return true;
      s2_count[s2[r] - 'a']++;
      if (s1_count[s2[r] - 'a'] == s2_count[s2[r] - 'a']) {
        matches++;
      } else if (s1_count[s2[r] - 'a'] + 1 == s2_count[s2[r] - 'a']) {
        matches--;
      }
      if (r - l + 1 > s1.size()) {
        s2_count[s2[l] - 'a']--;
        if (s1_count[s2[l] - 'a'] == s2_count[s2[l] - 'a']) {
          matches++;
        } else if (s1_count[s2[l] - 'a'] - 1 == s2_count[s2[l] - 'a']) {
          matches--;
        }
        l++;
      }
    }
    return matches == 26;
  }
};

int main(void) {
  // string s1 = "abc";
  // string s2 = "lecabee";
  // string s2 = "lecaabee";
  // string s1 = "adc";
  // string s2 = "dcda";
  string s1 = "ab";
  string s2 = "eidbaooo";
  Solution s;
  cout << s.permutation(s1, s2) << "\n";
  return 0;
}
