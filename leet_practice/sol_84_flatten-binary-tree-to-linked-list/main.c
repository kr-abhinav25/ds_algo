// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

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
    printf("%d\n", root->val);
    pre_order(root->left);
    pre_order(root->right);   
  }
}

void buildList(struct TreeNode *root, struct TreeNode** list, int* countPtr){
  if (root){
    list[++*countPtr] = root;
    buildList(root->left, list, countPtr);
    buildList(root->right, list, countPtr);
  }
}

void flatten(struct TreeNode* root) {
  struct TreeNode **list = (struct TreeNode**)(malloc(sizeof(struct TreeNode*) * 2000));
  int count = -1;
  int *countPtr = &count;
  buildList(root, list, countPtr);
  ++count;
  struct TreeNode* tmp = root;
  for (int i = 1; i < count; i++) {
    tmp->left = NULL;
    tmp->right = list[i];
    tmp = tmp->right;
  }
}

int main() {
  struct TreeNode *left, *right;

  // struct TreeNode *root = create_root(1);
  // left = insert_left(root, 2);
  // insert_left(left, 3);
  // insert_right(left, 4);
  // left = insert_right(root, 5);
  // left = insert_right(left, 6);
  // flatten(root);
  // pre_order(root);

  struct TreeNode *root1 = create_root(1);
  left = insert_left(root1, 2);
  flatten(root1);
  pre_order(root1);
}