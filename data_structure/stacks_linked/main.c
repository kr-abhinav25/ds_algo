#include "stacks_linked.h"
#include "stdio.h"
#include <stdlib.h>  

int main()
{
  Node* top = NULL;
  push(&top, 40);
  push(&top, 30);
  PrintStack(top);
  int val = pop(&top);
  // printf("%d\n", val);
  push(&top, 50);
  push(&top, 60);
  PrintStack(top);
  // DeleteStack(&top);
  // push(&top, 40);
  // PrintStack(top);
  return 0;
}
