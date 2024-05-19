// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
  int i = 0, j = numbersSize-1, sum = 0;
  int *returnArray = (int*)malloc(2 * sizeof(int));
  *returnSize = 2;

  // We maintain 2 pointers, one at the beginning, one at the end.
  // Every time we sum i+j
  // If sum is < target, we increment i, coz j being at its max still can't sum upto the target.
  // If sum is > target, we decrement j coz i being at its lowest still the sum exceeds the target.
  // This logic works coz the array is sorted in increasing order.
  while (i < j)  {
    sum = numbers[i] + numbers[j];
    if (sum > target) {
      j--;
    }
    else if (sum < target) {
      i++;
    }
    else if (sum == target) {
      // +1 coz Leetcode is in a parallel universe with 1th based index.
      returnArray[0] = i+1; 
      returnArray[1] = j+1;
      break;
    }
  }
  
  return returnArray;
}


int main() {
  int numbers[] = {5,25,75};
  int numbersSize = sizeof(numbers)/sizeof(numbers[0]);
  int target = 100;
  int* returnSize;
  int* result = twoSum(numbers, numbersSize, target, returnSize);
  printf("[%d,%d]", result[0], result[1]);
  
}