#include <iostream>
#include <vector>

class Solution {
public:
  int countPrimes(int n) {
    std::vector<bool> isPrime(n);
    std::fill(isPrime.begin(), isPrime.end(), true);

    for (int i = 2; i * i < n; i++) {
      if (!isPrime[i])
        continue;
      for (int j = i; i * j < n; j++) {
        isPrime[i * j] = false;
      }
    }

    int count = 0;
    for (int i = 2; i < n; i++) // 0 and 1 are not primes
      if (isPrime[i])
        count++;

    return count;
  }
  void test() { std::cout << countPrimes(10); }
};
