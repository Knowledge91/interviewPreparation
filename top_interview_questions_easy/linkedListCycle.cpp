#include <iostream>
#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}

  void print() {
    ListNode *node = this;
    std::cout << node->val;
    int i = 0;
    while (node->next != nullptr) {
      node = node->next;
      std::cout << " <- " << node->val;
      if (i > 10)
        return;
      i++;
    }
    std::cout << std::endl;
  }
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr)
      return false;

    std::unordered_set<ListNode *> set;
    while (head->next != nullptr) {
      if (set.find(head) != set.end())
        return true;
      set.insert(head);
      head = head->next;
    }
    return false;
  }

  void test() {
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(0);
    ListNode n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    std::cout << hasCycle(&n1) << std::endl;
  }
};
