/*Design an algorithm to encode a list of strings to a string. The encoded string is then sent over
 * the network and is decoded back to the original list of strings.
 *
 * This program implements the `encode` and `decode` functions. `encode` function serializes the
 * vector<string> into string while `decode` function just does the opposite.
 *
 * Time complexity-
 * Let 'm' be the sum of characters in the every strings and 'n' be the total number of strings.
 * For encode function: O(m)
 * For decode function: O(m)
 *
 * Space complexity-
 * O(n+m)
 * */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    if (strs.empty())
      return "";
    vector<int> sizes;
    for (auto &s : strs) {
      sizes.push_back(s.size());
    }
    string encoded = "";
    for (int s : sizes) {
      encoded += to_string(s) + ',';
    }
    encoded += '#'; // separator between sizes and strings
    for (auto &s : strs) {
      encoded += s;
    }
    return encoded;
  }

  vector<string> decode(string &encoded) {
    if (encoded.empty())
      return {};
    vector<int> sizes;
    int i = 0;
    while (encoded[i] != '#') {
      string cur = "";
      while (encoded[i] != ',') {
        cur += encoded[i];
        i++;
      }
      sizes.push_back(stoi(cur));
      i++;
    }
    i++; // increment once again to move i past '#' separator
    vector<string> decoded;
    for (int sz : sizes) {
      decoded.push_back(encoded.substr(i, sz));
      i += sz;
    }
    return decoded;
  }
};

int main(void) {
  Solution s;
  vector<string> strs = {"hello", "world there"};
  string encoded = s.encode(strs);
  vector<string> decoded = s.decode(encoded);
  cout << "correct? " << (strs == decoded) << "\n";

  return 0;
}
