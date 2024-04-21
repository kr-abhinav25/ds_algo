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

Node* removeElements(Node* head, int val){
   Node* ptr = head;
   Node* ptr2 = head;
   while (ptr != NULL)
   {
      // if (ptr->data == val) {
      //    ptr = ptr->next;
      // }
      if (ptr->next != NULL && ptr->next->data == val) {
         if (ptr->next->next != NULL) {
            ptr->next = ptr->next->next; 
         }
         else {
            ptr->next = NULL;
         }
      }
      else {
         ptr = ptr->next;
      }
   }

   // check for 1st node
   if (ptr2 != NULL && ptr2->data == val) {
      if (ptr2->next != NULL) {
         ptr2 = ptr2->next;
      }
      else {
         ptr2 = NULL;
      }
   }

   
   return ptr2;
}