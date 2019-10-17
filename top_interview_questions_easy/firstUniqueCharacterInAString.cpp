#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int firstUniqChar(std::string s) {
    std::unordered_map<char, int> map;
    for (char c : s) {
      map[c]++;
    }

    // check if non repetitive char exists
    bool exist = false;
    for (auto &[key, value] : map) {
      if (value == 1)
        exist = true;
    }
    if (!exist)
      return -1;

    std::string::iterator it = s.begin();
    while (true) {
      if (map[*it] == 1)
        return std::distance(s.begin(), it);
      std::advance(it, 1);
    }
  }

  void test() { std::cout << firstUniqChar("cc"); }
};
