/* Given an array of strings `strs`, group all anagrams together into sublists. You may return the output in any order.
 * Ex: Input: strs = ["act","pots","tops","cat","stop","hat"]
 *     Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
 *
 * This program solves the problem using hash table of frequency array. Then frequency array will be converted
 * into string tuple in order to use it as key. Frequency array of anagram strings are identical.
 * Time complexity - O(m), because there is one loop through the `strs`
 * Space complexity - O(m * n), because of `res` of type vector<vector<string>>.
 * where,'m' is the number of total strings and 'n' is the size of the largest string
 *
 * */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> group_anagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    for (const string &s : strs) {
      vector<int> count(26, 0); // array of size 26(total alphabets) initialized to 0
      for (auto el : s) {
        count[el - 'a']++;
      }
      string key = to_string(count[0]);
      for (int i = 1; i < 26; ++i) {
        key += ',' + to_string(count[i]);
      }
      m[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto &el : m) {
      res.push_back(el.second);
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
  vector<vector<string>> ans = s.group_anagrams(strs);
  for (const auto &group : ans) {
    cout << "[ ";
    for (const auto &word : group) {
      cout << word << " ";
    }
    cout << "]\n";
  }
  return 0;
}
