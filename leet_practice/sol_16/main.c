// https://leetcode.com/problems/find-the-duplicate-number/description/

#include<stdio.h>
#include<string.h>

int findDuplicate(int* nums, int numsSize) {
  int counter[numsSize];
  int result = 0;
  memset(counter, 0, numsSize * sizeof(nums[0]));
  for (int i = 0; i < numsSize; i++) {
    if (counter[nums[i]] == 1) {
    result = nums[i];
    break;
    }
    else {
      counter[nums[i]] = 1;
    }
  }
  return result;
}

 int main() {
  int nums[] = {1,3,4,2,2};
  int numsSize = sizeof(nums)/sizeof(nums[0]);
  int dup = findDuplicate(nums, numsSize);
  printf("%d\n", dup);
  return 0;
 }