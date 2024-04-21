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

// void add_element(int val) {
//    Node* node = initialize_node();
//    if (head == NULL) {
//       create_head(node, val);
//    }
//    else {
//       insert_at_end(node, val);
//    }
// }

// void reverseList(Node* node) {
//    Node* current = node;
//    Node* next = NULL;
//    Node* prev = NULL;
//    while (current != NULL)
//    {

//       next = current->next;
//       current->next = prev;
//       prev = current;
//       current = next;
//    }
//    head = prev;
// }
