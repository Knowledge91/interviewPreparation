#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> hash_set;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
      if (hash_set.find(*it) != hash_set.end())
        return true;
      hash_set.insert(*it);
    }
    return false;
  }

  bool containsDuplicateSlow(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] == nums[j])
          return true;
      }
    }
    return false;
  }

  void test() {
    std::vector<int> vec = {3, 1};
    std::cout << containsDuplicate(vec) << std::endl;
  }
};
