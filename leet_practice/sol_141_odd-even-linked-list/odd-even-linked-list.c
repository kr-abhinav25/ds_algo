// https://leetcode.com/problems/odd-even-linked-list/

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

struct ListNode* oddEvenList(struct ListNode* head) {
  if (head == NULL)
    return NULL;

  struct ListNode* tmp = head;
  int length = 0;
  while (tmp != NULL) {
    ++length;
    tmp = tmp->next;
  }

  if (length == 1)
    return head;

  struct ListNode** arrEven = (struct ListNode**)malloc(sizeof(struct ListNode*) * (int)(length/2));
  struct ListNode** arrOdd = (struct ListNode**)malloc(sizeof(struct ListNode*) * (length - length/2));

  tmp = head;
  int i = 0, j = 0;
  while (tmp != NULL) {
    arrOdd[i] = tmp;
    tmp = tmp->next;
    ++i;
    if (tmp != NULL) {
      arrEven[j] = tmp;
      ++j;
      tmp = tmp->next;
    }
  }

  tmp = head;
  for ( i = 1; i < (length - length/2); i++) {
    tmp->next = arrOdd[i];
    tmp = tmp->next;
  }
  for ( i = 0; i < length/2; i++) {
    tmp->next = arrEven[i];
    tmp = tmp->next;
  }
  tmp->next = NULL;
  return head;
}

int main()
{

struct ListNode* l1 = create_head(1);
  add_element(l1, 2);
  add_element(l1, 3);
  add_element(l1, 4);
  // add_element(l1, 5);

  l1 = oddEvenList(l1);
  print_list(l1);

 return 0;
}