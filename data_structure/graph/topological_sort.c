#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for each vertex
typedef struct ListNode {
  int vertex;
  struct ListNode* next;
} Node;

typedef struct vertex {
  int vertexNo; // No. representing the vertex
  int edgeCount; //No. of edges this vertex has
  int inDegreeCount;
  Node *edge; // pointer to the first edge. All edges are Linked list to it
}Vertex;

typedef struct GraphDS {
  int numVertices;
  Vertex **adjList; //Array of Vertex
}Graph;

// Array Queue for storing nodes during BFS traversal
typedef struct ArrayQueue {
  int front;
  int rear;
  int capacity;
  int size;
  Vertex **array;
}Queue;


Queue* createQueue(int capacity) {
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  queue->capacity = 100;
  queue->size = 0;
  queue->array = (Vertex**)malloc(sizeof(Vertex*) * capacity);
  return queue;
}

int isFullQueue(Queue* queue) {
  return((queue->rear + 1 == queue->front) || (queue->front == 0 && queue->rear == queue->capacity - 1)); 
}

int isEmptyQueue(Queue *queue) {
  return (queue->front == -1);
}

void Enqueue(Queue *queue, Vertex *vertex) {
  if(isFullQueue(queue))
    printf("Queue Overflow");
  
  if (queue->front == -1) {
    queue->front = 0;
  }  
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = vertex;
  queue->size++;
}

Vertex* Dequeue(Queue *queue) {
  if(isEmptyQueue(queue)) {
    printf("Queue Underflow");
    return 0;
  }

  Vertex *vertex = queue->array[queue->front];
  if (queue->front == queue->rear)
    queue->front = queue->rear = -1;
  else
    queue->front = (queue->front + 1) % queue->capacity;
  
  queue->size--;
  return vertex;
}

Graph* createGraph(int vertices) {
  Graph *graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjList = (Vertex**)malloc(sizeof(Vertex*) * graph->numVertices);
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->vertexNo = i+1;
    vertex->edgeCount = 0;
    vertex->inDegreeCount = 0;
    vertex->edge = NULL;
    graph->adjList[i] = vertex;    
  }
  
  return graph;
}

void addEdge(Graph *graph, int sourceVertex, int destinationVertex) {

  // Numbering for vertices starting from 1
  // So reduce by 1 to store in 0th indexed Array
  --sourceVertex;
  --destinationVertex;

  Vertex *vertex = graph->adjList[sourceVertex];
  vertex->edgeCount++;

  Node *node = (Node*)malloc(sizeof(Node));
  node->vertex = destinationVertex;
  node->next = vertex->edge;
  vertex->edge = node;

  graph->adjList[destinationVertex]->inDegreeCount++;
  // Add edge from destination to source
  // if (graph->adjList[destinationVertex] == NULL) {
  //   vertex = (Vertex*)malloc(sizeof(Vertex));
  //   vertex->vertexNo = destinationVertex + 1;
  //   vertex->edgeCount = 1;
  //   vertex->edge = NULL;
  //   graph->adjList[destinationVertex] = vertex;
  // }
  // else {
  //   vertex = graph->adjList[destinationVertex];
  //   vertex->edgeCount++;
  // }

  // node = (Node*)malloc(sizeof(Node));
  // node->vertex = sourceVertex;
  // node->next = vertex->edge;
  // vertex->edge = node;
}

// Print the graph
void printGraph(Graph *graph) {
  for (int v = 0; v < graph->numVertices; v++) {
    Vertex* vertex = graph->adjList[v];
    printf("\n Vertex %d, In Degree: %d\n: ", vertex->vertexNo, vertex->inDegreeCount);
    Node* temp = vertex->edge;
    while (temp) {
      printf("%d -> ", temp->vertex+1);
      temp = temp->next;
    }
    printf("\n");
  }
}

void topologicalSort(Graph *graph) {

  Queue *queue = createQueue(graph->numVertices);

  // Add all elements with in degree of 0 to queue
  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->adjList[i]->inDegreeCount == 0) {
      Enqueue(queue, graph->adjList[i]);
    }
  }
  
  printf("Topological Sort\n");

  while (!isEmptyQueue(queue)) {
    Vertex *vertex = Dequeue(queue);
    printf("%d->", vertex->vertexNo);

    Node* temp = vertex->edge;
    while (temp) {
      Vertex *outVertex = graph->adjList[temp->vertex];
      outVertex->inDegreeCount--;
      if (outVertex->inDegreeCount == 0) {
        Enqueue(queue, outVertex);
      }
      temp = temp->next;
    }
  }
}

int main() {
  int vertices = 11;

  Graph *graph = createGraph(vertices);
  
  // addEdge(graph, 1, 4);
  // addEdge(graph, 1, 2);
  // addEdge(graph, 4, 3);
  // addEdge(graph, 2, 3);
  // addEdge(graph, 2, 7);
  // addEdge(graph, 2, 5);
  // addEdge(graph, 2, 8);
  // addEdge(graph, 5, 6);
  // addEdge(graph, 3, 9);
  // addEdge(graph, 3, 10);
  // addEdge(graph, 7, 5);
  // addEdge(graph, 5, 8);
  // addEdge(graph, 7, 8);

  addEdge(graph, 7, 11);
  addEdge(graph, 7, 8);
  addEdge(graph, 5, 11);
  addEdge(graph, 3, 8);
  addEdge(graph, 3, 10);
  addEdge(graph, 11, 10);
  addEdge(graph, 11, 9);
  addEdge(graph, 11, 2);
  addEdge(graph, 8, 9);
  // printGraph(graph);
  topologicalSort(graph); 
}