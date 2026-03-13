/* Car fleet
 * */

#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
class CarFleet {
public:
  int total_fleet(std::vector<int> &position, std::vector<int> &speed, int target) {
    std::vector<std::pair<int, int>> pair; // position,speed pair
    for (int i = 0; i < position.size(); i++) {
      pair.push_back({position[i], speed[i]});
    }
    std::sort(pair.rbegin(), pair.rend()); // sort in descending order wrt position
    std::stack<int> stack;
    for (auto &p : pair) {
    }
  }
};

int main(void) {
  CarFleet c;
  std::vector<int> position{4, 1, 0, 7};
  std::vector<int> speed{2, 2, 1, 1};
  c.total_fleet(position, speed, 10);
  return 0;
}
