// https://leetcode.com/problems/candy/description/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {

  int result[ratingsSize];
  result[0] = 1;

  // DO these operations if only there are more than 1 elements
  if (ratingsSize > 1) {

    // Loop front->end, ensuring each element has rating > its left element
    for (int i = 1; i < ratingsSize; i++) {
      if (ratings[i] > ratings[i-1]) {
        result[i] = result[i-1] + 1;
      }
      else {
        result[i] = 1;
      }
    }

    // Loop end->front, ensuring each element has rating > its right element
    for (int i = ratingsSize-2; i >= 0; i--) {
      if ((ratings[i] > ratings[i+1]) && (result[i] <=  result[i+1])) {
        result[i] = result[i+1] + 1;
      }
    }

  }

  int candyCount = 0;
  for (int i = 0; i < ratingsSize; i++) {
    candyCount += result[i];
  }
  
  return candyCount;
  
}

int main() {
  int ratings[] = {31,2,3,4,5,3,2,1};
  int ratingsSize = sizeof(ratings)/sizeof(ratings[0]);

  int candyCount = candy(ratings, ratingsSize);
  printf("%d", candyCount);

  return 0;
}
