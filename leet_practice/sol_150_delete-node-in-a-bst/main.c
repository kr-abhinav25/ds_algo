// https://leetcode.com/problems/delete-node-in-a-bst

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
struct TreeNode* findMax(struct TreeNode* root) {
  while (root->right != NULL) {
    root = root->right;
  }
  return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
  if (root == NULL)    
    return NULL;
  
  if (key < root->val){
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->val) {
    root->right = deleteNode(root->right, key);
  }
  else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    else if (root->left && root->right == NULL) {
      return root->left;
    }
    else if (root->right && root->left == NULL) {
      return root->right;
    }
    else {
      struct TreeNode* max = findMax(root->left);
      root->val = max->val;
      root->left = deleteNode(root->left, root->val);
      return root;
    }
  }
  return root;
}

// struct TreeNode* deleteNode(struct TreeNode* root, int key) {
//   struct TreeNode * node = root;
//   deleteit(node, key);
//   return root;
// }

int main() {



  struct TreeNode *root1 = create_root(4);
  insert_element(root1, 7);
  insert_element(root1, 6);
  insert_element(root1, 5);
  insert_element(root1, 8);
  insert_element(root1, 9);
  deleteNode(root1, 7);
  pre_order(root1);

}