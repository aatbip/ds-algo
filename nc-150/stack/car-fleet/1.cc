/* Car fleet
 * */

#include <utility>
#include <vector>
class CarFleet {
public:
  int total_fleet(std::vector<int> &position, std::vector<int> &speed) {
    std::vector<std::pair<int, int>> pair; // position,speed pair
    for (int i = 0; i < position.size(); i++) {
      pair[i] = {position[i], speed[i]};
    }
  }
};

int main(void) { return 0; }
