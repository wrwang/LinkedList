struct Node {
    void *data;
    struct Node *next;
};

struct Node *newList(void);
struct Node *delete(struct Node *prev);
struct Node *insert(struct Node *prev, void *data);
int length(struct Node *head);
void printList(struct Node *head);
struct Node *getNode(struct Node *head, int i);
void deleteList(struct Node *head);
