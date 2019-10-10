#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> result;
    std::unordered_map<int, int> map1;
    std::unordered_map<int, int> map2;
    for (int num : nums1)
      map1[num]++;
    for (int num : nums2)
      map2[num]++;

    auto min = [](int &x, int &y) {
      if (x > y)
        return y;
      return x;
    };

    for (std::pair<const int, int> pair : map1) {
      if (map2[pair.first])
        for (int i = 0; i < min(pair.second, map2[pair.first]); i++)
          result.push_back(pair.first);
    }

    return result;
  }

  void test() {
    std::vector<int> vec = {1, 2, 2, 1};
    std::vector<int> vec2 = {2, 2};

    for (int el : intersect(vec, vec2))
      std::cout << el << " ";
  }
};
