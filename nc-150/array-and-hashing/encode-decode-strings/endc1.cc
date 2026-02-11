/*Design an algorithm to encode a list of strings to a string. The encoded string is then sent over
 * the network and is decoded back to the original list of strings.
 *
 * This program implements optimal encode and decode functions.
 *
 * Time complexity-
 * Let 'm' be the sum of characters in the every strings and 'n' be the total number of strings.
 * Encode: O(m), because encode copies every single characters from `strs` to `res`.
 * Decode: O(m), because decode also copies every single characters from `s` to `res`.
 *
 * Space complexity-
 * O(m+n)
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string res;
    for (const string &s : strs) {
      res += to_string(s.size()) + "#" + s;
    }
    return res;
  }

  vector<string> decode(string s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
      int j = i;
      while (s[j] != '#') {
        j++;
      }
      int length = stoi(s.substr(i, j - i));
      i = j + 1;
      j = i + length;
      res.push_back(s.substr(i, length));
      i = j;
      cout << i << "\n";
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<string> strs = {"hello", "world there"};
  string encoded = s.encode(strs);
  cout << encoded << "\n";
  vector<string> decoded = s.decode(encoded);
  for (auto &s : decoded) {
    cout << s << "\n";
  }

  return 0;
}
