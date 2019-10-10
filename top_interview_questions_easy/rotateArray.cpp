#include <iostream>
#include <vector>

class Solution {
public:
  void rotateSlow(std::vector<int> &nums, int k) {
    for (int i = 0; i < k; i++) {
      int temp = nums.back();
      for (int j = nums.size() - 1; j > 0; j--) {
        nums[j] = nums[j - 1];
      }
      nums[0] = temp;
    }
  }

  void rotate(std::vector<int> &nums, int k) {
    for (int i = 0; i < k; i++) {
      nums.insert(nums.begin(), *(nums.end() - 1));
      nums.pop_back();
    }
  }

  void test() {
    std::vector<int> test = {1, 2, 3, 4, 5, 6, 7};
    rotate(test, 3);
    for (int el : test)
      std::cout << el << " ";
  }
};
