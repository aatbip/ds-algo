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
    std::stack<double> stack;
    for (auto &p : pair) {
      double speed = (target - p.first) / (double)p.second;
      if (!stack.empty() && speed <= stack.top())
        continue;
      stack.push(speed);
    }
    return stack.size();
  }
};

int main(void) {
  CarFleet c;
  std::vector<int> position{8, 12, 16, 11, 7};
  std::vector<int> speed{6, 9, 10, 9, 7};
  int fleet = c.total_fleet(position, speed, 17);
  std::cout << fleet << "\n";
  return 0;
}
