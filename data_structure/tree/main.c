#include "tree.h"

int main()
{

  Node* root = create_root(1);
  insert_element(root, 2);
  insert_element(root, 3);
  insert_element(root, 4);
  insert_element(root, 5);

  // pre_order(root);
  in_order(root);

 return 0;
}
