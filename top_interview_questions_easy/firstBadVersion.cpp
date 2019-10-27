#include <iostream>

class Solution {
  int badVersion = 4;

public:
  int firstBadVersion(uint n) { return helper(1, n); }
  int helper(uint start, uint end) {
    if (isBadVersion(start))
      return start;
    if (start == end)
      return start + 1;

    int mid = (start + end) / 2;

    if (isBadVersion(mid))
      return helper(start, mid - 1);
    else
      return helper(mid + 1, end);
  }

  bool isBadVersion(uint n) {
    if (n >= badVersion)
      return true;
    return false;
  }

  void test() { std::cout << firstBadVersion(5); }
};
