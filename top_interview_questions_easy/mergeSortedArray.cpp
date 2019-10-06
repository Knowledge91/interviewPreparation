#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    if (n == 0)
      return;

    for (int i = 0; i < n; i++)
      nums1.pop_back();

    std::vector<int>::iterator nums1It = nums1.begin();
    std::vector<int>::iterator nums2It = nums2.begin();
    if (*nums2It < *nums1It) {
      nums1.insert(nums1It, *nums2It);
      nums2.erase(nums2It);
    }

    while (nums2.size() != 0) {
      bool is_inserted = false;
      for (std::vector<int>::iterator it = nums1It; it != nums1.end(); it++) {
        if (*nums2It <= *it) {
          nums1.insert(it, *nums2It);
          nums1It = it;
          is_inserted = true;
          break;
        }
      }
      if (!is_inserted) {
        nums1.insert(nums1.end(), *nums2It);
        nums1It = nums1.end();
      }

      nums2.erase(nums2It);
    }

    for (int num1 : nums1)
      std::cout << num1 << " ";
    std::cout << std::endl;
    for (int num2 : nums2)
      std::cout << num2 << " ";
    std::cout << std::endl;
  }

  void test() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};

    merge(nums1, nums1.size(), nums2, nums2.size());
  }
};
