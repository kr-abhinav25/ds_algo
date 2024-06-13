#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for each vertex
typedef struct ListNode {
  int vertex;
  struct ListNode* next;
} Node;

typedef struct GraphDS {
  int numVertices;
  Node **adjList;
}Graph;

// Array Queue for storing nodes during BFS traversal
typedef struct ArrayQueue {
  int front;
  int rear;
  int capacity;
  int size;
  Node **array;
}Queue;

int *visited;

Queue* createQueue(int capacity) {
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  queue->capacity = 1000;
  queue->size = 0;
  queue->array = (Node**)malloc(sizeof(Node*) * capacity);
  return queue;
}

int isFullQueue(Queue* queue) {
  return((queue->rear + 1 == queue->front) || (queue->front == 0 && queue->rear == queue->capacity - 1)); 
}

int isEmptyQueue(Queue *queue) {
  return (queue->front == -1);
}

void Enqueue(Queue *queue, Node *node) {
  if(isFullQueue(queue))
    printf("Queue Overflow");
  
  if (queue->front == -1) {
    queue->front = 0;
  }  
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = node;
  queue->size++;
}

Node* Dequeue(Queue *queue) {
  if(isEmptyQueue(queue)) {
    printf("Queue Underflow");
    return 0;
  }

  Node *node = queue->array[queue->front];
  if (queue->front == queue->rear)
    queue->front = queue->rear = -1;
  else
    queue->front = (queue->front + 1) % queue->capacity;
  
  queue->size--;
  return node;
}

Graph* createGraph(int vertices) {
  Graph *graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjList = (Node**)malloc(sizeof(Node*) * graph->numVertices);
  visited = (int*)malloc(sizeof(int) * graph->numVertices);
  for (int i = 0; i < graph->numVertices; i++) {
    graph->adjList[i] = NULL;
  }
  
  return graph;
}

void addEdge(Graph *graph, int sourceVertex, int destinationVertex) {

  // Numbering for vertices starting from 1
  // So reduce by 1 to store in 0th indexed Array
  --sourceVertex;
  --destinationVertex;
  // Add edge from source to destination
  Node *node = (Node*)malloc(sizeof(Node));
  node->vertex = destinationVertex;
  node->next = graph->adjList[sourceVertex];
  graph->adjList[sourceVertex] = node;

  // Add edge from destination to source
  node = (Node*)malloc(sizeof(Node));
  node->vertex = sourceVertex;
  node->next = graph->adjList[destinationVertex];
  graph->adjList[destinationVertex] = node;
}

// Print the graph
void printGraph(Graph *graph) {
  for (int v = 0; v < graph->numVertices; v++) {
    Node* temp = graph->adjList[v];
    printf("\n Vertex %d\n: ", v+1);
    while (temp) {
      printf("%d -> ", temp->vertex+1);
      temp = temp->next;
    }
    printf("\n");
  }
}

void dfs(Graph *graph, int vertex) {
  visited[vertex] = 1;
  printf("Visited Vertex %d\n ", vertex+1);
  Node *temp = graph->adjList[vertex];
  while (temp != NULL) {
    if (visited[temp->vertex] == 0) {
      dfs(graph, temp->vertex);
    }
    temp = temp->next;
  }
  
}

void dfsTraversal(Graph *graph) {
  memset(visited, 0, graph->numVertices * sizeof(int));
  printf("\nBFS Traversal:\n");
  for (int i = 0; i < graph->numVertices; i++) {
    if (visited[i] == 0) {
      dfs(graph, i);
    }

  }
}
void bfs(Graph *graph, Queue *queue) {
  Node* temp = Dequeue(queue);
  visited[temp->vertex] = 1;
  printf("Visited Vertex: %d\n", temp->vertex+1);
  while (temp != NULL) {
    if (visited[temp->vertex] == 0) {
      Enqueue(queue, graph->adjList[temp->vertex]);
    }
    temp = temp->next;
  }
  if (!isEmptyQueue(queue)) {
    bfs(graph, queue);
  }
}

void bfsTraversal(Graph *graph) {
  printf("BFS Traversal:\n");
  memset(visited, 0, graph->numVertices * sizeof(int));
  Queue *queue = createQueue(graph->numVertices);

  int startingVertex = 0;
  visited[startingVertex] = 1;
  printf("Visited Vertex: %d\n", startingVertex+1);
  Node* temp = graph->adjList[startingVertex];

  //Add all vertex to explore from the starting node
  while (temp != NULL) {
    Enqueue(queue, temp);
    temp = temp->next;
  }

  while (!isEmptyQueue(queue)) {
    Node* temp = Dequeue(queue);

    // If the vertex is not visited yet, mark it visited and all its edge vertices to the queue
    if (visited[temp->vertex] == 0) {
      printf("Visited Vertex: %d\n", temp->vertex+1);
      visited[temp->vertex] = 1;

      temp = graph->adjList[temp->vertex];
      while (temp != NULL) {
        if (visited[temp->vertex] == 0) {
          Enqueue(queue, temp);
        }
        temp = temp->next;
      }
    } 
  };
}

int main() {
  int vertices = 10;

  Graph *graph = createGraph(vertices);
  
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 4, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 7);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 8);
  addEdge(graph, 5, 6);
  addEdge(graph, 3, 9);
  addEdge(graph, 3, 10);
  addEdge(graph, 7, 5);
  addEdge(graph, 5, 8);
  addEdge(graph, 7, 8);


  printGraph(graph); 
  dfsTraversal(graph);
  bfsTraversal(graph);
}