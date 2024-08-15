// https://leetcode.com/problems/container-with-most-water/
#include <stdio.h>

int maxArea(int* height, int heightSize) {
  int leftPtr = 0, rightPtr = heightSize - 1, currentSum = 0, maxSum = 0;

  while (leftPtr < rightPtr) {
    if (height[leftPtr] < height[rightPtr]) {
      currentSum = (rightPtr - leftPtr) * height[leftPtr];
      ++leftPtr;
    }
    else {
      currentSum = (rightPtr - leftPtr) * height[rightPtr];
      --rightPtr;      
    }
    if (currentSum > maxSum)
      maxSum = currentSum;
  }
   
  return maxSum;
}

int main() {
  int height[] = {1,8,6,2,5,4,8,3,7};
  printf("%d\n", maxArea(height, 9));
}