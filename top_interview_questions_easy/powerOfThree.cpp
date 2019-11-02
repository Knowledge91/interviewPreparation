#include <cmath>
#include <iostream>

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n == 0)
      return false;
    double intpart;
    return std::modf(std::log10(n) / std::log10(3), &intpart) == 0.0;
  }
  void test() { std::cout << isPowerOfThree(243); }
};
