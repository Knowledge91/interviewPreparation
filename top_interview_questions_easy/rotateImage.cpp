#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    // transpose
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (i == j)
          break;
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }

    // mirrow
    for (int i = 0; i < matrix.size(); i++)
      std::reverse(matrix[i].begin(), matrix[i].end());
  }

  void test() {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        std::cout << matrix[i][j] << ", ";
      }
      std::cout << std::endl;
    }
  }
};
