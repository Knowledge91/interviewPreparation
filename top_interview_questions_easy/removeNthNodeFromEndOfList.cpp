#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int counter = 0;
    ListNode *curr = head;
    ListNode *second = head;
    while (counter != n) {
      second = second->next;
      counter++;
    }
    if (second == NULL)
      return head->next;
    while (second->next != NULL) {
      curr = curr->next;
      second = second->next;
    }
    curr->next = curr->next->next;
    return head;
  }

  void test() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    // node1.next = &node2;
    // node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node5;

    ListNode *node = removeNthFromEnd(&node1, 1);
    while (node->next) {
      std::cout << node->val << std::endl;
      node = node->next;
    };
    if (node)
      std::cout << node->val;
  }
};
