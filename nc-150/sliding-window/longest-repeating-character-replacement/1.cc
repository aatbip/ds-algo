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
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int get_longest(string &s, int k) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      unordered_map<char, int> freq;
      int max_freq = 0;
      for (int j = i; j < s.size(); j++) {
        freq[s[j]]++;
        max_freq = max(max_freq, freq[s[j]]);
        if ((j - i + 1) - max_freq <= k) {
          res = max(res, j - i + 1);
        }
      }
    }
    return res;
  }
};

int main(void) {
  Solution s;
  string str = "XYYX";
  return 0;
}
