#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int singleNumberBitwise(std::vector<int> &nums) {
    int bit = 0;
    for (int num : nums)
      bit ^= num;
    return bit;
  }

  int singleNumber(std::vector<int> &nums) {
    int i = 0;
    std::unordered_map<int, int> map;

    for (int num : nums) {
      map[num]++;
    }

    for (auto el : map) {
      if (el.second == 1)
        return el.first;
    }

    return -1;
  }

  void test() {
    std::vector<int> vec = {2, 2, 1};
    std::cout << singleNumberBitwise(vec) << std::endl;
  }
};
