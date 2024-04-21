#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>  

Node* initialize_node() {
   Node* node = (Node*)malloc(sizeof(Node));
   return node;
}

Node* create_list(int val) {
   return create_head(val);
}

Node* create_head(int val) {
   Node* node = initialize_node();
   node->data = val;
   node->next = NULL;
   return node;
}

void add_element(Node* head, int val, int pos) {
   if (pos == -1)
   insert_at_end(head, val);
}
// void create_head(Node* node, int val) {
//    node->data = val;
//    node->next = NULL;
//    head = node;
// }

void insert_at_end(Node* head, int val) {
   Node* tmp = head;
   while (tmp->next != NULL)
   {
      tmp = tmp->next;
   }
   
   Node* node = initialize_node();
   node->data = val;
   node->next = NULL;
   tmp->next = node;
}

void print_list(Node* head) {
   Node* tmp = head;
   while (tmp != NULL)
   {
      printf("%d\n", tmp->data);
      tmp = tmp->next;
   }   
}

Node* removeNthFromEnd(Node* head, int pos) {
   Node* ptr1 = head;
   Node* ptr2 = head;
   Node* ptr3 = head;
   for (int i = 0; i < pos && ptr2->next != NULL; i++)
   {
      ptr2 = ptr2->next;
   }
   while (ptr2->next != NULL)
   {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
   }

   int mm = 1;
   Node* ptr4 = ptr3;
   while (ptr4->next != NULL)
   {
      ptr4 = ptr4->next;
      ++mm;
   }

   if (ptr1 == ptr2) {
      return NULL;
   }
   else if (mm == pos) {
      ptr3 = ptr1->next;
   }
   else if (ptr1->next == ptr2) {
      ptr1->next = NULL;
   }
   else {
      Node* tmp = ptr1->next;
      ptr1->next = ptr2;
      free(tmp);
   }
   return ptr3;
 }
