/* Given a string s, find the length of the longest substring without duplicate characters.
 * A substring is a contiguous sequence of characters within a string.
 * Example- Input: s = "zxyzxyz"
 *          Output: 3
 *          Explanation: The string "xyz" is the longest without duplicate characters.
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int longest_substring_length(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      unordered_set<int> set;
      for (int j = i; j < s.size(); j++) {
        if (set.find(s[j]) != set.end())
          break;
        set.insert(s[j]);
      }
      res = max(res, (int)set.size());
    }
    return res;
  }
};

int main(void) {
  Solution s;
  string str = "zxyzxyz";
  cout << s.longest_substring_length(str) << "\n";
  return 0;
}
