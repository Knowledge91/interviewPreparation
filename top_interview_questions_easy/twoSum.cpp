#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target && i != j)
          return std::vector<int>({i, j});
      }
    }

    return std::vector<int>();
  }

  void test() {
    std::vector<int> vec = {-1, -2, -3, -4, -5};

    for (int el : twoSum(vec, -8))
      std::cout << el << " ";
  }
};
