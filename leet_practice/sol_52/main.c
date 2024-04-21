// https://leetcode.com/problems/move-zeroes/description/
#include "stdio.h"

void moveZeroes(int* nums, int numsSize){
  int i = 0;

  // get index of first zero
  while (nums[i] != 0)
  {
    i++;
    if (i == numsSize)
      break;
  }

  int j = i + 1;
  while (j < numsSize)
  {
    if (nums[j] > 0) {
      int temp = nums[j];
      nums[j] = nums[i];
      nums[i] = temp;

      while (nums[i] != 0)
      {
        i++;
        if (i == numsSize)
          break;        
      }

      j++;
      while (nums[j] < 1)
      {
        j++;
        if (j == numsSize)
          break;        
      }
    }
    else {
      j++;
    }
  } 
}

int main()
{
   int nums[] = {0, 2, 0, 0, 0, 1};
   moveZeroes(nums, 6);
  // for (int i = 0; i < 5; i++)
  // {
  //   printf("%d\n", nums[i]);
  // }
  
 return 0;
}