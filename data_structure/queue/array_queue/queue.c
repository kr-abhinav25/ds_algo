#include "queue.h"
#include "stdio.h"
#include <stdlib.h>

ArrayQueue* queue(int size) {
  ArrayQueue* Q = malloc(sizeof(ArrayQueue));
  if (!Q)
    return NULL;
  
  Q->capacity = size;
  Q->front = Q->rear = -1;
  Q->array = malloc(sizeof(int)* Q->capacity);
  return Q;
}

int isEmptyQueue(ArrayQueue* Q) {
  return(Q->front == -1);
}

int isFullQueue(ArrayQueue* Q) {
  return(((Q->rear + 1) % Q->capacity) == Q->front); 
}

int QueueSize(ArrayQueue* Q) {
  return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void Enqueue(ArrayQueue* Q, int data) {
  if(isFullQueue(Q))
    printf("Queue Overflow");
  
  Q->rear = (Q->rear + 1)* Q->capacity;
  Q->array[Q->rear] = data;
  if(Q->front == -1) {
    Q->rear = Q->front;
  }
}

int Dequeue(ArrayQueue* Q) {
  if(isEmptyQueue(Q)) {
    printf("Queue Underflow");
    return 0;
  }

  int data = 0;
  data = Q->array[Q->front];
  if (Q->front == Q->rear)
    Q->front = Q->rear = -1;
  else
    Q->front = (Q->front + 1) % Q->capacity;
  
  return data;
}

void DeleteQueue(ArrayQueue *Q) {
  if (Q) {
    if (Q->array)
      free(Q->array);
  free(Q);
  }
}