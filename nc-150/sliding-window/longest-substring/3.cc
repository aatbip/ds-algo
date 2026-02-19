/* Given a string s, find the length of the longest substring without duplicate characters.
 * A substring is a contiguous sequence of characters within a string.
 * Example- Input: s = "zxyzxyz"
 *          Output: 3
 *          Explanation: The string "xyz" is the longest without duplicate characters.
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longest_substring_len(string &s) {
    int res;
    int l = 0;
    unordered_map<char, int> map;

    return res;
  }
};

int main(void) {
  Solution s;
  string str = "aybca";
  cout << s.longest_substring_len(str) << "\n";
  return 0;
}
