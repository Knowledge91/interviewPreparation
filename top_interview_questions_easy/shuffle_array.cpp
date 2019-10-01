#include <iostream>
#include <iterator>
#include <random>
#include <vector>

std::vector<int> v = {1, 2, 3};
for (std::vector<int>::iterator v = v.begin(); v != v.end(); ++v) {
}
template <typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator &g) {
  std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
  std::advance(start, dis(g));
  return start;
}

template <typename Iter> Iter select_randomly(Iter start, Iter end) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return select_randomly(start, end, gen);
}

class Solution {
private:
  std::vector<int> initialVec;

public:
  Solution(std::vector<int> &nums) { initialVec = nums; }

  /** Resets the array to its original configuration and return it. */
  std::vector<int> reset() { return initialVec; }

  /** Returns a random shuffling of the array. */
  std::vector<int> shuffle() {
    srand(time(NULL));
    std::vector<int> auxVec = initialVec;
    std::vector<int> shuffledVec = initialVec;

    for (int &el : shuffledVec) {
      std::vector<int>::iterator it =
          select_randomly(auxVec.begin(), auxVec.end());
      el = *it;
      auxVec.erase(it);
    }

    return shuffledVec;
  }
};
