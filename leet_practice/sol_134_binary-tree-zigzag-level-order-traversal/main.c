// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct AQ
{
  int front, rear;
  int capacity;
  struct TreeNode **array;
} Queue;

Queue* createQueue(int size) {
  Queue* Q = malloc(sizeof(Queue));
  if (!Q)
    return NULL;
  
  Q->capacity = size;
  Q->front = Q->rear = -1;
  Q->array = (struct TreeNode**)malloc(sizeof(struct TreeNode*)* Q->capacity);
  return Q;
}

int isEmptyQueue(Queue* Q) {
  return(Q->front == -1);
}

int isFullQueue(Queue* Q) {
  return (Q->rear == Q->capacity-1);
}

void Enqueue(Queue* Q, struct TreeNode *data) {
  if(isFullQueue(Q))
    printf("Queue Overflow");
  
  Q->array[++Q->rear] = data;
  if(Q->front == -1) {
    Q->front = 0;
  }
}

struct TreeNode* Dequeue(Queue* Q) {
  if(isEmptyQueue(Q)) {
    printf("Queue Underflow");
    return 0;
  }

  struct TreeNode *data = Q->array[Q->front];
  if (Q->front == Q->rear)
    Q->front = Q->rear = -1;
  else
    ++Q->front;
  
  return data;
}

// Helper function to determine the height of the tree.
int getHeight(struct TreeNode* root) {
    if (!root) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
int **result;
  if (root == NULL) {
    *returnSize = 0;
    return result;
  }

  int leftToRight = 0, levelCount = 0, currentLevelIndex = -1, nextLevelIndex = -1;

  int height = getHeight(root);
  int stackLength = 1 << (height - 1);
  *returnSize = height;
  
  result = (int**)malloc(sizeof(int*) * height);
  *returnColumnSizes = (int*)malloc(sizeof(int) * height);
  struct TreeNode **currentLevel = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * stackLength);
  struct TreeNode **nextLevel = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * stackLength);
  struct TreeNode **tmp;

  currentLevel[++currentLevelIndex] = root;
  while (currentLevelIndex > -1) {
    
    int *res = (int *)malloc(sizeof(int) * (currentLevelIndex + 1));
    int resIndex = currentLevelIndex;
    (*returnColumnSizes)[levelCount] = currentLevelIndex+1;
    while (currentLevelIndex > -1) {
      
      // add to result
      res[resIndex--] = currentLevel[currentLevelIndex]->val;
      if (leftToRight) {
        if (currentLevel[currentLevelIndex]->left != NULL)
          nextLevel[++nextLevelIndex] = currentLevel[currentLevelIndex]->left;
        if (currentLevel[currentLevelIndex]->right != NULL)
        nextLevel[++nextLevelIndex] = currentLevel[currentLevelIndex]->right;
      }
      else {
        if (currentLevel[currentLevelIndex]->right != NULL)        
          nextLevel[++nextLevelIndex] = currentLevel[currentLevelIndex]->right;
        if (currentLevel[currentLevelIndex]->left != NULL)
          nextLevel[++nextLevelIndex] = currentLevel[currentLevelIndex]->left;
      }        
      --currentLevelIndex;
    }
    currentLevelIndex = nextLevelIndex;
    nextLevelIndex = -1;
    tmp = currentLevel;
    currentLevel = nextLevel;
    nextLevel = tmp;
    result[levelCount++] = res;
    leftToRight = 1 - leftToRight;
  }
 
  return result;
}

struct TreeNode* create_root(int val) {
  struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  root->val = val;
  root->left = NULL;
  root->right = NULL;

  return root;
};

struct TreeNode* insert_left(struct TreeNode* root, int val) {
  struct TreeNode *item = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  item->val = val;
  item->left = item->right = NULL;
  root->left = item;
  return item;
}

struct TreeNode* insert_right(struct TreeNode* root, int val) {
  struct TreeNode *item = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  item->val = val;
  item->left = item->right = NULL;
  root->right = item;
  return item;

}
void pre_order(struct TreeNode *root){
  if (root){
    pre_order(root->left);
    printf("%d\n", root->val);
    pre_order(root->right);   
  }
};

int main() {

  int returnSize;
  int *returnColumnSizes;

  struct TreeNode *left, *right;

  struct TreeNode *root = create_root(3);
  insert_left(root, 9);
  right = insert_right(root, 20);
  insert_left(right, 15);
  insert_right(right, 7);
  // pre_order(root);
  
  zigzagLevelOrder(root, &returnSize, &returnColumnSizes);
  zigzagLevelOrder(NULL, &returnSize, &returnColumnSizes);


}