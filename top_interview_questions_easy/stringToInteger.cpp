#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  enum Sign { null, none, pos, neg };

  int myAtoi(std::string str) {
    int res = 0;
    Sign sign = null;

    for (int i = 0; i <= str.size(); i++) {
      // skip white spaces
      if (str[i] == ' ')
        continue;

      // check for sign
      if (sign == null) {

        if (str[i] == '+') {
          if (!std::isdigit(str[i + 1]))
            return 0;
          sign = pos;
          continue;
        } else if (str[i] == '-') {
          if (!std::isdigit(str[i + 1]))
            return 0;
          sign = neg;
          continue;
        } else {
          sign = none;
        }
      }

      // get number substr
      int numStart = i;
      while (std::isdigit(str[i]) && i < str.size()) {
        i++;
      }
      std::string num = str.substr(numStart, i - numStart);
      std::cout << num << std::endl;

      for (int dec = num.size() - 1; dec >= 0; dec--) {
        int digit = num[num.size() - 1 - dec] - '0';
        if (digit == 0)
          continue;

        if (dec > 9 || res > INT_MAX - digit * std::pow(10, dec)) { // overflow
          if (sign == neg)
            return INT_MIN;
          else
            return INT_MAX;
        }
        res += digit * std::pow(10, dec);
      }

      if (sign == neg)
        return -res;
      else
        return res;
    }

    return res;
  }

  void test() { std::cout << myAtoi("3.14159"); }
};
