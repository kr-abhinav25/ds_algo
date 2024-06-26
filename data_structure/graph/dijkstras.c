#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for each vertex
typedef struct ListNode {
  int vertex;
  int edge; //distance from source vertex
  struct ListNode* next;
} Node;

typedef struct vertex {
  int vertexNo; // No. representing the vertex
  char name; //name of vertex
  int edgeCount; //No. of edges this vertex has
  int inDegreeCount;
  Node *edge; // pointer to the first edge. All edges are Linked list to it
}Vertex;

typedef struct GraphDS {
  int numVertices;
  Vertex **adjList; //Array of Vertex
}Graph;

typedef struct heapNode {
  Vertex *vertex;
  int currentDistance;
}heapNode;

typedef struct PriorityQueue
{
  int capacity;
  int count;
  heapNode **heapNodes;
}Heap;

Heap* createHeap(int capacity) {
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  heap->capacity = capacity;
  heap->count = 0;
  heap->heapNodes = (heapNode**)malloc(sizeof(heapNode*) * heap->capacity);
  for (int i = 0; i < capacity; i++) {
    heap->heapNodes[i] = NULL;
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

  if (left != -1 && heap->heapNodes[left]->currentDistance < heap->heapNodes[i]->currentDistance){
    min = left;
  }
  else {
    min = i;
  }

  if (right != -1 && heap->heapNodes[right]->currentDistance < heap->heapNodes[min]->currentDistance)
    min = right;
  
  if (min != i) {
    int temp = heap->heapNodes[min]->currentDistance;
    heap->heapNodes[min]->currentDistance = heap->heapNodes[i]->currentDistance;
    heap->heapNodes[i]->currentDistance = temp;
    percolateUpMinValue(heap, min);
  }
}

void heapify(Heap *heap) {
  for (int i = (heap->count-1)/2; i >= 0; i--) {
    percolateUpMinValue(heap, i);
  }
}

int isEmptyQueue(Heap *minHeap) {
  return (minHeap->count == 0);
}

Graph* createGraph(int vertices) {
  Graph *graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjList = (Vertex**)malloc(sizeof(Vertex*) * graph->numVertices);

  for (int i = 0, j = 97; i < graph->numVertices; i++, j++) {
    Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->vertexNo = i+1;
    vertex->name = (char)j;
    vertex->edgeCount = 0;
    vertex->inDegreeCount = 0;
    vertex->edge = NULL;
    graph->adjList[i] = vertex;    
  }
  
  return graph;
}

void addEdge(Graph *graph, int sourceVertex, int destinationVertex, int distance) {

  // Numbering for vertices starting from 1
  // So reduce by 1 to store in 0th indexed Array
  --sourceVertex;
  --destinationVertex;
  
  Vertex *vertex = graph->adjList[sourceVertex];
  vertex->edgeCount++;

  Node *node = (Node*)malloc(sizeof(Node));
  node->vertex = destinationVertex;
  node->next = vertex->edge;
  node->edge = distance;
  vertex->edge = node;

  graph->adjList[destinationVertex]->inDegreeCount++;
}

// Print the graph
void printGraph(Graph *graph) {
  for (int v = 0; v < graph->numVertices; v++) {
    Vertex* vertex = graph->adjList[v];
    printf("\n Vertex %c:\n", vertex->name);
    Node* temp = vertex->edge;
    while (temp) {
      printf("%c --%d--> %c\n",  vertex->name, temp->edge, graph->adjList[temp->vertex]->name);
      temp = temp->next;
    }
    printf("\n");
  }
}


heapNode* deQueue(Heap *heap) {
  if (heap->count == 0) {
    return NULL;
  }
  heapNode *temp = heap->heapNodes[0];
  heap->heapNodes[0] = heap->heapNodes[heap->count-1];
  --heap->count;
  heapify(heap);
  return temp;
}

void enQueue(Heap *heap, Vertex *vertex, int currentDistance) {
  if (heap->count == heap->capacity) {
    printf("Heap full");
  }
  heapNode *hp = (heapNode*)malloc(sizeof(heapNode));
  hp->vertex = vertex;
  hp->currentDistance = currentDistance;
  heap->heapNodes[heap->count] = hp;
  ++heap->count;
  heapify(heap);
}

void updatePriority(Heap *heap, Vertex *vertex, int newDistance) {
  for (int i = 0; i < heap->count; i++) {
    if (heap->heapNodes[i]->vertex->vertexNo == vertex->vertexNo) {
      heap->heapNodes[i]->currentDistance = newDistance;
      heapify(heap);
      break;
    }
  }
}

void dijkstras(Graph *graph, Vertex *sv) {
  Vertex *startingVertex = sv;
  int *pathDistances = (int*)malloc(sizeof(int) * graph->numVertices);
  int *visited = (int*)malloc(sizeof(int) * graph->numVertices);
  char *routeVia = (char*)malloc(sizeof(char) * (graph->numVertices + 1));

  memset(pathDistances, -1, sizeof(int) * graph->numVertices);
  memset(visited, 0, sizeof(int) * graph->numVertices);
  memset(routeVia, -'\0',sizeof(char) * graph->numVertices);
  // vertexNo indexing start from 1
  pathDistances[startingVertex->vertexNo - 1] = 0;
  routeVia[startingVertex->vertexNo - 1] = startingVertex->name;

  Heap *minHeap = createHeap(graph->numVertices);
  heapNode *hp = (heapNode*)malloc(sizeof(heapNode));
  enQueue(minHeap, startingVertex, 0);

  while (!isEmptyQueue(minHeap)) {
    hp = deQueue(minHeap);
    startingVertex = hp->vertex;
    visited[startingVertex->vertexNo - 1] = 1;
    Node* temp = startingVertex->edge;
    while (temp) {
      // calculate distance from current vertex
      int newDistance = pathDistances[startingVertex->vertexNo - 1] + temp->edge;
      int currentDistance = pathDistances[temp->vertex];
      if (currentDistance == -1) {
        pathDistances[temp->vertex] = newDistance;
        routeVia[temp->vertex] = hp->vertex->name;
        if (visited[temp->vertex] == 0) {
          Vertex *v = graph->adjList[temp->vertex];
          enQueue(minHeap, v, newDistance);
        }
      }
      if (newDistance < currentDistance) {
        pathDistances[temp->vertex] = newDistance;
        routeVia[temp->vertex] = hp->vertex->name;
        Vertex *v = graph->adjList[temp->vertex];
        updatePriority(minHeap, v, newDistance);
      }
      temp = temp->next;
    }    
  }

  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vertex: %c, cost: %d, from: %c\n", graph->adjList[i]->name, pathDistances[i], routeVia[i] );
  }
  
}

int main() {
  int vertices = 5;

  Graph *graph = createGraph(vertices);

  addEdge(graph, 1, 2, 4);
  addEdge(graph, 1, 3, 1);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 2, 2);
  addEdge(graph, 3, 4, 4);
  addEdge(graph, 4, 5, 4);
  // printGraph(graph);
  dijkstras(graph, graph->adjList[0]);
}