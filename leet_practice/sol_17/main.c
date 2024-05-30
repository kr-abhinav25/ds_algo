// https://leetcode.com/problems/product-of-array-except-self/description/

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
  int * result = (int*)malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;

  int preFix = 1;
  
  result[0] = 1;
  for (int i = 1; i < numsSize; i++) {
    result[i] = nums[i-1] * preFix;
    preFix = result[i];
  }

  preFix = 1;
  for (int i = numsSize-1; i >= 0; i--) {
    result[i] = result[i] * preFix;
    preFix = preFix * nums[i];
  }
  
  return result;
}

 int main() {
  int nums[] = {-1,1,0,-3,3};
  int numsSize = sizeof(nums)/sizeof(nums[0]);
  int* returnSize;
  int* result = productExceptSelf(nums, numsSize, returnSize);

  for (int i = 0; i < numsSize; i++) {
    printf("%d", result[i]);
  }

  return 0;
 }