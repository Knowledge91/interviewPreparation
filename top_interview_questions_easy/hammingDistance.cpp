#include <bitset>
#include <iostream>

class Solution {
public:
  int hammingDistance(int x, int y) {
    int dist = 0, n = x ^ y;
    while (n) {
      ++dist;
      n &= n - 1;
    }
    return dist;
  }
  void test() { std::cout << hammingDistance(1, 4); }
};
