/* 395. Longest Substring with At Least K Repeating Characters
 *
 * Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each
 * character in this substring is greater than or equal to k. if no such substring exists, return 0.
 *
 * Solution- Solved using sliding window.
 *
 * Time complexity- O(n * 26) = O(n)
 * Space complexity- O(26) = O(1)
 * where n->size of string
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int longest_substring(std::string s, int k) {
    int res = 0;
    for (int targetUniqueChars = 1; targetUniqueChars <= 26; targetUniqueChars++) {
      int l = 0, r = 0;
      int charWithKFreq = 0;
      int uniquechars = 0;
      std::vector<int> freqArr(26, 0);

      while (r < s.size()) {
        if (freqArr[s[r] - 'a'] == 0)
          uniquechars++;
        if (freqArr[s[r] - 'a'] == k - 1)
          charWithKFreq++;
        freqArr[s[r] - 'a']++;

        // valid window
        if (uniquechars == targetUniqueChars && charWithKFreq == uniquechars)
          res = std::max(res, r - l + 1);

        // invalid window
        while (uniquechars > targetUniqueChars) {

          if (freqArr[s[l] - 'a'] == 1)
            uniquechars--;

          if (freqArr[s[l] - 'a'] == k)
            charWithKFreq--;

          freqArr[s[l] - 'a']--;
          l++;
        }

        r++;
      }
    }
    return res;
  }
};

int main(void) {
  Solution s;
  std::string str = "aaabb";

  std::cout << s.longest_substring(str, 2) << "\n";

  return 0;
}
