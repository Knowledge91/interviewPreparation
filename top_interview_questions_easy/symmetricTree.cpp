#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) { return isMirror(root, root); }
  bool isMirror(TreeNode *l, TreeNode *r) {
    if (l == nullptr && r == nullptr)
      return true;
    if (l == nullptr || r == nullptr)
      return false;
    return l->val == r->val && isMirror(l->right, r->left) &&
           isMirror(l->left, r->right);
  }

  void test() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    TreeNode n4(3);
    TreeNode n5(4);
    TreeNode n6(4);
    TreeNode n7(3);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    std::cout << isSymmetric(&n1);
  }
};
