// https://leetcode.com/problems/find-median-from-data-stream/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HEAP_SIZE 50000

struct maxHeap {
  int count;
  int capacity;
  int maxValue;
  int *elements;
  int isHeapified;
  int maxValuePos;
};

struct minHeap {
  int count;
  int capacity;
  int minValue;
  int *elements;
  int isHeapified;
  int minValuePos;
};

typedef struct {
  struct minHeap *minHeap;
  struct maxHeap *maxHeap;    
} MedianFinder;

MedianFinder* medianFinderCreate() {
  MedianFinder *median = (MedianFinder*)malloc(sizeof(MedianFinder));
  struct maxHeap *maxHeap = (struct maxHeap*)malloc(sizeof(struct maxHeap));
  struct minHeap *minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));

  if (minHeap == NULL || maxHeap == NULL) {
    printf("Memory Error");
    return NULL;
  }
  minHeap->capacity = maxHeap->capacity = HEAP_SIZE;
  minHeap->count = maxHeap->count = 0;
  minHeap->isHeapified = maxHeap->isHeapified = 0;
  minHeap->minValuePos = maxHeap->maxValuePos = 0;
  minHeap->minValue = INT_MAX;
  maxHeap->maxValue = INT_MIN;
  minHeap->elements = (int*)malloc(sizeof(int) * minHeap->capacity);
  maxHeap->elements = (int*)malloc(sizeof(int) * maxHeap->capacity);
  if ( minHeap->elements == NULL ||maxHeap->elements == NULL) { 
    printf("Memory Error");
    return median;
  }

  median->minHeap = minHeap;
  median->maxHeap = maxHeap;

  return median;      
}

int leftChildMinHeap(struct minHeap *minHeap, int i) {
  int left = (2*i)+1;
  if (left >= minHeap->count)
    return -1;
  return left;
}

int rightChildMinHeap(struct minHeap *minHeap, int i) {
  int right = (2*i)+2;
  if (right >= minHeap->count)
    return -1;
  return right;
}

void percolateUpMinValue(struct minHeap *minHeap, int i) {

  int min;
  int left = leftChildMinHeap(minHeap, i);
  int right = rightChildMinHeap(minHeap, i);

  if (left != -1 && minHeap->elements[left] < minHeap->elements[i]){
    min = left;
  }
  else {
    min = i;
  }

  if (right != -1 && minHeap->elements[right] < minHeap->elements[min])
    min = right;
  
  if (min != i) {
    int temp = minHeap->elements[min];
    minHeap->elements[min] = minHeap->elements[i];
    minHeap->elements[i] = temp;
    percolateUpMinValue(minHeap, min);
  }
}


void heapifyMin(struct minHeap *minHeap) {  
  // if (minHeap->isHeapified == 0) {
  //   for (int i = (minHeap->count-1)/2; i >= 0; i--) {
  //     percolateUpMinValue(minHeap, i);
  //   }
  // }
  // minHeap->isHeapified = 1;
  // minHeap->minValue = minHeap->elements[0];
  // minHeap->minValuePos = 0;

  if (minHeap->isHeapified == 0) {
    int lowets = INT_MAX;
    int lowestPos = 0;
    for (int i = 0, j = minHeap->count-1; i < minHeap->count && i <= j; i++, j--) {
      if (minHeap->elements[i] < lowets) {
        lowestPos = i;
        lowets = minHeap->elements[lowestPos];
      }
      if (minHeap->elements[j] < lowets) {
        lowestPos = j;
        lowets = minHeap->elements[lowestPos];
      }      
    }

    minHeap->elements[lowestPos] = minHeap->elements[0];
    minHeap->elements[0] = lowets;
    minHeap->isHeapified = 1;
    minHeap->minValue = minHeap->elements[0];
    minHeap->minValuePos = 0;    
  }

}

int leftChildmaxHeap(struct maxHeap *maxHeap, int i) {
  int left = (2*i)+1;
  if (left >= maxHeap->count)
    return -1;
  return left;
}

int rightChildmaxHeap(struct maxHeap *maxHeap, int i) {
  int right = (2*i)+2;
  if (right >= maxHeap->count)
    return -1;
  return right;
}

void percolateUpMaxValue(struct maxHeap *maxHeap, int i) {

  int min;
  int left = leftChildmaxHeap(maxHeap, i);
  int right = rightChildmaxHeap(maxHeap, i);

  if (left != -1 && maxHeap->elements[left] > maxHeap->elements[i]){
    min = left;
  }
  else {
    min = i;
  }

  if (right != -1 && maxHeap->elements[right] > maxHeap->elements[min])
    min = right;
  
  if (min != i) {
    int temp = maxHeap->elements[min];
    maxHeap->elements[min] = maxHeap->elements[i];
    maxHeap->elements[i] = temp;
    percolateUpMaxValue(maxHeap, min);
  }
}

