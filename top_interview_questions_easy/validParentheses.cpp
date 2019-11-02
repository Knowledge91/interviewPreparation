#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{')
        stack.push(c);
      else if (stack.size() > 0 && ((stack.top() == '(' && c == ')') ||
                                    (stack.top() == '[' && c == ']') ||
                                    (stack.top() == '{' && c == '}')))
        stack.pop();
      else
        return false;
    }
    if (stack.size() == 0)
      return true;
    return false;
  }
  void test() { std::cout << isValid("{{}[][[([)]]}"); }
};
