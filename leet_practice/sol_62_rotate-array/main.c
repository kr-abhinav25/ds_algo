// https://leetcode.com/problems/rotate-array/

#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {

  if (k%numsSize == 0)
    return;

  int result[numsSize];
  for (int i = 0, j = numsSize -1; i <= j; i++, j--) {
    result[(i+k)%numsSize] = nums[i];
    result[(j+k)%numsSize] = nums[j];
  }
  for (int i = 0, j = numsSize -1; i <= j; i++, j--) {
    nums[i] = result[i];
    nums[j] = result[j];
  }
}

int main() {
  int k = 3;
  int numsSize = 7;
  int nums[] = {1,2,3,4,5,6,7};
  rotate(nums, numsSize, k);

  for (int i = 0; i < numsSize; i++) {
    printf("%d,", nums[i]);
  }
  
}