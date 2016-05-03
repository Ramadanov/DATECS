#include <stdio.h>
#include "LinkedList.h"

int main()
{

	List_nodes Newnode = NULL;

	Newnode = AddAtHead();

	Push(&Newnode, 6);
	Push(&Newnode, 6);

	printList(Newnode);

	printf("\nCount of nodes %d;\n", Length(Newnode));
	printList(Newnode);

	printf("Count of '6' in data: %d;\n", Count(Newnode, 6));
	printList(Newnode);

	printf("Node '2'-data: %d;\n", GetNth(Newnode, 2));
	printList(Newnode);

	DeleteList(&Newnode);
	printf("Count of nodes %d;\n", Length(Newnode));
	printList(Newnode);

	Newnode = AddAtHead();
	printf("Pop head of structure %d;\n", Pop(&Newnode));
	printList(Newnode);

	printf("Insert element in 2nd position (starting from 0):\n");
	InsertNth(&Newnode, 2, 55);
	printList(Newnode);

	DeleteList(&Newnode);
	Push(&Newnode, 66);
	Push(&Newnode, 65);
	Push(&Newnode, 64);
	Push(&Newnode, 63);
	Push(&Newnode, 32);

	List_nodes node2 = NULL;
	Push(&node2, 44);

	SortedInsert(&Newnode, node2);
	printf("Insert existing node in list:\n");
	printList(Newnode);
	
	getchar();
	return 0;
}