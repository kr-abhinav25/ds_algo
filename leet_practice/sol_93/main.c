// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
 };

// Linked List functions: 
struct ListNode* newNode(){
  struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
  return node;
}

void printList(struct ListNode* head) {
  struct ListNode* tmp = head;
  
  if (tmp == NULL) {
    printf("No item in List");
    return;
  }
  while(tmp != NULL) {
    printf("%d\n", tmp->val);
    tmp = tmp->next;
  }
}

void insert(struct ListNode* head, int element) {
  struct ListNode* tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  
  struct ListNode* node = newNode();
  node->val = element;
  node->next = NULL;
  tmp->next = node;
}

struct ListNode* createHead(int element) {
  struct ListNode* node = newNode();
  node->val = element;
  node->next = NULL;
  return node;
}

struct ListNode* reverseList(struct ListNode *head) {
    if(!head || !(head->next)) return head;
    struct ListNode *res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}

struct ListNode* reverseGroup(struct ListNode* head, int k) {
  if (head == NULL) {
    return head;
  }
  int i = 0;
  struct ListNode* tmp = head;

  while (i < k && tmp->next != NULL ) {
    tmp = tmp->next;
    ++i;
  }
  struct ListNode* lastNode = reverseGroup(tmp->next, k);
  if (i == k) {
    tmp->next = NULL;
    struct ListNode* reversedHead = reverseList(head);
    head->next = lastNode;
    return reversedHead;
  }
  else {
    return head;
  }
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
  struct ListNode* tmp = reverseGroup(head, k-1);
  return tmp;
}

int main() {

  struct ListNode *head = createHead(1);
  insert(head, 2);
  insert(head, 3);
  insert(head, 4);
  insert(head, 5);
  insert(head, 6);
  insert(head, 7);
  insert(head, 8);


  struct ListNode *head1 = reverseKGroup(head, 5);
  printList(head1);

 return 0;
}