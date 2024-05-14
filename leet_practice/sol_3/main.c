// https://leetcode.com/problems/maximum-subarray/description/
#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
  int currentSum = nums[0];
  int maxSum = currentSum;
  if (numsSize == 1) {
    return currentSum;
  }

  for (int i = 1; i < numsSize; i++) {
    currentSum = currentSum + nums[i];
    if (nums[i] > currentSum) {
      currentSum = nums[i];
      if (currentSum > maxSum) {
        maxSum = currentSum;
      }      
    }
    if (currentSum > maxSum) {
      maxSum = currentSum;
    }
  }

  return maxSum;
  
}

int main(){

  int nums[] = {5,4,-1,7,8};
  int numSize = sizeof(nums)/sizeof(nums[0]);
  int result = maxSubArray(nums, numSize);
  printf("%d\n", result);
}