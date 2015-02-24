typedef struct _Node
{
  void *data;
  struct _Node *next;
} Node;

Node *newList(void); //returns a head of a new empty list
Node *delete(Node *prev); // deletes the node after prev
Node *insert(Node *prev, void *data); // inserts a new node with data field data after prev
int length(Node *head); //number of elements in the list
void printList(Node *head); //print the data fields for the entire list
Node *getNode(Node *head, int i);
void deleteList(Node *head);
