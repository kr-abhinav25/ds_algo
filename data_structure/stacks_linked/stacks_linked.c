#include "stacks_linked.h"
#include "stdio.h"

int isEmptyStack(Node* top) {
  return (top == NULL);
}

void push(Node** top, int data) {
  Node* tmp = (Node*)malloc(sizeof(Node));
  tmp->data = data;
  tmp->next = *top;
  *top = tmp;
}

int pop(Node** top) {
  if (isEmptyStack(*top)) {
    printf("Stack Underflow");
    return INT_MIN;
  }
  else {
    Node* tmp = *top;
    int data = tmp->data;
    *top = tmp->next;
    free(tmp);
    return data;
  }
}

void PrintStack(Node* top) {
Node* tmp = top;
  if (tmp) {
    while(tmp != NULL) {
      printf("%d\n", tmp->data);
      tmp = tmp->next;
    }
  }
}

void DeleteStack(Node** top) {
  Node* p;
  Node* tmp;
  p = *top;

  while (p->next)
    {
      tmp = p->next;
      p = p->next;
      free(tmp);

    }

}