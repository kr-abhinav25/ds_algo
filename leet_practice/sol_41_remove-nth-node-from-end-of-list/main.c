// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <stdio.h>
#include <stdlib.h>  

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* initialize_node() {
   struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
   return node;
}

struct ListNode* create_head(int val) {
   struct ListNode* node = initialize_node();
   node->val = val;
   node->next = NULL;
   return node;
}

void add_element(struct ListNode* head, int val) {
   struct ListNode* tmp = head;
   while (tmp->next != NULL)
   {
      tmp = tmp->next;
   }
   
   struct ListNode* node = initialize_node();
   node->val = val;
   node->next = NULL;
   tmp->next = node;
}

void print_list(struct ListNode* head) {
   struct ListNode* tmp = head;
   while (tmp != NULL)
   {
      printf("%d\n", tmp->val);
      tmp = tmp->next;
   }   
}

int countAndRemove(struct ListNode* head, int n, int nodeCount) {
  if (head == NULL)
    return (nodeCount);

  ++nodeCount;
  int totalCount = countAndRemove(head->next, n, nodeCount);
  if (totalCount - nodeCount == n) {
    if (head->next != NULL) {
      head->next = head->next->next;
    }
    else {
      head->next = NULL;
    }
  }
  return totalCount;

}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  int count = countAndRemove(head, n, 0);
  if (count == n) {
    if (head->next != NULL) {
      head = head->next;
    }
    else {
      head = NULL;
    }    
  }
  return head;
}

int main()
{

struct ListNode* l1 = create_head(1);
  add_element(l1, 2);
  add_element(l1, 3);
  add_element(l1, 4);
  add_element(l1, 5);

  l1 = removeNthFromEnd(l1, 5);
  // l1 = removeNthFromEnd(l1, 2);
  print_list(l1);

 return 0;
}