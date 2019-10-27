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
  TreeNode *helper(const std::vector<int> &nums,
                   std::vector<int>::size_type start,
                   std::vector<int>::size_type end) {
    if (start >= end)
      return NULL;
    if (start == end - 1)
      return new TreeNode(nums[start]);

    std::vector<int>::size_type mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = helper(nums, start, mid);
    root->right = helper(nums, mid + 1, end);

    return root;
  }

  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return helper(nums, 0, nums.size());
  }
  void test() {
    std::vector<int> vec = {-3};
    std::vector<int> v = {
        vec.end() - vec.size() / 2,
        vec.end(),
    };

    for (int el : v) {
      std::cout << el << " ";
    }

    // sortedArrayToBST(vec);
  }
};
