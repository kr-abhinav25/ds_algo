#include "stacks_linked.h"
#include "tree.h"
#include "stdio.h"

LNode* createStack() {
  LNode* top = NULL;
  return top;
}

int isEmptyStack(LNode* top) {
  return (top == NULL);
}

void push(LNode** top, struct BinaryTreeNode* data) {
  LNode* tmp = (LNode*)malloc(sizeof(LNode));
  tmp->data = data;
  tmp->next = *top;
  *top = tmp;
}

void pop(LNode** top) {
  if (isEmptyStack(*top)) {
    printf("Stack Underflow");
    return INT_MIN;
  }
  else {
    *top = *top->next;
    free(*top);
  }
}

void PrintStack(LNode* top) {
LNode* tmp = top;
  // if (tmp) {
  //   while(tmp != NULL) {
  //     printf("%d\n", tmp->data);
  //     tmp = tmp->next;
  //   }
  // }
}

void DeleteStack(LNode** top) {
  LNode* p;
  LNode* tmp;
  p = *top;

  while (p->next)
    {
      tmp = p->next;
      p = p->next;
      free(tmp);

    }

}