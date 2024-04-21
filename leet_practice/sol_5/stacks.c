#include "stacks.h"
#include "stdio.h"
#include <stdlib.h>  

stack* createStack() {
  stack *S = malloc(sizeof(stack));
  if (!S)
    return NULL;
  
  S->capacity = MAXSIZE;
  S->top = -1;
  S->array = malloc(S->capacity * sizeof(int));

  if (!S->array)
    return NULL;

  return S;
}

int isEmptyStack(stack* S) {
  return (S->top == -1);
}

int isFullStack(stack* S) {
  return (S->top == S->capacity -1);
}

void push(stack* S, int data) {
  if (isFullStack(S))
    printf("Stack Overflow");
  else
    S->array[++S->top] = data;
}

int pop(stack* S) {
  if (isEmptyStack(S)) {
    printf("Stack Underflow");
    return INT_MIN;
  }
  else {
    return S->array[S->top--];
  }
}

void PrintStack(stack* S) {
  if (S && S->array && S->top != -1) {
    for (int i = 0; i <= S->top; i++)
    {
      printf("%d\n",S->array[i]);
    }
  }
}

void DeleteStack(stack* S) {
  if (S)
    if (S->array)
      free(S->array);
    free(S);
}