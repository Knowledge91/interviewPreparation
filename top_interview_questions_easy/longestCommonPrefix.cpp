#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.size() == 0)
      return "";
    if (strs.size() == 1)
      return strs[0];

    std::string lcp = LCP(strs[0], strs[1]);
    for (int i = 2; i < strs.size(); i++) {
      if (lcp == "")
        return "";
      lcp = LCP(lcp, strs[i]);
    }
    return lcp;
  }
  std::string LCP(const std::string &s1, const std::string &s2) {
    for (int i = 0; i < s1.size(); i++) {
      if (i == s1.size() - 1 && s1[i] == s2[i])
        return s1;
      if (i == s2.size() || i == s1.size() || s1[i] != s2[i])
        return s1.substr(0, i);
    }
    return "";
  }

  void test() {
    std::vector<std::string> strs = {"aa", "ab"};
    std::cout << longestCommonPrefix(strs);
  }
};
