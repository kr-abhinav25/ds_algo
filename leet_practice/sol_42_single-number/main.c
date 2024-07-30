// https://leetcode.com/problems/single-number/description/

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
  int xorAll = 0, result = 0;
  
  for (int i = 0; i < numsSize; i++) {
    // Xor all array elements, the duplicate nos. will
    // cancel out to 0,only single no. will remain.
    result = result ^ nums[i];

  }

  return result;
}

int main() {
  int nums[3] = {2,2,1};
  printf("%d", singleNumber(nums, 3));
}