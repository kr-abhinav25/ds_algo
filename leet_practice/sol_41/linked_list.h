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

Node* initialize_node(void);
Node* create_list(int);
Node* create_head(int);
void add_element(Node*, int, int);
void insert_at_end(Node*, int);
void print_list(Node*);
Node* removeNthFromEnd(Node*, int);
#endif