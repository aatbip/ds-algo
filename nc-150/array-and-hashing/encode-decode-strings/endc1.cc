/*Design an algorithm to encode a list of strings to a string. The encoded string is then sent over
 * the network and is decoded back to the original list of strings.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    if (strs.empty())
      return "";
    string encoded = "";
    for (auto &s : strs) {
      encoded += to_string(s.size()) + '#' + s;
    }
    return encoded;
  }
};

int main(void) {
  Solution s;
  vector<string> strs = {"hello", "world there"};
  cout << s.encode(strs) << "\n";

  return 0;
}
