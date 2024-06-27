// https://leetcode.com/problems/first-missing-positive/description/

#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int *nums, int numsSize) {
  int psuedo = (numsSize + 1) * -1;
  int indexToChange = -1;
  
  for (int i = 0, j = numsSize - 1; i <= j; i++, j--) {
    if (nums[i] < 0 || nums[i] > numsSize)
      nums[i] = 0;
    if (nums[j] < 0 || nums[j] > numsSize)
      nums[j] = 0;      
  }

  for (int i = 0, j = numsSize - 1; i <= j; i++, j--) {
    if (nums[i] != 0) {
      indexToChange = abs(nums[i])-1;
      if (indexToChange < numsSize)
        nums[indexToChange] = nums[indexToChange] == 0 ? psuedo : abs(nums[indexToChange]) * -1;
    }
    if (nums[j] != 0) {
      indexToChange = abs(nums[j])-1;
      if (indexToChange < numsSize)
        nums[indexToChange] = nums[indexToChange] == 0 ? psuedo : abs(nums[indexToChange]) * -1;      
    }
  }  

  if (indexToChange == -1)
    return 1;

  indexToChange = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] >= 0) {
      indexToChange = i + 1;
      break;
    }
  }
  
  if (indexToChange == 0)
    indexToChange = numsSize+1;
  return indexToChange;
}

int main() {
  int result = 0;

  int nums[] = {1};
  result = firstMissingPositive(nums, 1);
  printf("%d\n", result);

  int nums1[] = {1,2,0};
  result = firstMissingPositive(nums1, 3);
  printf("%d\n", result);  

  int nums2[] = {3,4,0,2};
  result = firstMissingPositive(nums2, 4);
  printf("%d", result);  
}