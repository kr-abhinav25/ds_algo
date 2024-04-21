typedef struct binaryTree
{
  int data;
  struct binaryTree* left;
  struct binaryTree* right;
}Node;

Node* create_root(int);
void insert_element(Node*, int);
void pre_order(Node*);
void in_order(Node*);
void post_order(Node*);