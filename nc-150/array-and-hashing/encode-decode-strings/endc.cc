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
  cout << s.encode(strs) << "\n";

  return 0;
}
