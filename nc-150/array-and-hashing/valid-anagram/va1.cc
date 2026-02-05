/* Given two strings 's' and 't', return true if two strings are anagrams, otherwise return false.
 *
 * To achieve the best time complexity, we will make use of an unordered hash map.
 * Time complexity - O(n)
 * Space complexity - O(1), because at most 26 characters should be stored
 */

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(const std::string &s, const std::string &t) {
    if (s.length() != t.length()) {
      return false;
    }
    std::unordered_map<char, int> countS;
    std::unordered_map<char, int> countT;
    for (int i = 0; i < s.length(); i++) {
      countS[s[i]]++;
      countT[t[i]]++;
    }
    return countS == countT;
  }
};

int main(void) {
  Solution s;
  std::cout << s.isAnagram("bqppz", "pazpb") << "\n";
  return 0;
}
