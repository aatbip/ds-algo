#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

class Solution {
public:
  std::string smallInt(std::string num, int k) {
    std::string temp = "";
    for (int i = 0; i < (int)num.size() - k; i++) {
      std::string s = "";
      for (int j = 0; j < (int)num.size(); j++) {
        if (j >= i && j <= i + k - 1)
          continue;
        s += num[j];
      }
      if (temp.empty() || s < temp) {
        temp = s;
      }
    }
    return temp.empty() ? "0" : std::to_string(std::stoi(temp));
  }
};

int main(void) {
  Solution s;
  std::string num = "10200";
  std::cout << s.smallInt(num, 1) << "\n";
  return 0;
}
