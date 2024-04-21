typedef struct AQ
{
  int front, rear;
  int capacity;
  int *array;
} ArrayQueue;

ArrayQueue* queue(int size);
int isEmptyQueue(ArrayQueue* Q);
int isFullQueue(ArrayQueue* Q);
int QueueSize(ArrayQueue* Q);
void Enqueue(ArrayQueue* Q, int data);
int Dequeue(ArrayQueue* Q);
void DeleteQueue(ArrayQueue *Q);