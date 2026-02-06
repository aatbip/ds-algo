/* Given an array of strings `strs`, group all anagrams together into sublists. You may return the output in any order.
 * Ex: Input: strs = ["act","pots","tops","cat","stop","hat"]
 *     Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
 *
 *  In this program, we solve this problem by using sorting and hash map. Each sorted `strs` will be the
 *  key of the hash map.
 *
 * Time complexity -
 *  O(m * nlogn), where 'm' is the number of total strings and 'n' is the size of the largest string
 *  Because, nlogn is for the sort algorithm which sorts each string and in worst case longest string 'n'
 *  is used for analysis so 'nlogn'. And then 'm' is for the first loop which loops through the
 *  `strs`.
 * Space complexity -
 *  O(m * n)
 *  Because of the final `ans` which is of vector<vector<string>>.
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> group_anagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    for (string &s : strs) {
      string sortedS = s;
      sort(sortedS.begin(), sortedS.end());
      m[sortedS].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto el : m) {
      ans.push_back(el.second);
    }
    return ans;
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
