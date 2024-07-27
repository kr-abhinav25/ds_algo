// https://leetcode.com/problems/path-sum/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool checkSum(struct TreeNode* root, int targetSum) {
  if (root->left == NULL && root->right == NULL) {
    if (targetSum - root->val == 0)
      return true;

    return false;
  }
  
  int reducedTarget = targetSum - root->val;
  if (root->left != NULL && checkSum(root->left, reducedTarget))
    return true;

  if (root->right != NULL && checkSum(root->right, reducedTarget))
    return true;

  return false;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
  if (root == NULL)
    return false;

  // This special check is there coz fuckIng Leetcode is retarded.
  //  Tree [1,2] with target 1 is false but Tree[1] with
  // target 1 is true. Fucking retards, make up your mind if leaf
  // nodes should be included or not
  if (root->left == NULL && root->right == NULL && root->val - targetSum == 0)
    return true;  


  if ((root->left != NULL) && checkSum(root->left, targetSum - root->val) == true)
    return true;

  if ((root->right != NULL) && checkSum(root->right, targetSum - root->val) == true)
    return true;

  return false;
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

  struct TreeNode *root = create_root(5);
  left = insert_left(root, 4);
  left = insert_left(left, 11);
  insert_left(left, 7);
  right = insert_right(left, 2);
  right = insert_right(root, 8);
  insert_left(right, 13);
  right = insert_right(right, 4);
  insert_right(right, 1);
  printf("1: %d\n", hasPathSum(root, 22));

  struct TreeNode *root1 = create_root(1);
  left = insert_left(root1, 2);
  printf("0: %d\n", hasPathSum(root1, 1));

  struct TreeNode *root2 = create_root(1);
  left = insert_left(root2, 2);
  left = insert_left(left, 3);
  left = insert_left(left, 4);
  left = insert_left(left, 5);
  // pre_order(root2);
  printf("0: %d\n", hasPathSum(root2, 6));

    struct TreeNode *root3 = create_root(1);
  left = insert_left(root3, -2);
  insert_right(left, 3);
  left = insert_left(left, 1);
  insert_left(left, -1);
  right = insert_right(root3, -3);
  insert_left(right, -2);
  printf("1: %d\n", hasPathSum(root3, -1));



}