#pragma once


struct NODE // declearing node sructure
{
	int data;
	struct NODE *next;
};

typedef NODE * List_nodes;




void Push(List_nodes *, int); //Adds a new node at the head of the list


void printList(List_nodes); // Print content

int Length(List_nodes);

List_nodes AddAtHead();

List_nodes BuildOneTwoThree();

//Testing:
void LengthTest();
void TestPush();


//List of functions:

int Count(List_nodes, int); // count of chousen valu in the data;		1)

int GetNth(List_nodes, int); //returns the value of chousen node;		2)

void DeleteList(List_nodes *); //delete list;							3)

int Pop(List_nodes *); //delete head and return it's data				4)

void InsertNth(List_nodes *, int, int); // insert element in list;		5)

void SortedInsert(List_nodes*, List_nodes); //insert Node in list		6)
