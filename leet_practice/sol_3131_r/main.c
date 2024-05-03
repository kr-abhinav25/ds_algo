// https://leetcode.com/problems/find-the-integer-added-to-array-i/

#include <stdio.h>
int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int nums1Max = nums1[0];
  int nums2Max = nums2[0];
  for (int i = 0, j= nums1Size -1; i < j && j > i; i++, j--) {
    if (nums1[i] > nums1Max) {
      nums1Max = nums1[i];
    }
    if (nums1[j] > nums1Max) {
      nums1Max = nums1[j];
    }    
    if (nums2[i] > nums2Max) {
      nums2Max = nums2[i];
    }  
    if (nums2[j] > nums2Max) {
      nums2Max = nums2[j];
    }       
  }
  return (nums2Max - nums1Max);
}


int main() {
  int nums1[] = {2,6,4};
  int nums2[] = {9,7,5};
  int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
  int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
  int result = addedInteger(nums1, nums1Size, nums2, nums2Size);
  printf("%d", result);
}
