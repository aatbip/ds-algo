/*You are given two strings s1 and s2.
 * Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a
 * substring of s2, then return true. Both strings only contain lowercase letters.
 * Example 1: Input: s1 = "abc", s2 = "lecabee"
 *            Output: true
 *
 * In this program we solve the problem using sliding window technique. However, we compare s1_count and s2_count using
 * array iteration which gives additional overhead of O(k) where k = 26.
 *
 * Time complexity - O(n * k) where k = 26 (constant) so asymptomatically we can say O(n)
 * Space complexity - O(1)
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
    for (int i = 0; i < s1.size(); i++) {
      s1_count[s1[i] - 'a']++;
    }
    int l = 0;
    for (int r = 0; r < s2.size(); r++) {
      s2_count[s2[r] - 'a']++;
      if (r - l + 1 > s1.size()) {
        s2_count[s2[l] - 'a']--;
        l++;
      }
      if (s1_count == s2_count)
        return true;
    }
    return false;
  }
};

int main(void) {
  string s1 = "abc";
  // string s1 = "adc";
  string s2 = "lecabee";
  // string s2 = "lecaabee";
  // string s2 = "dcda";
  Solution s;
  cout << s.permutation(s1, s2) << "\n";
  return 0;
}
