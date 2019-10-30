#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &vec) {
    int local_max = 0;
    int global_max = INT_MIN;
    for (int i = 0; i < vec.size(); i++) {
      local_max = std::max(vec[i], local_max + vec[i]);
      if (local_max > global_max)
        global_max = local_max;
    }

    return global_max;
  }
  void test() {
    std::vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSubarray(vec);
  }
};
