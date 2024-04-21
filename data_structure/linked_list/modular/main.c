#include "linked_list.h"

int main()
{

  Node* l1 = create_list(2);
 add_element(l1, 4, -1);
 add_element(l1, 3, -1);

  Node* l2 = create_list(5);
 add_element(l2, 6, -1);
 add_element(l2, 4, -1);
 print_list(l1);
 print_list(l2);

 return 0;
}