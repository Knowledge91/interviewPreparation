#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return helper(root, -std::numeric_limits<double>::max(),
                  std::numeric_limits<double>::max());
  }
  bool helper(TreeNode *root, double lower, double upper) {
    if (root == nullptr)
      return true;

    int val = root->val;
    if (val <= lower)
      return false;
    if (val >= upper)
      return false;

    if (!helper(root->left, lower, val))
      return false;
    if (!helper(root->right, val, upper))
      return false;

    return true;
  }

  void test() {
    // TreeNode t1(5);
    // TreeNode t2(1);
    // TreeNode t3(6);
    // TreeNode t4(3);
    // TreeNode t5(7);
    // t1.left = &t2;
    // t1.right = &t3;
    // t3.left = &t4;
    // t3.right = &t5;

    TreeNode t1(2);
    TreeNode t2(1);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;

    std::cout << isValidBST(&t1);
    std::cout << std::endl << std::numeric_limits<double>::min();
  }
};
