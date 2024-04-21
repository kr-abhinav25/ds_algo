#include "stacks.h"

int main()
{

stack* S = createStack();
push(S,10);
push(S,20);
push(S,220);
push(S,40);
PrintStack(S);
DeleteStack(S);
 return 0;
}
