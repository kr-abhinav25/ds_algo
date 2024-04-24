#include <stdio.h>
#include <string.h>

void sortColors(int* nums, int numsSize) {
  if (numsSize == 0)
    return;
    
  int countZero = 0;
  int countOne = 0;
  int countTwo = 0;

  for (int i = 0; i < numsSize; i++) {
    switch( nums[i]) {
      case 0:
        ++countZero;
        break;
      case 1:
        ++countOne;
        break;
      case 2:
        ++countTwo;
        break;
      default:
        printf("Unexpected Input: %d\n", nums[i]);      
    }
  }

  int indexTracker = 0;
  while(countZero != 0) {
    nums[indexTracker] = 0;
    indexTracker++;
    countZero--;
  }
  while(countOne != 0) {
    nums[indexTracker] = 1;
    indexTracker++;
    countOne--;
  }
  while(countTwo != 0) {
    nums[indexTracker] = 2;
    indexTracker++;
    countTwo--;
  }    
}

 int main() {
  int input[] = {};
  int numSize = sizeof(input)/sizeof(input[0]);

  sortColors(input, numSize);

  for (int i = 0; i < numSize; i++) {
    printf("%d\n", input[i]);
  }

  return 0;
 }