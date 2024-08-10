// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
struct TreeNode* lcs(struct TreeNode* root, int low, int high) {
  if (low < root->val && high > root->val)
    return root;
  else if (low == root->val || high == root->val)
    return root;    
  else if (low > root->val && high > root->val)
    return lcs(root->right, low, high);
  else
    return lcs(root->left, low, high);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  if (p->val > q->val)
    return lcs(root, q->val, p->val);
  else
    return lcs(root, p->val, q->val);
}

int main() {

  struct TreeNode *root = create_root(6);
  struct TreeNode *q = insert_element(root, 2);
  insert_element(root, 0);
  struct TreeNode *p = insert_element(root, 4);
  insert_element(root, 3);
  insert_element(root, 5);
  insert_element(root, 8);
  insert_element(root, 7);
  insert_element(root, 9);

  // pre_order(root);

  printf("%d\n", lowestCommonAncestor(root, p, q)->val);

  struct TreeNode *root1 = create_root(2);
  struct TreeNode *q1 = insert_element(root1, 1);
  struct TreeNode *p1 = insert_element(root1, 3);
  printf("%d", lowestCommonAncestor(root1, p1, q1)->val);


}