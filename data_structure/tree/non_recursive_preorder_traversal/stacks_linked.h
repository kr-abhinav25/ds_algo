#ifndef STACKS_LINKED
#define STACKS_LINKED
#define MAXSIZE 10
#define INT_MIN 0
#include <stdlib.h>  

typedef struct ListNode
{
  struct BinaryTreeNode* data;
  struct ListNode* next;
}LNode;

LNode* createStack();
int isEmptyStack(LNode*);
void push(LNode**, struct BinaryTreeNode*);
void pop(LNode**);
void PrintStack(LNode*);
void DeleteStack(LNode**);
#endif