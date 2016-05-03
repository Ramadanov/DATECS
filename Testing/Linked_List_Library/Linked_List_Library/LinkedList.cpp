#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"


int Length(List_nodes head) //
{
	List_nodes newNode = NULL;
	newNode = head;

	int counter = 0;

	while (newNode != NULL)
	{
		counter++;
		newNode = newNode->next;
	}
	return counter;
}

void Push(List_nodes *phead, int data)
{
	List_nodes newNode = NULL;

	newNode = (List_nodes)malloc(sizeof(struct NODE));

	newNode->next = *phead;
	newNode->data = data;
	 // The '*' to dereferences back to the real head
	*phead = newNode;
}

void printList(List_nodes node)
{

	printf("List of Nodes:\t");
	while (node != NULL) //go through nodes
	{
		printf(" %d ", node->data);//print current node
		
		node = node->next; //go to next node
	}
	printf("\n\n");
}


List_nodes BuildOneTwoThree()
{
	List_nodes head = NULL;
	//struct NODE* second = NULL;
	//struct NODE* third = NULL;

	Push(&head, 1); // push 1 to head
	Push(&head, 2); // push 2 to head
	Push(&head, 3); // push 3 to head


	//head = malloc(sizeof(struct NODE)); // allocate 3 nodes in the heap
	//second = malloc(sizeof(struct NODE));
	//third = malloc(sizeof(struct NODE));

	//head->data = 1; // setup first node
	//head->next = second; // note: pointer assignment rule
	//second->data = 2; // setup second node
	//->next = third;
	//third->data = 3; // setup third link
	//third->next = NULL;
	// At this point, the linked list referenced by "head"
	// matches the list in the drawing.

	return head;

}

void ChangeToNull(List_nodes* headRef) { // Takes a pointer to
										   // the value of interest
	*headRef = NULL; // use '*' to access the value of interest
}

List_nodes AddAtHead() {
	struct NODE* head = NULL;
	int i;
	for (i = 1; i<6; i++) {
		Push(&head, i);
	}
	// head == {5, 4, 3, 2, 1};
	return(head);
}

void LengthTest() 
{
	List_nodes head = BuildOneTwoThree();
	int len = Length(head);
	// results in len == 3
}

void TestPush() 
{
	List_nodes head = BuildOneTwoThree();//returns the list {1, 2, 3}
	Push(&head, 1); 
	Push(&head, 13);
	//expecting:	13, 1, 1, 2, 3;
}


int Count(List_nodes head, int searchFor)
{
	//List_nodes newNode;
	//newNode = head;

	int counter = 0;

	while (head != NULL)
	{
		if (head->data == searchFor)
		{
			counter++;
		}
		head = head->next;
	}
	return counter;
}


int GetNth(List_nodes head, int index) 
{
	int counter = 0;
	
	while(head != NULL)
	{
		if (counter != index)
		{
			head = head->next;
			counter++;
		}
		else
		{
			return head->data;
		}
	}
	return -1;
}

void DeleteList(List_nodes *phead)
{
	List_nodes Newnode = NULL;
	Newnode = *phead;

	while (Newnode != NULL)
	{
		*phead=Newnode->next;
		free(Newnode);
		Newnode = *phead;
	}

	ChangeToNull(phead);
}

int Pop(List_nodes* headRef)
{
	List_nodes Newnode = NULL;
	Newnode = *headRef;
	int temp =(*headRef)->data;

	if (Newnode != NULL)
	{
		*headRef = Newnode->next;
		free(Newnode);
		Newnode = *headRef;
		return temp;
	}
	else 
	{
		printf("FAIL Structure is empty");
		return -1;
	}
	
	//return Newnode;//temp 0 - to be changed
}

void InsertNth(List_nodes* phead, int index, int data)
{

	int counter = 0;
	List_nodes newNode = NULL;
	newNode = *phead;

	List_nodes addNode = NULL;
	addNode = (List_nodes)malloc(sizeof(struct NODE));
	addNode->data = data;
	addNode->next = NULL;



	//newNode->data = data;
	if (index == 0)
	{
		Push(phead, data);
	}
	else
	{
		while (newNode != NULL)
		{
			if (counter == index - 1)
			{
				addNode->next = newNode->next;
				//addNode->next=(*phead)->next;
				newNode->next = addNode;
				//(*phead)->next = addNode;
				//Push(&newNode, data);
				//(*phead)->next = addNode;*/
				break;
			}
			//(*phead) = (*phead)->next;
			newNode = newNode->next;
			counter++;
		}
		if (newNode == NULL)
		{
			printf("there is no such ellement:!!!!!!!!\n");
		
		}
	}
}

void SortedInsert(List_nodes* headRef, List_nodes newNode)
{
	List_nodes tempNode = NULL;
	//tempNode = (List_nodes)malloc(sizeof(struct NODE));
	tempNode = *headRef;

	int counter = 0;

	while (newNode->data > tempNode->data)
	{
		tempNode = tempNode->next;
		counter++;
	}
	newNode->next = tempNode->next;
	tempNode->next = newNode;

	//InsertNth(&tempNode, , newNode->data);
	//Push(&tempNode, newNode->data);

}