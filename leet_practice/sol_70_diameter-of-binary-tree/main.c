// https://leetcode.com/problems/diameter-of-binary-tree/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int depth(struct TreeNode* root, int *diameter) {
  if (root == NULL)
    return 0;
  
  int leftCount = depth(root->left, diameter);
  int rightCount = depth(root->right, diameter);
  
  int sum = leftCount + rightCount;
  if (sum > *diameter) {
    *diameter = sum;
  }
  if (leftCount > rightCount) {
    return leftCount + 1;
  }
  else {
    return rightCount + 1;
  }
}

int diameterOfBinaryTree(struct TreeNode* root) {
  int left  = 0, right = 0;
  int diameter = 0;
  if (root == NULL)
    return 0;
  
  depth(root, &diameter);
  return diameter;
}

struct TreeNode* create_root(int val) {
  struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  root->val = val;
  root->left = NULL;
  root->right = NULL;

  return root;
};

void insert_element(struct TreeNode *root, int val) {
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

  struct TreeNode *root = create_root(1);
  struct TreeNode *left, *right;
  left = insert_left(root, 2);
  right = insert_right(root, 3);
  insert_left(left, 4);
  left = insert_right(left, 5);
  // pre_order(root);

  printf("%d", diameterOfBinaryTree(root));


}