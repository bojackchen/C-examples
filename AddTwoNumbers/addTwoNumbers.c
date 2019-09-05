/*
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* returnList = (struct ListNode*) malloc(sizeof(struct ListNode));
  // sliding pointer for operation
  struct ListNode* workList = returnList;
  int sum;
  int carry = 0;

  while (l1 != NULL || l2 != NULL) {
    // three cases: 1. l1 empty; 2. l2 empty; 3. both not empty;
    if (l1 == NULL) {
      sum = (l2->val + carry) % 10;
      carry = (l2->val + carry) / 10;
      l2 = l2->next;
    } else if (l2 == NULL) {
      sum = (l1->val + carry) % 10;
      carry = (l1->val + carry) / 10;
      l1 = l1->next;
    } else {
      sum = (l1->val + l2->val + carry) % 10;
      carry = (l1->val + l2->val + carry) / 10;
      l1 = l1->next;
      l2 = l2->next;
    }

    workList->val = sum;
    if (l1 != NULL || l2 != NULL) {
      // continue when either one is not empty
      workList->next = (struct ListNode*) malloc(sizeof(struct ListNode));
      workList = workList->next;
    } else if (carry == 1) {
      // construct MSB when carry == 1
      workList->next = (struct ListNode*) malloc(sizeof(struct ListNode));
      workList = workList->next;
      workList->val = carry;
      workList->next = NULL;
    } else {
      // terminate the list when both empty
      workList->next = NULL;
    }
  }

  return returnList;
}
