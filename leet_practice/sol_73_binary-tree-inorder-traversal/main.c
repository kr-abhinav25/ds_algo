// https://leetcode.com/problems/binary-tree-inorder-traversal

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

void getIn(struct TreeNode* root, int* i, int* returnSize, int* resp) {
  if (root){
    getIn(root->left, i, returnSize, resp);
    resp[++*i] = root->val;
    getIn(root->right, i, returnSize, resp);   
  }  
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  if (root == NULL) {
    *returnSize = 0;
    int *resp;
    return resp;
  }
  int i = -1;
  int *resp = (int*)malloc(sizeof(int)*100);
  getIn(root, &i, returnSize, resp);

  if (i > -1)
    *returnSize = i + 1;
  return resp;
}

int main() {
  struct TreeNode *root = create_root(3);
  // insert_element(root, 1);
  // insert_element(root, 2);
  // insert_element(root, 4);
  // insert_element(root, 3);
  // insert_element(root, 5);
  // insert_element(root, 8);
  // insert_element(root, 7);
  // insert_element(root, 9);
  int returnSize = 0;
  int *result = inorderTraversal(root, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d\n", result[i]);
  }
  
  // printf("%d\n", kthSmallest(root, 1));



}