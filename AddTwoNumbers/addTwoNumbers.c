/*
 * struct ListNode {
 *   int val;
 *   struct ListNode* next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* returnList;
  struct ListNode* workList = returnList;
  int sum;
  int carry = 0;

  while (l1 != NULL || l2 != NULL) {
    sum = (l1->val + l2->val + carry) % 10;
    carry = (l1->val + l2->val + carry) / 10;

    workList->val = sum;
    workList->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    workList = workList->next;

    l1 = l1->next;
    l2 = l2->next;
  }

  if (carry == 1) {
    workList->val = carry;
    workList->next = NULL;
  } else {
    workList->next = NULL;
  }

  return returnList;
}
