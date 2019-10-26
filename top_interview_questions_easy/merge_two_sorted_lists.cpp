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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    ListNode *tmp, *side, *main, *head = (l1->val > l2->val ? l2 : l1);
    if (head == l1) {
      main = l1, side = l2;
    } else {
      main = l2, side = l1;
    }

    while (main->next != nullptr) {
      if (main->next->val <= side->val) {
        main = main->next;
      } else {
        tmp = main->next;
        main->next = side;
        side = tmp;
      }
    }
    main->next = side;
    return head;
  }

  void test() {
    ListNode l10(1);
    ListNode l11(2);
    ListNode l12(4);
    l10.next = &l11;
    l11.next = &l12;

    ListNode l20(1);
    ListNode l21(3);
    ListNode l22(4);
    l20.next = &l21;
    l21.next = &l22;

    ListNode *p = mergeTwoLists(&l10, &l20);
    p->print();
  }
};
