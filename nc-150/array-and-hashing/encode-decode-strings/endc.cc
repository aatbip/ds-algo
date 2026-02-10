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
      encoded += to_string(s);
    }
    encoded += '#';
  }
};
