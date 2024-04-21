/* linked_list.h */
#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
   int data;
   struct Node* next;
} Node;

// struct Node* head;

Node* initialize_node(void);
Node* create_list(int val);
Node* create_head(int val);
void add_element(Node* head, int val, int pos);
void insert_at_end(Node* head, int val);
void print_list(Node* head);

// Node* initialize_node(void);
// void create_head(Node* node, int val);
// void insert_at_end(Node* node, int val);
// void add_element(int val);
// Node* print_list(void);
// void reverseList(Node* node);
#endif