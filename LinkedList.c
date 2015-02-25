#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

struct Node *newList(void)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode != NULL)
		newNode->next = NULL;
	return newNode;
}

struct Node *delete(struct Node *prev)
{
	struct Node *nextNode = prev->next;
	if (nextNode == NULL)
		return NULL;

	prev->next = nextNode->next;
	nextNode->next = NULL;
	return nextNode;
}

struct Node *insert(struct Node *prev, void *data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = prev->next;
		prev->next = newNode;
	}
	return newNode;
}

int length(struct Node *head)
{
	struct Node *curr = head;
	int len = 0;
	while (curr->next != NULL) {
		len++;
		curr = curr->next;
	}
	return len;
}

void printList(struct Node *head)
{
	struct Node *curr = head->next;
	while (curr != NULL) {
		printData(curr->data);
		printf(" ");
		curr = curr->next;
	}
	printf("\n");
}

struct Node *getNode(struct Node *head, int i)
{
	struct Node *curr = head;
	while (i > 0 && curr != NULL) {
		curr = curr->next;
		i--;
	}
	return curr;
}

void deleteList(struct Node *head)
{
	struct Node *deleted;
	while (length(head) > 0) {
		deleted = delete(head);
		free(deleted->data);
		free(deleted);
	}
	free(head);
}
