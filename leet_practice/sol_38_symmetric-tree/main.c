// https://leetcode.com/problems/symmetric-tree/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool checkSymmetry(struct TreeNode* left, struct TreeNode* right) {
  if (left == NULL && right == NULL)
    return true;
  
  if (left == NULL && right != NULL)
  return false;

  if (right == NULL && left != NULL)
  return false;

  if (left->val == right->val) {
    return (checkSymmetry(left->right, right->left) && checkSymmetry(left->left, right->right));
  }
  else {
    return false;
  }
}

bool isSymmetric(struct TreeNode* root) {
  if (root == NULL)
    return false;
  
  return (checkSymmetry(root->left, root->right));
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

  struct TreeNode *left, *right;

  struct TreeNode *root = create_root(2);
  left = insert_left(root, 3);
  left = insert_left(left, 4);
  insert_right(left, 5);
  right = insert_right(root, 3);
  insert_left(right, 5);
  printf("0: %d\n", isSymmetric(root));

  root = create_root(1);
  left = insert_left(root, 2);
  insert_left(left, 3);
  insert_right(left, 4);
  right = insert_right(root, 2);
  insert_left(right, 4);
  insert_right(right, 3);
  printf("1: %d\n", isSymmetric(root));



}