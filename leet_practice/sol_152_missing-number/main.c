// https://leetcode.com/problems/missing-number/description/
#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
  int xorAll = 0, result = 0;
  
  for (int i = 0; i < numsSize; i++) {
    // Xor all array elements
    result = result ^ nums[i];

  // Xor all numbers from 0...n
    xorAll = xorAll ^ i; 
  }

  // Loop will run till i = numSize - 1
  // So need to XOR with numsSize to complete XOR from 0..n
  xorAll = xorAll ^ numsSize;

  return result ^ xorAll;
}

int main() {
  int nums[3] = {3, 0, 1};
  printf("%d", missingNumber(nums, 3));
}