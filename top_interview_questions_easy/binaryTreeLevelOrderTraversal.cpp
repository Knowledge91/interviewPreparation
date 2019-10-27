#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> vec;
    if (root == nullptr)
      return vec;

    helper(root, 0, vec);

    return vec;
  }

  void helper(TreeNode *root, int level, std::vector<std::vector<int>> &vec) {
    if (vec.size() < level + 1)
      vec.resize(level + 1);

    vec[level].push_back(root->val);
    if (root->left != nullptr)
      helper(root->left, level + 1, vec);
    if (root->right != nullptr)
      helper(root->right, level + 1, vec);
  }

  void test() {

    TreeNode tn1(3);
    TreeNode tn2(9);
    TreeNode tn3(20);
    TreeNode tn4(15);
    TreeNode tn5(7);

    tn1.left = &tn2;
    tn1.right = &tn3;
    tn3.left = &tn4;
    tn3.right = &tn5;

    std::vector<std::vector<int>> vec = levelOrder(&tn1);
    for (std::vector<int> level : vec) {
      for (int el : level) {
        std::cout << el << ", ";
      }
      std::cout << std::endl;
    }
  }
};
