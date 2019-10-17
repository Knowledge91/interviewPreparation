#include <iostream>
#include <vector>

class Solution {
public:
  void reverseString(std::vector<char> &s) {
    int i = 0;
    while (i != s.size() - 1 - i and i != s.size() - i) {
      std::swap(s[i], s[s.size() - 1 - i]);
      i++;
    }
  }

  void test() {
    std::vector<char> s = {'a', 'b', 'c', 'd'};
    reverseString(s);
    for (char el : s) {
      std::cout << el << " ";
    }
  }
};
