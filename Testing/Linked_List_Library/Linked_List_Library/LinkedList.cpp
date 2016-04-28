#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"


int Length(struct NODE* head)
{
	struct NODE* newNode;
	newNode = head;

	int counter = 0;
	while (newNode != NULL)
	{
		counter++;
		newNode = newNode->next;
	}
	return counter;
}

void push(struct NODE* head, int data)
{
	List newNode = NULL;

	newNode->data = data;
	newNode->next = head;

	head = *newNode;
}

