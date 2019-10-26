#include "./top_interview_questions_easy/merge_two_sorted_lists.cpp"
#include <iostream>
#include <vector>

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

void print(std::vector<int> v) {
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    if (std::prev(v.end(), 1) == it) {
      std::cout << *it << std::endl;
    } else {
      std::cout << *it << ", ";
    }
  }
}

// void print(ListNode *node) {
//   while (node->next != NULL) {
//     ListNode *nextNode = node->next;
//     std::cout << node->val << ", ";
//     node = nextNode;
//   };
//   std::cout << node->val;
// }

// // Problem: Maximum Depth Binary Tree
// void depthTreeHelper(TreeNode *node, int depth, int &maxDepth) {
//   if (maxDepth < depth)
//     maxDepth = depth;
//   if (node->left != NULL)
//     depthTreeHelper(node->left, depth + 1, maxDepth);
//   if (node->right != NULL)
//     depthTreeHelper(node->right, depth + 1, maxDepth);
// };
// // Problem: Climb Stairs
// int climbStairsHelper(int n, std::vector<int> &mem) {
//   if (mem[n] != 0)
//     return mem[n];

//   mem[n] = 0;
//   if (n - 1 >= 0)
//     mem[n] += climbStairsHelper(n - 1, mem);
//   if (n - 2 >= 0)
//     mem[n] += climbStairsHelper(n - 2, mem);

//   return mem[n];
// }

// class Solution {
// public:
//   int removeDuplicates(std::vector<int> &nums) {
//     nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
//     return nums.size();
//   }

//   void deleteNode(ListNode *node) {
//     while (node->next != NULL) {
//       node->val = node->next->val;
//       if (node->next->next == NULL) {
//         node->next = NULL;
//         return;
//       }
//       node = node->next;
//     }
//   }

//   // Problem: Maximum Depth Binary Tree
//   int maxDepth(TreeNode *root) {
//     if (root == NULL)
//       return 0;

//     int maxDepth = 1;
//     depthTreeHelper(root, maxDepth, maxDepth);

//     return maxDepth;
//   }

//   // Problem: Climbing Stairs
//   int climbStairs(int n) {
//     std::vector<int> mem(n + 3);
//     mem[0] = 0;
//     mem[1] = 1;
//     mem[2] = 2;
//     return climbStairsHelper(n, mem);
//   }
// };

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5};

  Solution sol = Solution();
  sol.test();
  // print(sol.shuffle());

  // Problem: Remove Duplicates from Array
  // std::vector<int> test = {1, 1, 2};
  // sol.removeDuplicates(test);
  // print(test);

  // Problem: Delete Node in a Linked List
  // ListNode node4(9);
  // ListNode node3(1);
  // ListNode node2(5);
  // ListNode node1(4);
  // node3.next = &node4;
  // node2.next = &node3;
  // node1.next = &node2;
  // sol.deleteNode(&node2);
  // print(&node1);

  // Problem: Maximum Depth of Binary Tree
  // TreeNode treeNode1(3);
  // TreeNode treeNode2(9);
  // TreeNode treeNode3(20);
  // TreeNode treeNode4(15);
  // TreeNode treeNode5(7);
  // treeNode1.left = &treeNode2;
  // treeNode1.right = &treeNode3;
  // treeNode3.left = &treeNode4;
  // treeNode3.right = &treeNode5;
  // std::cout << sol.maxDepth(&treeNode1) << std::endl;

  // Problem: Climbing Stairs
  // std::cout << sol.climbStairs(5) << std::endl;

  return 0;
};
