#include "tree.h"
#include "stacks_linked.h"

int main()
{

  Node* root = create_root(1);
  insert_element(root, 2);
  insert_element(root, 3);
  insert_element(root, 4);
  insert_element(root, 5);
  insert_element(root, 6);
  insert_element(root, 7);


  // pre_order(root);
  non_recursive_preorder_traversal(root);

 return 0;
}
