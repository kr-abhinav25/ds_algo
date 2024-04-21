#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>  

Node* initialize_node() {
   Node* node = (Node*)malloc(sizeof(Node));
   return node;
}

Node* create_list(int val) {
   return create_head(val);
}

Node* create_head(int val) {
   Node* node = initialize_node();
   node->data = val;
   node->next = NULL;
   return node;
}

void add_element(Node* head, int val, int pos) {
   if (pos == -1)
   insert_at_end(head, val);
}
// void create_head(Node* node, int val) {
//    node->data = val;
//    node->next = NULL;
//    head = node;
// }

void insert_at_end(Node* head, int val) {
   Node* tmp = head;
   while (tmp->next != NULL)
   {
      tmp = tmp->next;
   }
   
   Node* node = initialize_node();
   node->data = val;
   node->next = NULL;
   tmp->next = node;
}

void print_list(Node* head) {
   Node* tmp = head;
   while (tmp != NULL)
   {
      printf("%d\n", tmp->data);
      tmp = tmp->next;
   }   
}

void add(Node* l1, Node* l2){

   Node* tmp1 = l1;
   Node* tmp2 = l2;
   Node* sum_node;
   int carry_over = 0;
   int count = 0;
   int sum = 0;
   Node* array_to_return;
   Node* pp;
   Node* xx;
   Node* yy;

   while ((tmp1 != NULL) && (tmp2 != NULL))
   {
      sum = tmp1->data + tmp2->data + carry_over;
      carry_over = 0;
      if (sum > 9) {
         int val = sum%10;
         tmp1->data = val;
         tmp2->data = val;
         carry_over = sum/10;
      }
      else {
         tmp1->data = sum;
         tmp2->data = sum;
      }
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
   }
   if(tmp1 == NULL) {
      array_to_return = tmp2;
      xx = l2;
      yy=l1;
   }
   else {
      array_to_return = tmp1;
      xx = l1;
      yy=l2;

   }
   while (array_to_return != NULL) {
      sum = array_to_return->data + carry_over;
      carry_over = 0;
      if (sum > 9) {
         int val = sum%10;
         array_to_return->data = val;
         carry_over = sum/10;
      }
      else {
         array_to_return->data = sum;
      }
      if (array_to_return->next == NULL)
      {
        if (carry_over > 0) {
            yy->data = carry_over;
            yy->next = NULL;
            array_to_return->next = yy;
            carry_over = 0;
        }
        break;
      }
      array_to_return = array_to_return->next;
   }
      if (carry_over > 0) {
         Node* tmp = xx;
         while (tmp->next != NULL)
         {
            tmp = tmp->next;
         }
         
            yy->data = carry_over;
            yy->next = NULL;
            tmp->next = yy;
            carry_over = 0;
        }
   print_list(xx);
   
}
// void add(Node* l1, Node* l2){
//   Node* tmp = l1;
//   int num1 = 0;
//   int num2 = 0;
//   int tenth_counter = 1;
//   do {
//     num1 = num1 + (tmp->data * tenth_counter);
//     tenth_counter = tenth_counter * 10;
//     tmp = tmp->next;
//   }
//   while(tmp != NULL);

//    tenth_counter = 1;

//   do {
//     num2 = num2 + (tmp->data * tenth_counter);
//     tenth_counter = tenth_counter * 10;
//     tmp = tmp->next;
//   }
//   while(tmp != NULL);
//   printf("%d\n", num2);

//   int sum = num1 + num2;

//    Node* head

//   while (sum > 0)
//   {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->data = sum%10;
//    node->next = NULL;
//   }
  
// }