// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include "stdio.h"

int search(int* nums, int numsSize, int target){

  if (numsSize == 1) {
   return (nums[0] == target) ?  0 : -1;
  }

  if (numsSize == 2) {
    if (nums[0] == target) {
      return 0;
    }
    else if (nums[1] == target){
      return 1;
    }
    else {
      return -1;
    }
  }

  int i=0, start = 0, end = (numsSize - 1);
  int mid = 0;
  while (start <= end)
  {
    mid = (start + end) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    else if (start == end) {
      break;
    }
    else if (target >= nums[mid] && target <= nums[end]) {
      start = mid + 1;
    }
    else if (target <= nums[mid]) {
      if (target < nums[start]) {
        if (target > nums[end]) {
          break;
        }
        else if (target <= nums[end]) {
        start = mid + 1;
        }
      }
      else if (target >= nums[start]) {
        end = mid - 1;
      }
    }
    else if (target >= nums[mid]) {
      if (target > nums[end]) {
        if(target < nums[start]) {
          break;
        }
        else if (target >= nums[start]) {
          end = mid - 1;
        }
      }
      else if (target <= nums[end]) {
      start = mid + 1;
      }
    }    
  }
  return -1;
}

int main()
{
   int arr[] = {4,5,6,7,8,1,2,3};
  int result = search(arr, 8, 8);
  printf("%d", result);
 return 0;
}