// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct ArrayStack
{
  int top;
  int capacity;
  int *array;
}stack;

stack* createStack(int length) {
  stack *S = malloc(sizeof(stack));
  if (!S)
    return NULL;
  
  S->capacity = length+2;
  S->top = -1;
  S->array = malloc((S->capacity ) * sizeof(int));
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
    return -2;
  }
  else {
    return S->array[S->top--];
  }
}

int longestValidParentheses(char* s) {
  size_t length = strlen(s);
  if (length < 2)
    return 0;

  int max = 0, i = 0, currentLength = 0;
  stack* S = createStack(length);
  push(S, -1);

  while (s[i]!= '\0') {
    if (s[i] == '(') {
      push(S, i);
    }
    else {
      if ( S->array[S->top] != -1 && s[S->array[S->top]] == '(') {
        pop(S);
       currentLength = i - S->array[S->top];
       if (currentLength > max )
        max = currentLength;        
      }
      else {
        push(S, i);
      }
    }
    ++i;
  }
  
  return max;
}

int main(int argc, char *argv[]) {
  char *s = "(()";
  printf("2: %d\n",longestValidParentheses(s));

  char *s2 = ")()())";
  printf("4: %d\n",longestValidParentheses(s2));

  char *s3 = "";
  printf("0: %d\n",longestValidParentheses(s3));

  char *s4 = "()(()";
  printf("2: %d\n",longestValidParentheses(s4));

  char *s5 = ")(";
  printf("0: %d\n",longestValidParentheses(s5));

  char *s6 = "()(())";
  printf("6: %d\n",longestValidParentheses(s6));
}