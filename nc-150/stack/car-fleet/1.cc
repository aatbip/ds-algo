/* There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
 * You are given two integer arrays position and speed, both of length n, where position[i] is the starting
 * mile of the ith car and speed[i] is the speed of the ith car in miles per hour.
 * A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
 * A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is
 * the minimum speed of any car in the fleet.
 * If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
 * Return the number of car fleets that will arrive at the destination.
 *
 * Example - Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
 *           Output: 3
 *           Explanation:
 *           The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
 *           The fleet forms at target. The car starting at 0 (speed 1) does not catch up to any other car,
 *           so it is a fleet by itself. The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet,
 *           meeting each other at 6. The fleet moves at speed 1 until it reaches target.
 *
 * This program solves the problem using stack. Stack is used to track the number of fleets.
 *
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
