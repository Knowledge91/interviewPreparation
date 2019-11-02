#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> r;
    if (numRows == 0)
      return r;

    r.push_back(std::vector<int>{1});
    for (int i = 0; i < numRows - 1; i++) {
      r.push_back(newRow(r[i]));
    }
    return r;
  }
  std::vector<int> newRow(const std::vector<int> &vec) {
    std::vector<int> v;
    v.push_back(1);
    for (int i = 1; i < vec.size(); i++) {
      v.push_back(vec[i - 1] + vec[i]);
    }
    v.push_back(1);
    return v;
  }
  void test() {
    for (std::vector<int> v : generate(5)) {
      for (int i : v) {
        std::cout << i << ",";
      }
      std::cout << std::endl;
    }
  }
};
