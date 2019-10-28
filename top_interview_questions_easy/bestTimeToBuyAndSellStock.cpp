#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int j = 0;
    int min = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++) {
      if (min > prices[i]) {
        min = prices[i];
      } else if (maxProfit < prices[i] - min) {
        maxProfit = prices[i] - min;
      }
    }

    return maxProfit;
  }

  void test() {
    std::vector<int> prices = {2, 4, 1};
    std::cout << maxProfit(prices);
  }
};
