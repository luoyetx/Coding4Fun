#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  if (l1 == NULL && l2 == NULL) return NULL;
  struct ListNode* l3 = malloc(sizeof(struct ListNode));
  struct ListNode* p = l3;
  p->next = NULL;

  while (l1 != NULL || l2 != NULL) {
    p->next = malloc(sizeof(struct ListNode));
    p = p->next;
    p->next = NULL;
    if (l1 == NULL) {
      p->val = l2->val;
      l2 = l2->next;
    }
    else if (l2 == NULL) {
      p->val = l1->val;
      l1 = l1->next;
    }
    else {
      if (l1->val < l2->val) {
        p->val = l1->val;
        l1 = l1->next;
      }
      else {
        p->val = l2->val;
        l2 = l2->next;
      }
    }
  }

  return l3->next; // memory leak
}

int main(int argc, char *argv[]) {
  struct ListNode *l1 = malloc(sizeof(struct ListNode));
  l1->val = 1;
  l1->next = malloc(sizeof(struct ListNode));
  l1->next->val = 2;
  l1->next->next = NULL;
  struct ListNode *l2 = malloc(sizeof(struct ListNode));
  l2->val = 3;
  l2->next = malloc(sizeof(struct ListNode));
  l2->next->val = 4;
  l2->next->next = NULL;
  mergeTwoLists(l1, l2);
  return 0;
}