void heapifyMax(struct maxHeap *maxHeap) {
  // if (maxHeap->isHeapified == 0) {
  //   int pos = (maxHeap->count-1)/2;
  //   percolateUpMaxValue(maxHeap, pos);
  //   maxHeap->isHeapified = 1;
  //   maxHeap->maxValue = maxHeap->elements[0];
  //   maxHeap->maxValuePos = 0;   
  // }   
  // if (maxHeap->isHeapified == 0) {
  //   for (int i = (maxHeap->count-1)/2; i >= 0; i--) {
  //     percolateUpMaxValue(maxHeap, i);
  //   }
  // }

  if (maxHeap->isHeapified == 0) {
    int highest = INT_MIN;
    int highestPos = 0;
    for (int i = 0, j = maxHeap->count-1; i < maxHeap->count && i <= j; i++, j--) {
      if (maxHeap->elements[i] > highest) {
        highestPos = i;
        highest = maxHeap->elements[highestPos];
      }
      if (maxHeap->elements[j] > highest) {
        highestPos = j;
        highest = maxHeap->elements[highestPos];
      }      
    }

    maxHeap->elements[highestPos] = maxHeap->elements[0];
    maxHeap->elements[0] = highest;
    maxHeap->isHeapified = 1;
    maxHeap->maxValue = maxHeap->elements[0];
    maxHeap->maxValuePos = 0;    
  }
}

void resizeMinHeap(struct minHeap *minHeap) {
  int* tmp = minHeap->elements;
  int* new = (int*)malloc(sizeof(int) * minHeap->capacity * 2);
  if (new == NULL) {
    printf("Memory Error");
    return;
  }
  minHeap->elements = new;
  for(int i=0; i < minHeap->capacity; i++) {
    minHeap->elements[i] = tmp[i];
  }

  minHeap->capacity = minHeap->capacity * 2;
  free(tmp);
}

void addToMinHeap(struct minHeap *minHeap, int num) {
  minHeap->elements[minHeap->count] = num;
  if (num < minHeap->minValue) {
    minHeap->minValue = num;
    minHeap->minValuePos = minHeap->count;
  }  
  ++minHeap->count;
  minHeap->isHeapified = 0;
}

void resizeMaxHeap(struct maxHeap *maxHeap) {
  int* tmp = maxHeap->elements;
  int* new = (int*)malloc(sizeof(int) * maxHeap->capacity * 2);
  if (new == NULL) {
    printf("Memory Error");
    return;
  }
  maxHeap->elements = new;
  for(int i=0; i < maxHeap->capacity; i++) {
    maxHeap->elements[i] = tmp[i];
  }

  maxHeap->capacity = maxHeap->capacity * 2;
  free(tmp);
}

void addToMaxHeap(struct maxHeap *maxHeap, int num) {
  maxHeap->elements[maxHeap->count] = num;
  if (num > maxHeap->maxValue) {
    maxHeap->maxValue = num;
    maxHeap->maxValuePos = maxHeap->count;
  }
  ++maxHeap->count;
  maxHeap->isHeapified = 0;
}

int dequeueMaxHeap(struct maxHeap *maxHeap) {
  if (maxHeap->count == 0)
    return -1;

  int temp = maxHeap->maxValue;
  maxHeap->elements[maxHeap->maxValuePos] = maxHeap->elements[maxHeap->count -1];
  --maxHeap->count;
  maxHeap->isHeapified = 0;
  heapifyMax(maxHeap);
  return temp;
}

int dequeueMinHeap(struct minHeap *minHeap) {
  if (minHeap->count == 0)
    return -1;

  int temp =minHeap->minValue;
  minHeap->elements[minHeap->minValuePos] = minHeap->elements[minHeap->count -1];
  --minHeap->count;
  minHeap->isHeapified = 0;
  heapifyMin(minHeap);
  return temp;
}

int findHeapMax(struct maxHeap *maxHeap) {
  heapifyMax(maxHeap);
  return maxHeap->elements[0];
}

int findHeapMin(struct minHeap *minHeap) {
  heapifyMin(minHeap);
  return minHeap->elements[0];
}

