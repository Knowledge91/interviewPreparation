#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;

    ListNode *last = nullptr;
    while (head->next != nullptr) {
      ListNode *node = head->next;
      ListNode *prev = head;

      while (node->next != nullptr) {
        node = node->next;
        prev = prev->next;
      }
      if (last == nullptr)
        last = node;
      node->next = prev;
      prev->next = nullptr;
    }

    return last;
  }

  void test() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;

    ListNode *node = reverseList(&node1);

    while (node->next != nullptr) {
      std::cout << node->val << std::endl;
      node = node->next;
    }
    std::cout << node->val << node->next << std::endl;
  }
};
