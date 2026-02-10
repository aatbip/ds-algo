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

  vector<string> decode(string &encoded) {
    if (encoded.empty())
      return {};
    vector<string> decoded;
    int i = 0;
    while (i < encoded.size()) {
      string cur = "";
      while (encoded[i] != '#') {
        cur += encoded[i];
        i++;
      }
      i++;
      decoded.push_back(encoded.substr(i, stoi(cur)));
      i += stoi(cur);
    }
    return decoded;
  }
};

int main(void) {
  Solution s;
  vector<string> strs = {"hello", "world there"};
  string encoded = s.encode(strs);
  cout << encoded << "\n";
  vector<string> decoded = s.decode(encoded);
  for (auto s : decoded) {
    cout << s << "\n";
  }

  return 0;
}
