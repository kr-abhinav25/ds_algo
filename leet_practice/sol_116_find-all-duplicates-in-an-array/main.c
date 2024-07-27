// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* findDuplicates(int* nums, int numsSize, int* returnSize) {

  int *countArray = (int*)malloc(numsSize * sizeof(int));
  memset(countArray, 0, numsSize * sizeof(int));
  int returnArraySize = 0;

  for (int i = 0; i < numsSize; i++) {
    ++countArray[nums[i]-1];
    if (countArray[nums[i]-1] == 2) {
      returnArraySize++;
    }    
  }

  int *returnArray = (int*)malloc(returnArraySize * sizeof(int));

  int j = 0;
  for(int i = 0; i < numsSize; i++) {
    if (countArray[i] > 1) {
      returnArray[j] = i+1;
      j++;
    }
  }
  *returnSize = returnArraySize;
  return returnArray;  
}

int main() {

  int *result, returnSize;
  int nums[] = {4,3,2,7,8,2,3,1};
  
  result = findDuplicates(nums, 8, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d\n", result[i]);
  }
  
}