void addToHeap(struct maxHeap *maxHeap, struct minHeap *minHeap,int num) {

  if (maxHeap->count == minHeap->count) {
    if (num >= maxHeap->maxValue) {
      addToMinHeap(minHeap, num);      
    }
    else {
      addToMaxHeap(maxHeap, num);
    }
  }
  else if ((maxHeap->count - minHeap->count) > 1) {
    if (num >= maxHeap->maxValue) {
      addToMinHeap(minHeap, num);      
    }
    else {
      addToMinHeap(minHeap, maxHeap->maxValue);
      maxHeap->maxValue = num;
      maxHeap->elements[maxHeap->maxValuePos] = num;
      maxHeap->isHeapified = 0;
      heapifyMax(maxHeap);
    }
  }
  else if ((minHeap->count - maxHeap->count) > 1) {
    if (num <= minHeap->minValue) {
      addToMaxHeap(maxHeap, num);
    }
    else {
      addToMaxHeap(maxHeap, minHeap->minValue);
      minHeap->minValue = num;
      minHeap->elements[minHeap->minValuePos] = num;
      minHeap->isHeapified = 0;
      heapifyMin(minHeap);
    }    
  }
  else if ((maxHeap->count - minHeap->count) == 1) {
    if (num >= maxHeap->maxValue) {
      addToMinHeap(minHeap, num);      
    }
    else {
      addToMinHeap(minHeap, maxHeap->maxValue);
      maxHeap->maxValue = num;
      maxHeap->elements[maxHeap->maxValuePos] = num;
      maxHeap->isHeapified = 0;
      heapifyMax(maxHeap);
    }
  }
  else if ((minHeap->count - maxHeap->count) == 1) {
    if (num <= minHeap->minValue) {
      addToMaxHeap(maxHeap, num);
    }
    else {
      addToMaxHeap(maxHeap, minHeap->minValue);
      minHeap->minValue = num;
      minHeap->elements[minHeap->minValuePos] = num;
      minHeap->isHeapified = 0;
      heapifyMin(minHeap);
    }    
  }

  // addToMaxHeap(maxHeap, num);
  // if ((maxHeap->count - minHeap->count) > 1) {
  //   int tmp = dequeueMaxHeap(maxHeap);
  //   addToMinHeap(minHeap, tmp);
  // }

  // if (maxHeap->maxValue > minHeap->minValue) {
  //   int tmp = dequeueMaxHeap(maxHeap);
  //   addToMinHeap(minHeap, tmp);    
  // }
  // if ((minHeap->count - maxHeap->count) > 1) {
  //   int tmp = dequeueMinHeap(minHeap);
  //   addToMaxHeap(maxHeap, tmp);
  // }  
}

void medianFinderAddNum(MedianFinder* obj, int num) {
  addToHeap(obj->maxHeap, obj->minHeap ,num);
}

double medianFinderFindMedian(MedianFinder* obj) {
  if (obj->maxHeap->count == 0 && obj->minHeap->count == 0) {
    return (double)0;
  }
  if (obj->maxHeap->count == obj->minHeap->count) {
    // If any of the args in C are a double, a double divide is used (resulting in a double).
    // So only need to cast one of them to a double.
    double result = ((double)findHeapMax(obj->maxHeap) + findHeapMin(obj->minHeap))/2;
    return result;
  }
  else if (obj->maxHeap->count > obj->minHeap->count) {
    return (double)findHeapMax(obj->maxHeap);
  }
  else {
    return (double)findHeapMin(obj->minHeap);
  }
}

void medianFinderFree(MedianFinder* obj) {
}

int main () {
//  Your MedianFinder struct will be instantiated and called as such:
  
  double result;
  MedianFinder* obj = medianFinderCreate();
  // medianFinderAddNum(obj, 1);
  // medianFinderAddNum(obj, 2);
  // result = medianFinderFindMedian(obj);
  // printf("%f\n", result);

  // medianFinderAddNum(obj, 3);
  // result = medianFinderFindMedian(obj);
  // printf("%f\n", result);

  result = medianFinderFindMedian(obj);
  printf("%f\n", result);

  medianFinderAddNum(obj, 1);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);  

  medianFinderAddNum(obj, 2);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);

  medianFinderAddNum(obj, 3);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);  

  medianFinderAddNum(obj, 4);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);  

  medianFinderAddNum(obj, 5);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);  

  medianFinderAddNum(obj, 6);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);  

  medianFinderAddNum(obj, 7);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);    

  medianFinderAddNum(obj, 8);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);    

  medianFinderAddNum(obj, 9);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);    

  medianFinderAddNum(obj, 10);
  result = medianFinderFindMedian(obj);
  printf("%f\n", result);    


  medianFinderFree(obj);
}