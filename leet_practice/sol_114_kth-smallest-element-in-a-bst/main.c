// https://leetcode.com/problems/kth-smallest-element-in-a-bst

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct TreeNode* insert_element(struct TreeNode *root, int val) {
  struct TreeNode *tmp = root;
  struct TreeNode *item = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  item->val = val;
  item->left = item->right = NULL;

  do
  {
    if(val <= tmp->val) {
      if (tmp->left == NULL) {
        tmp->left = item;
        break;
      }
      tmp = tmp->left;
    }
    else if (val > tmp->val)
    {
      if (tmp->right == NULL) {
        tmp->right = item;
        break;
      }      
      tmp = tmp->right;
    }
    
  }while(1==1);
  return item;
};

void pre_order(struct TreeNode *root){
  if (root){
    pre_order(root->left);
    printf("%d\n", root->val);
    pre_order(root->right);   
  }
};

struct TreeNode* kk(struct TreeNode* root, int k, int *count) {
  if (!root)
    return NULL;

  struct TreeNode *left = kk(root->left, k, count);
  if (left)
    return left;
  if(++*count == k)
    return root;
  
  return kk(root->right, k, count);
}

int kthSmallest(struct TreeNode* root, int k) {
  int pos = 0;
  int *count = &pos;
  struct TreeNode* tmp = kk(root, k, count);
  return tmp->val;
}

int main() {
  struct TreeNode *root = create_root(3);
  insert_element(root, 1);
  insert_element(root, 2);
  insert_element(root, 4);
  // insert_element(root, 3);
  // insert_element(root, 5);
  // insert_element(root, 8);
  // insert_element(root, 7);
  // insert_element(root, 9);

  printf("1: %d\n", kthSmallest(root, 4));

  struct TreeNode *root1 = create_root(5);
  insert_element(root1, 3);
  insert_element(root1, 6);
  insert_element(root1, 2);
  insert_element(root1, 4);
  insert_element(root1, 1);

  printf("3: %d\n", kthSmallest(root1, 3));



}