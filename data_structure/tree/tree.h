typedef struct BinaryTreeNode
{
  int data;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode *right;
} Node;

Node* create_root(int);
void insert_element(Node*, int);
void pre_order(Node*);
void in_order(Node*);