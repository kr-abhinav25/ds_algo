// https://leetcode.com/problems/trapping-rain-water/description/
#include <stdio.h>
#include <string.h>

int trap(int* height, int heightSize) {
  int leftHeight[heightSize];
  int rightHeight[heightSize];
  int result = 0;
  int maxLeft = 0;
  int maxRight = 0;

  // fill arrays with 0, GOD knows why memset isn't working!
  for (int i = 0; i < heightSize; i++) {
    leftHeight[i] = 0;
    rightHeight[i] = 0;
  }

  // The idea is to calculate how much water can be held by
  // each block. So at each point, get the max left and max right
  // which defines maximum water that point can hold. From this
  // get the min(max left, max right) as the lower of them will
  // determine the holding capacity. Subtraction any elavation from
  // this at the point also to account for the unfillable area.
  for (int i = 0; i < heightSize; i++) {
    if (height[i] > maxLeft) {
      maxLeft = height[i];
    }
    leftHeight[i] = maxLeft;
  }
  
  for (int j = heightSize-1; j >= 0; j--) {
    if (height[j] > maxRight) {
      maxRight = height[j];
    }
    rightHeight[j] = maxRight;
  }

  for (int k = 0; k < heightSize; k++) {
    int minHeight = 0;
    if (leftHeight[k] < rightHeight[k]) {
      minHeight = leftHeight[k];
    }
    else {
      minHeight = rightHeight[k];
    }
    result = result + (minHeight - height[k]);

  }
  
  return result;
}

int main() {
  int height[] = {2,1,2};
  int heightSize = (int)(sizeof(height)/sizeof(height[0]));
  int output = trap(height, heightSize);
  printf("%d", output);
}