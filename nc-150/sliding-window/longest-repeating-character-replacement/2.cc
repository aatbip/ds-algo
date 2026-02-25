/* You are given a string s consisting of only uppercase english characters and an integer k.
 * You can choose up to k characters of the string and replace them with any other uppercase
 * English character. After performing at most k replacements, return the length of the longest
 * substring which contains only one distinct character.
 * Example - Input: s = "XYYX", k = 2
 *           Output: 4
 *           Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.
 *
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longest_replacement(string &s, int k) {
    int l = 0;
    unordered_map<char, int> freq_map;
    int max_freq = 0;
    int res = 0;
    for (int r = 0; r < s.size(); r++) {
      freq_map[s[r]]++;
      max_freq = max(max_freq, freq_map[s[r]]);
      while ((r - l + 1) - max_freq > k) { // while the window is invalid shirnk left
        freq_map[s[l]]--;
        l++;
      }
      res = max(res, r - l + 1);
    }
    return res;
  }
};

int main(void) {
  Solution s;
  string str = "ABAB";
  cout << s.longest_replacement(str, 0) << "\n";
  return 0;
}
