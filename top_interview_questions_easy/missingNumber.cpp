#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    std::unordered_set<int> set;
    for (int i : nums)
      set.insert(i);

    for (int i = 0; i < nums.size(); i++) {
      if (set.find(i) == set.end())
        return i;
    }
    return *(std::max_element(std::begin(nums), std::end(nums))) + 1;
  }

  void test() {
    std::vector<int> nums = {0};
    std::cout << missingNumber(nums);
  }
};
