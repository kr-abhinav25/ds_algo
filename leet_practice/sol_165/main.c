// https://leetcode.com/problems/middle-of-the-linked-list/

#include "linked_list.h"

int main()
{

  Node* l1 = create_list(1);
 add_element(l1, 2, -1);
 add_element(l1, 3, -1);
//  add_element(l1, 4, -1);
//  add_element(l1, 5, -1);
//  add_element(l1, 6, -1);

//  print_list(l1);
//  print_list(rr);
Node* half = middleNode(l1);
 print_list(half);

 return 0;
}