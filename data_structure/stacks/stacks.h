#define MAXSIZE 10
#define INT_MIN 0
typedef struct ArrayStack
{
  int top;
  int capacity;
  int *array;
}stack;

stack* createStack();
void push(stack* S, int data);
int isEmptyStack(stack* S);
int isFullStack(stack* S);
int pop(stack* S);
void PrintStack(stack* S);
void DeleteStack(stack* S);