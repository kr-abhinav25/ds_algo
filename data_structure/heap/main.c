#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
  int capacity;
  int count;
  int type;
  int *elements;
  
}Heap;

Heap* createHeap(int capacity, int type) {
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  if (heap == NULL) {
    printf("Memory Error");
    return NULL;
  }
  heap->capacity = capacity;
  heap->count = 0;
  heap->elements = (int*)malloc(sizeof(int) * heap->capacity);
  if (heap->elements == NULL) {
    printf("Memory Error");
    return heap;
  }

  return heap;
}

int parent(Heap* heap, int i) {
  if(i <=0 || i > heap->count)
    return -1;
  
  return (i-1)/2;
}

int leftChild(Heap* heap, int i) {
  int left = (2*i)+1;
  if (left >= heap->count)
    return -1;
  return left;
}

int rightChild(Heap* heap, int i) {
  int right = (2*i)+2;
  if (right >= heap->count)
    return -1;
  return right;
}

int getMaximum(Heap* heap) {
  if (heap->count <=0)
    return -1;
  return heap->elements[0];
}

void percolateDown(Heap* heap, int i) {

  int max, temp;
  int left = leftChild(heap, i);
  int right = rightChild(heap, i);

  if (left != -1 && heap->elements[left] > heap->elements[i]){
    max = left;
  }
  else {
    max = i;
  }

  if (right != -1 && heap->elements[right] > heap->elements[max])
    max = right;
  
  if (max != i) {
    temp = heap->elements[max];
    heap->elements[max] = heap->elements[i];
    heap->elements[i] = temp;
    percolateDown(heap, max);
  }
}

int delete(Heap* heap) {
  if (heap->count == 0) {
    return -1;
  }
  int temp = heap->elements[0];
  heap->elements[0] = heap->elements[heap->count -1];
  percolateDown(heap, 0);
  return temp;
}

void DestroyHeap(Heap* heap){
  if (heap == NULL)
    return;
  free(heap->elements);
  free(heap);
  heap = NULL;
}

void resizeHeap(Heap* heap) {
  int* tmp = heap->elements;
  int* new = (int*)malloc(sizeof(int) * heap->capacity * 2);
  if (new == NULL) {
    printf("Memory Error");
    return;
  }
  heap->elements = new;
  for(int i=0; i < heap->capacity; i++) {
    heap->elements[i] = tmp[i];
  }

  heap->capacity = heap->capacity * 2;
  free(tmp);
}
void insert(Heap* heap, int data) {
  if (heap->count == heap->capacity)
    resizeHeap(heap);
  
  heap->count++;
  int i = heap->count -1;
  while (i > 0 && heap->elements[(i-1)/2] < data)
  {
    heap->elements[i] = heap->elements[(i-1)/2];
    i = (i-1)/2;
  }

  heap->elements[i] = data;
}

void buildHeap(Heap* heap, int elements[], int count){
  for (int i = 0; i < count; i++)
  {
    heap->elements[i] = elements[i];
  }
  heap->count = count;
  int lastElement = heap->count-1;
  for (int i = (lastElement-1)/2; i >=0; i-- )
  {
    percolateDown(heap,i);
  }
  
}

void heapSort(Heap* heap) {

  int oldSize = heap->count;
  while (heap->count >= 0 )
  {
    int temp = heap->elements[0];
    printf("%d\n", temp);
    heap->elements[0] = heap->elements[heap->count-1];
    heap->elements[heap->count-1] = temp;
    heap->count--;
    percolateDown(heap,0); 
  }
  heap->count = oldSize;
}

int main() {
  int elements[] = {12,7,5,8,45,1,55,4,101,15,195,418,369,85};
  int count = sizeof(elements)/sizeof(elements[0]);

  Heap *heap = createHeap(count,0);
  buildHeap(heap, elements, count);
  heapSort(heap);
  // for (int i = 0; i < count; i++)
  // {
  //   printf("%d\n", heap->elements[i]);
  // }
  

}

