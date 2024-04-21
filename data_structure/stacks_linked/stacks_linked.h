#ifndef STACKS_LINKED
#define STACKS_LINKED
#define MAXSIZE 10
#define INT_MIN 0
#include <stdlib.h>  

typedef struct ListNode
{
  int data;
  struct ListNode* next;
}Node;
int isEmptyStack(Node*);
void push(Node**, int);
int pop(Node**);
void PrintStack(Node*);
void DeleteStack(Node**);
#endif