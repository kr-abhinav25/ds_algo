// https://leetcode.com/problems/merge-intervals/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mergeIntervals(int **intervals, int intervalsSize, int left, int middle, int right, int **sortResult) {
  int size = right - left +1;
  int rightStart = middle + 1;
  int tempPos = left;
  while ((left <= middle) && (rightStart <= right)) {
    if (intervals[left][0] <= intervals[rightStart][0]) {
      sortResult[tempPos++] = intervals[left++];
    }
    else {
      sortResult[tempPos++] = intervals[rightStart++];
    }
  }
  while (left <= middle) {
    sortResult[tempPos++] = intervals[left++];
  }
  while (rightStart <= right) {
    sortResult[tempPos++] = intervals[rightStart++];
  }
  for (int i = 0; i < size; i++) {
    intervals[right] = sortResult[right];
    --right;
  }
  
}

void mergeSort(int **intervals, int intervalsSize, int left, int right, int **sortResult) {
  int middle;
  if (right > left) {
    middle = (left + right) / 2;
    mergeSort(intervals, intervalsSize, left, middle, sortResult);
    mergeSort(intervals, intervalsSize, middle+1, right, sortResult);
    mergeIntervals(intervals, intervalsSize, left, middle, right, sortResult);
  }
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
  int *sortResult[intervalsSize];
  mergeSort(intervals, intervalsSize, 0,  intervalsSize-1, sortResult);
  int i = 0, j; 
  int rangeStart, rangeEnd;
  int rangeCount = 0;
  int **res = (int**)malloc(sizeof(int*)*10000);
  while (i < intervalsSize) {
    rangeStart = intervals[i][0];
    rangeEnd = intervals[i][1];
    j = i+1;
    while (j < intervalsSize && intervals[j][0] <= rangeEnd) {
      rangeEnd = intervals[j][1] <= rangeEnd ?  rangeEnd : intervals[j][1];
      j++;
    }
    i = j;
    int *range = (int*)malloc(sizeof(int)*2);
    range[0] = rangeStart;
    range[1] = rangeEnd;
    res[rangeCount] = range;
    rangeCount++;
  };  

  *returnSize = rangeCount;
  *returnColumnSizes = (int*)malloc(sizeof(int) * rangeCount);
  
  for (int i = 0; i < rangeCount; i++) {
    (*returnColumnSizes)[i] = 2;
  }
  return res;
}

int main() {
  int interval1[] = {15,18};
  int interval2[] = {1,3};
  int interval3[] = {2,6};
  int interval4[] = {8,10};

  int *intervals[4];
  intervals[0] = interval1;
  intervals[1] = interval2;
  intervals[2] = interval3;
  intervals[3] = interval4;

  int intervalsColSize[] = {2,2,2,2};
  int returnCount = 0;
  int *returnSize = &returnCount;
  int *returnColumnSizes;
  int **result = merge(intervals, 4, intervalsColSize, returnSize, &returnColumnSizes);
  for (int i = 0; i < returnCount; i++) {
    printf("%d %d\n", result[i][0], result[i][1]);
  }

  int interval5[] = {1,3};

  int *intervals2[1];
  intervals2[0] = interval5;

  int intervalsColSize2[] = {2};
  int returnCount2 = 0;
  int *returnSize2 = &returnCount2;
  int *returnColumnSizes2;
  int **result2 = merge(intervals2, 1, intervalsColSize2, returnSize2, &returnColumnSizes2);
  for (int i = 0; i < returnCount2; i++) {
    printf("%d %d\n", result2[i][0], result2[i][1]);
  }

  int interval6[] = {1,4};
  int interval7[] = {0,2};
  int interval8[] = {3,5};

  int *intervals3[3];
  intervals3[0] = interval6;
  intervals3[1] = interval7;
  intervals3[2] = interval8;

  int intervalsColSize3[] = {2,2,2};
  int returnCount3 = 0;
  int *returnSize3 = &returnCount3;
  int *returnColumnSizes3;
  int **result3 = merge(intervals3, 3, intervalsColSize3, returnSize3, &returnColumnSizes3);
  for (int i = 0; i < returnCount3; i++) {
    printf("%d %d\n", result3[i][0], result3[i][1]);
  }
  
}