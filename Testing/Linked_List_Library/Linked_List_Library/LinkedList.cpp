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

void DeleteNode(List_nodes *pnode)
{
	List_nodes temp = (*pnode)->next;
	(*pnode)->data = temp->data;
	(*pnode)->next = temp->next;

	free(temp);
}

int DestroyNode(List_nodes *head, int position)
{
	List_nodes tempNode = NULL;
	List_nodes newNode = NULL;
	newNode = *head;
	bool invalid = true;
	int counter = 0;

	while (newNode != NULL)
	{
		
		if (position == counter)
		{
			DeleteNode(&newNode);
			invalid = false;
		}
		counter++;
		newNode = newNode->next;
	}
	if (invalid)
	{
		printf("ERROR this node doesent exist!\n");
		return -1;
	}
}




//list of functions 1-18

int Count(List_nodes head, int searchFor)
{
	List_nodes newNode;
	newNode = head;

	int counter = 0;

	while (newNode != NULL)
	{
		if (newNode->data == searchFor)
		{
			counter++;
		}
		newNode = newNode->next;
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
	int temp;

	if (Newnode != NULL)
	{
		temp = (*headRef)->data;
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


	if ((*phead == NULL) || (index == 0))
	{
		Push(phead, data);
	}
	else
	{
		int counter = 0;
		List_nodes newNode = NULL;
		newNode = *phead;

		List_nodes addNode = NULL;
		addNode = (List_nodes)malloc(sizeof(struct NODE));
		addNode->data = data;
		addNode->next = NULL;



		while (newNode != NULL)
		{
			if (counter == index - 1)
			{
				addNode->next = newNode->next;
				newNode->next = addNode;
			}
			if (newNode->next != NULL)
			{
				newNode = newNode->next;
				counter++;
			}

			else
				break;
			
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
	tempNode = *headRef;

	int counter = 0;

	while (newNode->data > tempNode->data)
	{
		tempNode = tempNode->next;
		counter++;
	}
	InsertNth(headRef, counter, newNode->data);
}

void InsertSort(List_nodes* headRef)
{
	List_nodes tempNode = NULL;
	List_nodes tempNode2 = NULL;

	tempNode2 = (List_nodes)malloc(sizeof(struct NODE));
	tempNode = (*headRef)->next;

	while (tempNode != NULL)
	{
		
		if (tempNode->data < (*headRef)->data)
		{
			tempNode2->data = tempNode->data;
			DeleteNode(&tempNode);
			SortedInsert(headRef, tempNode2);
		}
		else
		{
			tempNode = tempNode->next;
		}
	}
}
void Append(List_nodes* aRef, List_nodes* bRef)
{
	List_nodes tempNode = NULL;
	tempNode = (List_nodes)malloc(sizeof(struct NODE));
	tempNode = *aRef;
	while (tempNode->next != NULL)
	{

		tempNode = tempNode->next;
	}
	tempNode->next = *bRef;
}
void FrontBackSplit(List_nodes source, List_nodes* frontRef, List_nodes* backRef)
{
	int lenght_source = NULL;
	List_nodes temmpNode = NULL;
	int conter = 0;
	
	temmpNode = source;
	*frontRef = source;
	lenght_source = Length(source);
	lenght_source = (lenght_source / 2) + (lenght_source % 2);
	printf("length /2 :%d\n", lenght_source);
	

	while (conter < lenght_source - 1)
	{
		temmpNode = temmpNode->next;
		conter++;
		
	}
	*backRef = temmpNode->next;
	temmpNode->next = NULL;

}

void RemoveDuplicates(List_nodes head)
{
	List_nodes tempNode = NULL;
	tempNode = head;
	while (tempNode->next != NULL)
	{
		if (tempNode->data == tempNode->next->data)
		{
			DeleteNode(&tempNode);
		}
		else
		{
			tempNode = tempNode->next;
		}
	}
}
void MoveNode(List_nodes* destRef, List_nodes* sourceRef)
{
	//List_nodes temp = NULL;
	//temp = *sourceRef;
	
	Push(destRef, Pop(sourceRef));


}

void AlternatingSplit(List_nodes source, List_nodes* aRef, List_nodes* bRef)
{
	List_nodes tempNode = NULL;
	tempNode = source;
	int current_data;

	while (tempNode != NULL)
	{
		current_data = tempNode->data;
		tempNode = tempNode->next;

		if (current_data % 2 == 0)
		{
			Push(aRef, current_data);
		}
		else
		{
			Push(bRef, current_data);
		}

	}
}

List_nodes ShuffleMerge(List_nodes first, List_nodes second)
{
	
	List_nodes head = NULL;
	head = (List_nodes)malloc(sizeof(struct NODE));

	List_nodes *temp = NULL;
	temp = &head;
	//head->next = NULL;

	while (true)
	{
		if (first)
		{
			Push(temp, Pop(&first));
			if (!(first || second))
			{
				break;
			}
			temp = &(*temp)->next;	
		}

		if (second)
		{
			
			Push(temp, Pop(&second));
			if (!(first || second))
			{
				break;
			}
			temp = &(*temp)->next;
		}

	}
	(*temp)->next = NULL;

	return head;
}

List_nodes SortedMerge(List_nodes first, List_nodes second)
{
	List_nodes head = NULL;
	head = (List_nodes)malloc(sizeof(struct NODE));

	List_nodes *temp = NULL;
	temp = &head;

	List_nodes *temp_f = &first;
	List_nodes *temp_s = &second;
	//List_nodes *temp = NULL;
	//temp = &head;
	while((*temp_f != NULL) || (*temp_s != NULL))
	{
		if ((*temp_f)&&(((*temp_f)->data) < ((*temp_s)->data)))
		{
			Push(temp, (*temp_f)->data);
			if (&(*temp_s) != NULL)
			{
				temp_f = &(*temp_f)->next;
			}
		}
		else if(*temp_s)
		{
			Push(temp, (*temp_s)->data);
			if  (&(*temp_s)->next != NULL)
			{
				temp_s = &(*temp_s)->next;
			}
		}
		//if ((*temp_f == NULL) && (*temp_s == NULL))
		{
			//break;
		}
		if (!(*temp_f || *temp_s))
		{
			break;
		}
		temp = &(*temp)->next;
	}
	(*temp)->next = NULL;

	return head;
}

//FrontBackSplit() and SortedMerge()

void MergeSort(List_nodes *headRef)
{
	List_nodes temp = NULL;
	List_nodes temp_f = NULL;
	List_nodes temp_s = NULL;
	temp = *headRef;
	
	if ((!(temp->next))||(!(temp)))
	{
		return;
	}

	FrontBackSplit(temp, &temp_f, &temp_s);
	
	
		MergeSort(&temp_f);
	
		MergeSort(&temp_s);

	
	temp =SortedMerge(temp_f, temp_s);
	
}
/*
struct node* head = *headRef;
struct node* a;
struct node* b;
// Base case -- length 0 or 1
if ((head == NULL) || (head->next == NULL)) {
	return;
}
FrontBackSplit(head, &a, &b);
// Split head into 'a' and 'b' sublists
// We could just as well use AlternatingSplit()
MergeSort(&a);
// Recursively sort the sublists
MergeSort(&b);
*headRef = SortedMerge(a, b);
*/