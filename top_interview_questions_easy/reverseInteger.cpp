#include <cmath>
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int y = 0;
    while (x != 0) {
      if (y > 0 && y > INT_MAX / 10) // overflow
        return 0;
      if (y < 0 && y < INT_MIN / 10)
        return 0;
      y *= 10;
      int add = x % 10;
      if (add > 0 && y > INT_MAX - add) // overflow
        return 0;
      if (add < 0 && y < INT_MIN - add) // underflow
        return 0;

      y += add;
      x /= 10;
    }
    return y;
  }
  void test() {
    std::cout << INT_MIN << std::endl;
    std::cout << reverse(-123) << std::endl;
  }
};
