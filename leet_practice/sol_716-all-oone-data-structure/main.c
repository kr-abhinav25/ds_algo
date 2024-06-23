// https://leetcode.com/problems/all-oone-data-structure/description/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 1000

typedef struct node {

  char *key;
  int count;
  struct node *next;
  struct node *up;
  struct node *down;
} Node;

typedef struct {
  Node **hashTable;
  Node *head;
  Node *tail;
  int elementCount;
} AllOne;

AllOne* allOneCreate() {
  AllOne *one = (AllOne*)malloc(sizeof(AllOne));
  one->hashTable = (Node**)malloc(sizeof(Node*) * HASHSIZE);
  for (int i = 0; i < HASHSIZE; i++) {
    one->hashTable[i] = NULL;
  }
  one->elementCount = 0;
  one->head = NULL;
  one->tail = NULL;

  return one;
}

int calculateHash(char *key) {
  unsigned long hash = 5381;
  int c;

  while (c = *key++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  
  return hash % HASHSIZE;
}

// Returns the Node* to the key or the node whose ->next the new node with key
// should be linked.
Node* findKeyOrNodeToLink(AllOne* obj, char* key, int hashVal) {
  Node *np =  obj->hashTable[hashVal];
  
  while(np != NULL) {
    if (strcmp(key, np->key) == 0)
      return np;

    if (np->next == NULL)
      break;

    np = np->next;
  }

  return np;
 }

Node* createNode(char* key, int count) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->key = key;
  node->count = count;
  node->next = NULL;
  node->up = NULL;
  node->down = NULL;

  return node;
}
void percolateUp(AllOne* obj, Node* node) {
  Node *upper = node;
  while (upper->up != NULL && upper->up->count < node->count) {
    upper = upper->up;
  }

  node->up->down = node->down;
  if (node == obj->tail) {
    obj->tail = node->up;
  }
  else {
    node->down->up = node->up;
  }

  if (upper == obj->head) {
    upper->up = node;
    node->down = upper;
    node->up = NULL;
    obj->head = node;
  }
  else {
    node->up = upper->up;
    node->down = upper;

    upper->up = node;
    node->up->down = node;
  }
}

void percolateDown(AllOne* obj, Node* node) {
  Node *lower = node->down;
  while (node->count < lower->count || lower != obj->tail) {
    lower = lower->down;
  }

  if (node == obj->head) {
    obj->head = node->down;
    obj->head->up = NULL;
  }
  else {
    node->up->down = node->down;
    node->down->up = node->up;
  }

  if (lower == obj->tail) {
    obj->tail = node;
    node->down = NULL;
  }
  else {
    node->down = lower->down;
    lower->down->up = node;
  }
  node->up = lower;
  lower->down = node;
}

void addNodeToTail(AllOne *obj, Node *node) {
  obj->tail->down = node;
  node->up = obj->tail;
  obj->tail = node;
}

void allOneInc(AllOne* obj, char* key) {
  Node *node;
  int hashVal = calculateHash(key);
  Node *existingNode = findKeyOrNodeToLink(obj, key, hashVal);

  // Key doesn't exist in Hash
  if (existingNode == NULL) {

    node = createNode(key, 1);
    obj->hashTable[hashVal] = node;

    // First element being added to Hash
    if (obj->elementCount == 0) {  
      obj->head = node;
      obj->tail = node;
    }
    // Link to tail and make existingNode the new tail
    else {
      addNodeToTail(obj, node);
    }
    ++obj->elementCount;
  }
  else {
    // Node with key exists
    if (strcmp(key, existingNode->key) == 0) {
      existingNode->count += 1;
      if (existingNode != obj->head && existingNode->count > existingNode->up->count) {
        percolateUp(obj, existingNode);
      }
      
    }
    else { //existingNode points to the node whose node->next the new entry should be linked to.
      node = createNode(key, 1);
      existingNode->next = node;
      addNodeToTail(obj, node);
    }
  }
}

void deleteNode(AllOne* obj, Node *node) {
  if (obj->tail == node) {
    if (obj->head == node) {
      obj->tail = obj->head = NULL;
    }
    else if (obj->head->down == node) {
      obj->head->down = NULL;
      obj->tail = obj->head;
    }
    else {
      obj->tail = node->up;
      node->up->down = NULL;
    }
  }
  else {
    if (obj->head == node) {
      // only 2 elements in List
      if (obj->head->down == obj->tail) {
        obj->head = obj->tail;
        obj->tail->up = NULL;
      }
      else {
        obj->head = obj->head->down;
        obj->head->up = NULL;
      }
    }
    else {
      node->up->down = node->down;
      if (node->down) {
        node->down->up = node->up;
      }
    }
  }
}

