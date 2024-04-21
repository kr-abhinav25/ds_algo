#include "tree.h"
#include <stdio.h>
#include <stdlib.h>  

Node* initialize_node() {
  Node* tmp = (Node*)malloc(sizeof(Node));
  return tmp;
}
Node* create_root(int data) {
  Node* tmp = initialize_node();
  tmp->data = data;
  tmp->right = NULL;
  tmp->left = NULL;
  return tmp;
}

void insert_element(Node* root, int data) {
  Node* tmp = root;
  Node* to_add = initialize_node();
  to_add->data = data;
  to_add->left = NULL;
  to_add->right = NULL;
  do
  {
    if(data <= tmp->data) {
      if (tmp->left == NULL) {
        tmp->left = to_add;
        break;
      }
      tmp = tmp->left;
    }
    else if (data > tmp->data)
    {
      if (tmp->right == NULL) {
        tmp->right = to_add;
        break;
      }      
      tmp = tmp->right;
    }
    
  }while(1==1);
}

void pre_order(Node* root) {
  if(root) {
    printf("%d\n", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }
}

void in_order(Node* root) {
  if(root) {
    pre_order(root->left);
    printf("%d\n", root->data);
    pre_order(root->right);
  }
}