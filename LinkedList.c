#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

Node *newList(void)
{
  Node *newNode = malloc(sizeof(Node));
  if (newNode != NULL)
    newNode->next = NULL;
  return newNode;
}

Node *delete(Node *prev)
{
  Node *nextNode = prev->next;
  if (nextNode == NULL)
    return NULL;

  prev->next = nextNode->next;
  nextNode->next = NULL;
  return nextNode;
}

Node *insert(Node *prev, void *data)
{
  Node *newNode = malloc(sizeof(Node));
  if (newNode != NULL)
  {
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
  }
  return newNode;
}

int length(Node *head)
{
  Node *curr = head;
  int len = 0;
  while (curr->next != NULL) 
  {
    len++;
    curr = curr->next;
  }
  return len;
}

void printList(Node *head)
{
  Node *curr = head->next;
  while (curr != NULL)
  {
    printData(curr->data);
    printf(" ");
    curr = curr->next;
  }
  printf("\n");
}

Node *getNode(Node *head, int i)
{
  Node *curr = head;
  while (i > 0 && curr != NULL)
  {
    curr = curr->next;
    i--;
  }
  return curr;
}

void deleteList(Node *head)
{
  Node *deleted;
  while (length(head) > 0)
  {
    deleted = delete(head);
    free(deleted->data);
    free(deleted);
  }
  free(head);
}
