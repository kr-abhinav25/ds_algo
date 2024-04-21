// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "linked_list.h"

int main()
{

  Node* l1 = create_list(1);
 add_element(l1, 2, -1);
 add_element(l1, 3, -1);
//  add_element(l1, 4, -1);
//  add_element(l1, 5, -1);
//  print_list(l1);
 Node* rr = removeNthFromEnd(l1, 3);
 print_list(rr);
 return 0;
}