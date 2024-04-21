#include "binary_tree.h"

int main()
{

  Node* root = create_root(150);
  insert_element(root, 100);
  insert_element(root, 200);
  insert_element(root, 40);
  insert_element(root, 125);
  insert_element(root, 151);
  insert_element(root, 250);

  // pre_order(root);
  in_order(root);

 return 0;
}
