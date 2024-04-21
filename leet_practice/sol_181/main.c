// https://leetcode.com/problems/remove-linked-list-elements/
#include "linked_list.h"

int main()
{

  Node* l1 = create_list(7);
 add_element(l1, 6, -1);
 add_element(l1, 6, -1);
//  add_element(l1, 7, -1);
//  add_element(l1, 7, -1);
//  add_element(l1, 7, -1);
//  add_element(l1, 7, -1);
//  add_element(l1, 7, -1);

//  print_list(l1);
//  print_list(rr);
Node* half = removeElements(l1, 7);
 print_list(half);

 return 0;
}