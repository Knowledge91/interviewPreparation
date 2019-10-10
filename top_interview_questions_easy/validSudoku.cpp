#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
public:
  void print(std::vector<int> &vec) {
    for (int el : vec)
      std::cout << el << " ";
    std::cout << std::endl;
  }

  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    auto charToInt = [](const char &c) { return (int)c - '0'; };
    auto getRow = [&board, charToInt](const int &row) {
      std::vector<int> vec;
      for (int i = 0; i < board[row].size(); i++)
        if (board[row][i] != '.')
          vec.push_back(charToInt(board[row][i]));
      return vec;
    };
    auto getCol = [&board, charToInt](const int &col) {
      std::vector<int> vec;
      for (int i = 0; i < board.size(); i++)
        if (board[i][col] != '.')
          vec.push_back(charToInt(board[i][col]));
      return vec;
    };
    auto getSubBox = [&board, charToInt](const int &box_row,
                                         const int &box_col) {
      std::vector<int> vec;
      for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
          if (board[i][j] != '.')
            vec.push_back(charToInt(board[i][j]));
        }
      }
      return vec;
    };
    auto isNotValidVec = [this](std::vector<int> vec) {
      std::unordered_set<int> set;
      for (int el : vec) {
        if (set.find(el) != set.end()) {
          print(vec);
          return true;
        }
        set.insert(el);
      }
      return false;
    };

    int i = 9;
    // chk rows and cols
    while (i--) {
      if (isNotValidVec(getRow(i)) || isNotValidVec(getCol(i)))
        return false;
    }

    // chk sub boxes
    for (i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (isNotValidVec(getSubBox(i * 3, j * 3)))
          return false;
      }

    return true;
  }

  void test() {
    // std::vector<std::vector<char>> board{
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    // std::vector<std::vector<char>> board{
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    // std::vector<std::vector<char>> board{
    //     {'.', '.', '.', '9', '.', '.', '.', '.', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'.', '.', '3', '.', '.', '.', '.', '.', '1'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'1', '.', '.', '.', '.', '.', '3', '.', '.'},
    //     {'.', '.', '.', '.', '2', '.', '6', '.', '.'},
    //     {'.', '9', '.', '.', '.', '.', '.', '7', '.'},
    //     {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    //     {'8', '.', '.', '8', '.', '.', '.', '.', '.'}};
    std::vector<std::vector<char>> board{
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
        {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};

    std::cout << isValidSudoku(board);
  }
};
