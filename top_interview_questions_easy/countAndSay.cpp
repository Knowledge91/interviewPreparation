#include <iostream>
#include <string>

class Solution {
public:
  std::string countAndSay(int n) {
    std::string say = "1";
    for (int i = 0; i < n - 1; i++) {
      std::string xSay = "";
      for (int j = 0; j < say.size(); j++) {

        // count
        int start = j;
        while (j < say.size() && say[j] == say[j + 1]) {
          j++;
        }
        int count = j - start + 1;

        // say
        xSay += std::to_string(count) + say[j];
      }
      say = xSay;
    }
    return say;
  }

  void test() { std::cout << countAndSay(1); }
};
