// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include "stacks.h"
#include <stdbool.h>

bool isStackEmpty(int* stack) {

}
int *createStack(int size) {
  return int stack[size];
}

void push(int* stack, int data) {
  
}

int maxProfit(int* prices, int pricesSize){
  int stack[] = createStack(pricesSize);
  push(stack, 10);
  push(stack, 20);
  int data = pop(stack); 

// int stack[pricesSize];
// int top = -1;

// for (int i = 0; i < pricesSize; i++)
// {
//   while( !isStackEmpty(stack) &&  prices[i] > top(stack)) {
//     pop(stack);
//   }
// }

}

int main() {
  int arr[] = {7,1,5,3,6,4};
  int result = search(arr, 6);
  printf("%d", result);
  return 0;
}