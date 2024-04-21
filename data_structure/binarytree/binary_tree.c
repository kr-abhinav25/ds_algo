#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>


Node* create_root(int data) {
  Node* root = (Node*)malloc(sizeof(Node));
  root->data = data;
  root->left = NULL;
  root->right = NULL;

  return root;
};

void insert_element(Node* root, int data) {
  Node* tmp = root;
  Node* item = (Node*)malloc(sizeof(Node));
  item->data = data;
  item->left = item->right = NULL;

  do
  {
    if(data <= tmp->data) {
      if (tmp->left == NULL) {
        tmp->left = item;
        break;
      }
      tmp = tmp->left;
    }
    else if (data > tmp->data)
    {
      if (tmp->right == NULL) {
        tmp->right = item;
        break;
      }      
      tmp = tmp->right;
    }
    
  }while(1==1);
  
  
};

void pre_order(Node* root){
  printf("%d\n", root->data);
  pre_order(root->left);
  pre_order(root->right);   
};

void in_order(Node* root){  
  if (root) {
    in_order(root->left);
    printf("%d\n", root->data);
    in_order(root->right);  
  }
}

void post_order(Node* root) {
  if (root) {
    post_order(root->left);
    post_order(root->right);  
    printf("%d\n", root->data);
  }
};