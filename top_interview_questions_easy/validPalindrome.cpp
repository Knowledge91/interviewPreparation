#include <cctype>
#include <iostream>
#include <string>

class Solution {
  enum Direction { dec, inc };

public:
  bool isPalindrome(std::string s) {
    int i = -1;
    int j = s.size();

    auto nextCharPos = [&s](int &pos, Direction dir) {
      switch (dir) {
      case dec: {
        do {
          pos--;
        } while (pos >= 0 && !std::isalnum(s[pos]));
        break;
      }
      case inc: {
        do {
          pos++;
        } while (pos < s.size() && !std::isalnum(s[pos]));
        break;
      }
      }
    };

    while (i <= j) {
      nextCharPos(i, inc);
      nextCharPos(j, dec);
      if (std::tolower(s[i]) != std::tolower(s[j]) && std::isalnum(s[i]) &&
          std::isalnum(s[j]))
        return false;
    }
    return true;
  }

  void test() {
    std::cout << isPalindrome(
        "......................................................................"
        "..........................................a..........................."
        "......................................................................"
        "......................................................................"
        "......................................................................"
        "...");
  }
};
