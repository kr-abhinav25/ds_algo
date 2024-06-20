// https://leetcode.com/problems/merge-k-sorted-lists/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode* resultHead = NULL;

typedef struct heap
{
  int capacity;
  int count;
  int type;
  struct ListNode **elements;
  
}Heap;

// Linked List functions: 
struct ListNode* newNode(){
  struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
  return node;
}

void insert(struct ListNode* head, int element) {
  struct ListNode* tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  
  struct ListNode* node = newNode();
  node->val = element;
  node->next = NULL;
  tmp->next = node;
}

struct ListNode* createHead(int element) {
  struct ListNode* node = newNode();
  node->val = element;
  node->next = NULL;
  return node;
}

void printList(struct ListNode* head) {
  struct ListNode* tmp = head;
  
  if (tmp == NULL) {
    printf("No item in List");
    return;
  }
  while(tmp != NULL) {
    printf("%d\n", tmp->val);
    tmp = tmp->next;
  }
}

struct ListNode* createListFromArray(int arr[], int size) {
  if (size == 0) {
    return NULL;
  }

  struct ListNode* head = createHead(arr[0]);

  for (int i = 1; i < size; i++) {
    insert(head, arr[i]);
  }

  return head;
}


// Heap functions:
Heap* createHeap(int capacity) {
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  if (heap == NULL) {
    printf("Memory Error");
    return NULL;
  }
  heap->capacity = capacity;
  heap->count = 0;
  heap->elements = (struct ListNode**)malloc(sizeof(struct ListNode*) * heap->capacity);
  if (heap->elements == NULL) {
    printf("Memory Error");
    return heap;
  }

  return heap;
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

void percolateUpMinValue(Heap* heap, int i) {

  int min;
  int left = leftChild(heap, i);
  int right = rightChild(heap, i);

  if (left != -1 && heap->elements[left]->val < heap->elements[i]->val){
    min = left;
  }
  else {
    min = i;
  }

  if (right != -1 && heap->elements[right]->val < heap->elements[min]->val)
    min = right;
  
  if (min != i) {
    struct ListNode* temp = heap->elements[min];
    heap->elements[min] = heap->elements[i];
    heap->elements[i] = temp;
    percolateUpMinValue(heap, min);
  }
}

void heapify(Heap *heap) {
  for (int i = (heap->count-1)/2; i >= 0; i--) {
    percolateUpMinValue(heap, i);
  }
}

void  addNextElementToHeap(Heap *heap) {
  // add next element from list to root of heap
  if (heap->elements[0]->next != NULL) {
      heap->elements[0] = heap->elements[0]->next;
  }
  else {
    heap->elements[0] = heap->elements[heap->count-1];
    heap->count--;
  }
}
void addToResult(int val) {
  if (resultHead == NULL) {
    resultHead = createHead(val);
  }
  else {
    insert(resultHead, val);
  }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  struct ListNode* result = NULL;
  if (listsSize == 0) {
    return result;
  }
  Heap *heap = createHeap(listsSize);
  for (int i = 0; i < listsSize; i++) {
    struct ListNode* current = lists[i];

    if (current != NULL) {
      heap->count++;
      heap->elements[heap->count-1] = current;
    }
  }

  while (heap->count > 0) {
    heapify(heap);
    addToResult(heap->elements[0]->val);
    addNextElementToHeap(heap);
  }

  result = resultHead;
  return result;
}

int main() {

  int listArr1[] = {1,4,5};
  int listArr2[] = {1,3,4};
  int listArr3[] = {2,6};
  int listArr4[] = {};

  int listLengths[4];
  listLengths[0] = sizeof(listArr1)/sizeof(listArr1[0]);
  listLengths[1] = sizeof(listArr2)/sizeof(listArr2[0]);
  listLengths[2] = sizeof(listArr3)/sizeof(listArr3[0]);
  listLengths[3] = sizeof(listArr4)/sizeof(listArr4[0]);
  struct ListNode* List1 = createListFromArray(listArr1, listLengths[0]);
  struct ListNode* List2 = createListFromArray(listArr2, listLengths[1]);
  struct ListNode* List3 = createListFromArray(listArr3, listLengths[2]);
  struct ListNode* List4 = createListFromArray(listArr4, listLengths[3]);

  struct ListNode* List[4] = {List1, List2, List3, List4};

  struct ListNode* result = mergeKLists(List, 4);
  printList(result);
  // printList(List1);
  // printList(List2);
  // printList(List3);
  // printList(List4);

}