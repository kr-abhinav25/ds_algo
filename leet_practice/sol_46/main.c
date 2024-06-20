// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
int maxSum = INT_MIN;

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

void pre_order(struct TreeNode *root){
  if (root){
    printf("%d\n", root->val);
    pre_order(root->left);
    pre_order(root->right);   
  }
};

int sumDfs(struct TreeNode* root) {
  int leftSum = 0;
  int rightSum = 0;
  if (root->left) {
    leftSum = sumDfs(root->left);
  }
  if (root->right) {
    rightSum = sumDfs(root->right);
  }

  int leftSumWithParent = leftSum + root->val;
  int rightSumWithParent = rightSum + root->val;
  int subtreeSum = leftSum + rightSum + root->val;
  if (subtreeSum > maxSum) {
    maxSum = subtreeSum;
  }
  if (leftSumWithParent > maxSum) {
    maxSum = leftSumWithParent;
  }
  if (rightSumWithParent > maxSum) {
    maxSum = rightSumWithParent;
  }
  if (root->val > maxSum) {
    maxSum = root->val;
  }
  if (leftSumWithParent >rightSumWithParent) {
    if (root->val > leftSumWithParent) {
      return root->val;
    }
    return leftSumWithParent;
  }
  else {
    if (root->val > rightSumWithParent) {
      return root->val;
    }    
    return rightSumWithParent;
  }

}

int maxPathSum(struct TreeNode* root) {
  maxSum = INT_MIN;
  sumDfs(root);
  return maxSum;
}

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

int main() {
  // struct TreeNode *root = create_root(-10);
  // insert_element(root, 9);
  // insert_element(root, 20);
  // insert_element(root, 7);
  // insert_element(root, 15);
  // insert_element(root, -15);

  struct TreeNode *root = create_root(9);
  struct TreeNode *left, *right;
  insert_left(root, 6);
  right = insert_right(root, -3);
  insert_left(right, -6);
  right = insert_right(right, 2);
  left = insert_left(right, 2);
  insert_right(left, -6);
  left = insert_left(left, -6);
  left = insert_left(left, -6);

  int result = maxPathSum(root);
  printf("%d", result);

  // pre_order(root);

}