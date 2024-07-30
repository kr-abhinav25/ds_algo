// https://leetcode.com/problems/validate-binary-search-tree/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

bool inOrderCheck(struct TreeNode* root, long *previousValue) {
  if (root == NULL)
    return true;

  bool leftCheck = inOrderCheck(root->left, previousValue);
  if (leftCheck && (long)root->val > *previousValue){
    *previousValue = root->val;
    bool rightCheck = inOrderCheck(root->right, previousValue);
    if (rightCheck)
      return true;
  }

  return false;
}

bool isValidBST(struct TreeNode* root) {
  long previousValue = LONG_MIN;
  return inOrderCheck(root, &previousValue);

}

// bool checkValid(struct TreeNode* root, int min, int max) {
//   if (root == NULL)
//     return true;

//   if (root->val > min && root->val < max) {
//     if (checkValid(root->left, min, root->val) && checkValid(root->right, root->val, max))
//       return true;
//   }
  
//   return false;

// }


// bool isValidBST(struct TreeNode* root) {
//   if (root->left == NULL && root->right == NULL)
//     return true;

//   return(checkValid(root, INT_MIN, INT_MAX));  
// }

int main() {

  struct TreeNode *root = create_root(-2147483648);
  insert_element(root, 2147483647);
  //  pre_order(root);

  printf("%d", isValidBST(root));

  // insert_element(root, 3);

  // struct TreeNode *left, *right;
  // struct TreeNode *root = create_root(5);
  // left = insert_left(root, 1);
  // right = insert_right(root, 4);
  // insert_left(right, 3);
  // left = insert_right(right,6);
  // // pre_order(root);

  // printf("%d", isValidBST(root));


}