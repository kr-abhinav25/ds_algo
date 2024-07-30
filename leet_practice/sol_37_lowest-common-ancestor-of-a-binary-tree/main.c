// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct TreeNode* findAncestor(struct TreeNode* root, int p, int q) {

  if (root == NULL)
    return NULL;

  if (root->val == p || root->val == q)
    return root;

  struct TreeNode* left = findAncestor(root->left, p , q);
  struct TreeNode* right = findAncestor(root->right, p, q);

  if (left == NULL && right == NULL)
    return NULL;
  else if (left == NULL && right != NULL)
    return right;
  else if (left != NULL && right == NULL)
    return left;
  else
    return root;    
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  if (root->val == p->val)
    return p;
  else if (root->val == q->val)
    return q;
  
  return findAncestor(root, p->val, q->val);
}

void pre_order(struct TreeNode *root){
  if (root){
    pre_order(root->left);
    printf("%d\n", root->val);
    pre_order(root->right);   
  }
};

int main() {

  struct TreeNode *root = create_root(3);
  struct TreeNode *left, *right;
  left = insert_left(root, 5);
  insert_left(left, 6);
  right = insert_right(left, 2);
  insert_left(right, 7);
  insert_right(right, 4);
  right = insert_right(root, 1);
  insert_left(right, 0);
  insert_right(right, 8);

  // pre_order(root);

  printf("%d", lowestCommonAncestor(root, left, right)->val);


}