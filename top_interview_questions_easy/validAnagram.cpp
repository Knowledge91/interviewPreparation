#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> map1;
    std::unordered_map<char, int> map2;

    for (char c : s)
      map1[c]++;
    for (char c : t)
      map2[c]++;

    if (map1.size() != map2.size())
      return false;

    for (auto &[key, value] : map1) {
      if (value != map2[key])
        return false;
    }

    return true;
  }

  void test() { std::cout << isAnagram("ana", "nasa"); }
};
