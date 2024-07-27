// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include "stdio.h"


int binarySearch(int* nums, int start, int end, int target) {
  if (start > end)
    return -1;

  int mid = start + (end - start)/2;
  if (nums[mid] == target) {
    return mid;
  }
  // left part of array is sorted
  else if (nums[start] <= nums[mid]) {
    if (target >= nums[start] && target < nums[mid])
      return binarySearch(nums, start, mid -1, target);
    else
      return binarySearch(nums, mid+1, end, target);
  }
  else {
    if (target > nums[mid] && target <= nums[end])
      return binarySearch(nums, mid+1, end, target);
    else
      return binarySearch(nums, start, mid-1, target);
  }
}

int search(int* nums, int numsSize, int target) {
  return binarySearch(nums, 0, numsSize - 1, target);
}


int main()
{
  //  int arr[] = {4,5,6,7,8,1,2,3};
  // int result = search(arr, 8, 8);
  // printf("%d", result);

  // int arr1[] = {4,5,6,7,0,1,2};
  // printf("4: %d\n", search(arr1, 7, 0));

  int arr2[] = {3, 1};
  printf("1: %d\n", search(arr2, 2, 1));  
 return 0;
}