void allOneDec(AllOne* obj, char* key) {
  int hashVal = calculateHash(key);
  Node *node = findKeyOrNodeToLink(obj, key, hashVal);
  --node->count;
  if (node->count == 0) {
    deleteNode(obj, node);
    --obj->elementCount;
    if (obj->hashTable[hashVal] == node) {
      obj->hashTable[hashVal] = NULL;
    }
  }
  else {
    if (node != obj->tail && node->count < node->down->count) {
      percolateDown(obj, node);
    }
  }
}

char* allOneGetMaxKey(AllOne* obj) {
  if (obj->elementCount == 0) {
    char *tmp = (char*)malloc(sizeof(char)*1);
    memset(tmp, '\0', sizeof(char) * 1);
    return tmp;
  }
  return obj->head->key;
}

char* allOneGetMinKey(AllOne* obj) {
  if (obj->elementCount == 0) {
    char *tmp = (char*)malloc(sizeof(char)*1);
    memset(tmp, '\0', sizeof(char) * 1);
    return tmp;
  }
  return obj->tail->key;
}

void allOneFree(AllOne* obj) {

}

int main() {

  char hello[] = "hello";
  // char world[] = "world";
  // char leet[] = "leet";
  // char lala[] = "lala";

  // char code[] = "code";
  // char ds[] = "ds";
  // char new[] = "new";



  AllOne* obj = allOneCreate();
 
  allOneInc(obj, hello);
  allOneInc(obj, hello);

  char *result = allOneGetMaxKey(obj); 
  printf("%s\n", result);  
  result = allOneGetMinKey(obj); 
  printf("%s\n", result);

  allOneDec(obj, hello); 
  allOneDec(obj, hello); 

  result = allOneGetMinKey(obj); 
  printf("%s\n", result);

  allOneInc(obj, hello);
  result = allOneGetMinKey(obj); 
  printf("%s\n", result);

  // allOneInc(obj, hello);
  // allOneInc(obj, leet);

  // allOneInc(obj, lala);
  // allOneInc(obj, lala);
  // allOneDec(obj, leet); 

  // result = allOneGetMinKey(obj); 
  // printf("%s\n", result);

  // allOneInc(obj, ds); 
  // allOneDec(obj, leet); 

  // result = allOneGetMaxKey(obj); 
  // printf("%s\n", result);

  // allOneDec(obj, ds); 
  // allOneInc(obj, hello);

  // result = allOneGetMaxKey(obj); 
  // printf("%s\n", result);

  // allOneInc(obj, hello);
  // allOneInc(obj, hello);
  // allOneDec(obj, world); 
  // allOneDec(obj, leet); 
  // allOneDec(obj, code); 
  // allOneDec(obj, ds); 

  // result = allOneGetMaxKey(obj); 
  // printf("%s\n", result);

  // allOneInc(obj, new); 
  // allOneInc(obj, new); 
  // allOneInc(obj, new); 
  // allOneInc(obj, new); 
  // allOneInc(obj, new); 
  // allOneInc(obj, new); 

  // result = allOneGetMaxKey(obj); 
  // printf("%s\n", result);

  // result = allOneGetMinKey(obj); 
  // printf("%s\n", result);  
  // result = allOneGetMinKey(obj);
  // printf("%s\n", result);

  // allOneInc(obj, key3);
  // allOneInc(obj, key4);
  // allOneInc(obj, key3);
  // allOneDec(obj, key1); 
  // allOneInc(obj, key3);
  // allOneInc(obj, key4);
  // allOneInc(obj, key4);

  // result = allOneGetMaxKey(obj);
  // printf("%s\n", result);

  // allOneInc(obj, key2);

  // result = allOneGetMaxKey(obj); 
  // printf("%s\n", result);
  // result = allOneGetMinKey(obj);
  // printf("%s\n", result);

  // allOneDec(obj, key1); 
  // allOneDec(obj, key1); 

  // result = allOneGetMaxKey(obj); 
  // printf("%s\n", result);
  // result = allOneGetMinKey(obj);
  // printf("%s\n", result);
  
  // allOneDec(obj, key2); 
  // result = allOneGetMinKey(obj);
  // printf("%s\n", result);
  allOneFree(obj);
}