#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int max = 0;
    int valley = prices[0];
    int peak = prices[0];
    int i = 0;
    while (i < prices.size() - 1) {
      // find next valley
      while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
        i++;
      valley = prices[i];

      // find next peak
      while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
        i++;
      peak = prices[i];

      max += peak - valley;
    }

    return max;
  }

  void test() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << maxProfit(prices) << std::endl;
  }
};
