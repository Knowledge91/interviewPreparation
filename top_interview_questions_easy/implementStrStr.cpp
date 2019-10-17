#include "string"
#include <iostream>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    if (needle == "")
      return 0;
    if (needle.size() > haystack.size())
      return -1;

    for (int i = 0; i <= haystack.size() - needle.size(); i++) {
      int k = i;
      for (int j = 0; j < needle.size(); j++) {
        if (haystack[k] != needle[j])
          break;
        if (j == needle.size() - 1)
          return k - j;
        k++;
      }
    }
    return -1;
  }

  void test() { std::cout << strStr("", "a"); }
};
