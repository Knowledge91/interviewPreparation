#include <iostream>

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
  bool isPalindrome(ListNode *head) {
    if (head == nullptr)
      return true;

    ListNode *node = head;

    int L = 0;
    while (node != nullptr) {
      L++;
      node = node->next;
    }

    int i = 1;
    while (i <= L - i) {
      int v1 = head->val;
      node = head;
      for (int j = 1; j <= L - 2 * i + 1; j++) {
        node = node->next;
      }
      int v2 = node->val;
      std::cout << v1 << " " << v2 << std::endl;
      if (v1 != v2)
        return false;

      head = head->next;
      i++;
    }

    return true;
  };

  void test() {
    ListNode n1(1);
    ListNode n2(3);
    ListNode n3(2);
    ListNode n5(3);
    ListNode n6(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n5;
    n5.next = &n6;

    std::cout << isPalindrome(&n1);
  }
};
