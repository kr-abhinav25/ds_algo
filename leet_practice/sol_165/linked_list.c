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

Node* middleNode(Node* head){
   Node* ptr1 = head;
   Node* ptr2 = head;
   do {
      if (ptr1->next != NULL) {
         ptr1 = ptr1->next;
      }
      if (ptr2->next != NULL) {
         ptr2 = ptr2->next;
         if (ptr2->next != NULL) {
            ptr2 = ptr2->next;
            
         }         
      }
      if (ptr1->next == NULL || ptr2->next == NULL) {
         break;
      }
   }
   while(1==1);
   return ptr1;
}