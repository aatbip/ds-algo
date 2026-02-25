/* You are given a string s consisting of only uppercase english characters and an integer k.
 * You can choose up to k characters of the string and replace them with any other uppercase
 * English character. After performing at most k replacements, return the length of the longest
 * substring which contains only one distinct character.
 * Example - Input: s = "XYYX", k = 2
 *           Output: 4
 *           Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.
 *
 * In this program, we solve the problem using brute force approach. We make use of an unordered_map
 * to track the frequency of characters and then iterate through every character sequences to see
 * if valid window exist. Window becomes invalid `window size(ie j-i+1) - max_frequency > k`, in simple
 * terms, if there are more characters in the window that should be replaced than the number max characters
 * that can be replaced (k).
 * */

#include <algorithm>
#include <iostream>
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
  cout << s.get_longest(str, 0) << "\n";
  return 0;
}
