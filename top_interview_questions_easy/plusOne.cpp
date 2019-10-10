#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    helper(digits, digits.end() - 1);
    return digits;
  }
  void helper(std::vector<int> &digits, const std::vector<int>::iterator &it) {
    if (it == digits.begin()) {
      if (*it == 9) {
        *it = 0;
        digits.insert(it, 1);
      } else
        (*it)++;
      return;
    }

    if (*it < 9)
      (*it)++;
    else {
      *it = 0;
      helper(digits, it - 1);
    }
  }

  std::vector<int> plusOneOverflow(std::vector<int> &digits) {
    std::vector<int> vec;

    unsigned long long integer = 0;
    for (int i = 1; i <= digits.size(); i++)
      integer += digits[i - 1] * std::pow(10, digits.size() - i);

    std::cout << integer << std::endl;

    integer++;
    while (integer != 0) {
      vec.insert(vec.begin(), integer % 10);
      integer /= 10;
    }

    return vec;
  }

  void test() {
    // std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> vec = {0};
    for (int el : plusOne(vec))
      std::cout << el << " ";
  }
};
