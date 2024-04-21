// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include "stdio.h"
#include <stdlib.h>  

void countSmaller(int* nums, int numsSize, int* returnSize){
  int *result = malloc(numsSize * sizeof(int));
  result[numsSize -1] = 0;
  int second_last_index = numsSize - 2;
  for (int i = second_last_index; i >= 0; i--)
  {
    // if (*(nums + i) > *(nums + (i + 1))) {
    //   result[i] = (*(result + (i + 1))) + 1;
    // }
    // else if(*(nums + i) == *(nums + (i + 1))) {
    //   result[i] = *(result + (i + 1));
    // }
    // else {
      int count = 0;
      int num_to_check = *(nums + i);
      for (int j = i + 1; j < numsSize; j++)
      {
       if (*(nums + j) > num_to_check) {
        count++;
       }
      }
      result[i] = count;
    // }
  }

  for (int i = 0; i < numsSize; i++)
  {
    printf("%d\n", *(result + i));
  }
  
  
}

int main()
{
  int a[5] = {9, 5, 7, 3, 5};
  int *nums = &a;
  countSmaller(nums, 5, nums);
  return 0;
}