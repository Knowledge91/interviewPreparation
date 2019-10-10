#include <iostream>
#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int zeroes = 0;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
      if (*it == 0) {
        nums.erase(it);
        it--;
        zeroes++;
      }
    }

    while (zeroes--)
      nums.push_back(0);
  }

  void test() {
    std::vector<int> vec = {0, 1, 0, 3, 12};
    moveZeroes(vec);

    for (int el : vec)
      std::cout << el << " ";
  }
};
