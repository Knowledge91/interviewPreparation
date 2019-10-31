#include <iostream>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    std::vector<int> memo(nums.size());
    std::fill(memo.begin(), memo.end(), -1);

    return helper(nums.size() - 1, nums, memo);
  }

  int helper(int i, std::vector<int> &nums, std::vector<int> &memo) {
    if (i < 0)
      return 0;

    if (memo[i] >= 0)
      return memo[i];

    memo[i] = std::max(nums[i] + helper(i - 2, nums, memo),
                       helper(i - 1, nums, memo));
    return memo[i];
  }

  void test() {
    std::vector<int> v = {2, 7, 9, 3, 1};
    std::cout << rob(v);
  }
};
