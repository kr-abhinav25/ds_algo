#include <stdio.h>
#include <stdlib.h>  

typedef struct Node
{
   int data;
   struct Node* next;
} Node;


Node* initialize_node() {
   Node* node = (Node*)malloc(sizeof(Node));
   return node;
}

Node* create_head(int val) {
   Node* node = initialize_node();
   node->data = val;
   node->next = NULL;
   return node;
}

Node* create_list(int val) {
   return create_head(val);
}

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

void add_element(Node* head, int val, int pos) {
   if (pos == -1)
   insert_at_end(head, val);
}

void print_list(Node* head) {
   Node* tmp = head;
   while (tmp != NULL)
   {
      printf("%d\n", tmp->data);
      tmp = tmp->next;
   }   
}

int main() {
  Node* l1 = create_list(2);
  add_element(l1, 6, -1);
  add_element(l1, 4, -1);
  print_list(l1);
  print_list(l1);

 return 0;

}
