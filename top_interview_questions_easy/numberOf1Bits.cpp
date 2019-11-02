#include <bitset>
#include <iostream>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int bits = 0;
    uint32_t mask = 1;
    for (int i = 0; i < 32; i++) {
      if ((mask & n) != 0) {
        bits++;
      }
      mask <<= 1;
    }
    return bits;
  }
  void test() {
    std::bitset<32> x(11);
    std::cout << x << std::endl;
    std::cout << hammingWeight(11);
  }
};
