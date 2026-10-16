#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int longest_substring(std::string s, int k) {
    int res = 0;
    for (int targetUniqueChars = 1; targetUniqueChars <= 26; targetUniqueChars++) {
      int l = 0, r = 0;
      int charWithKFreq = 0;
      int uniquechars = 0;
      char freqArr[26] = {0};

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
        if (uniquechars > targetUniqueChars) {
          uniquechars--;
          charWithKFreq--;
          freqArr[s[r] - 'a']--;
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
  std::string str = "ababbc";

  std::cout << s.longest_substring(str, 2) << "\n";

  return 0;
}
