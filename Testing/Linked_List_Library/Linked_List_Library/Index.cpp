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
	Push(&Newnode, 66);
	Push(&Newnode, 66);
	Push(&Newnode, 65);
	Push(&Newnode, 64);
	Push(&Newnode, 63);
	Push(&Newnode, 32);

	List_nodes node2 = NULL;
	Push(&node2, 4);

	SortedInsert(&Newnode, node2);
	printf("Insert existing node in sorted llist:\n");
	printList(Newnode);
	
	printf("Delete node:\n");
	DestroyNode(&Newnode, 2); //destroy is under testing!!!!!!!
	printList(Newnode);
	
	Push(&Newnode, 70);
	Push(&Newnode, 71);
	Push(&Newnode, 72);
	Push(&Newnode, 73);

	
	printList(Newnode);
	printf("Sorting a list of nodes:\n"); 
	InsertSort(&Newnode);	 //InsertSort is under testing!!!!!!!!
	printList(Newnode);

	Push(&node2, 5);
	Push(&node2, 6);

	printList(node2);
	printList(Newnode);
	printf("Append 2 nodes:\n");
	Append(&Newnode, &node2);
	printList(Newnode);

	
	List_nodes frontRef = NULL;
	List_nodes backRef = NULL;
	Push(&Newnode, 66);

	FrontBackSplit(Newnode, &frontRef, &backRef);
	printf("front list:\n");
	printList(frontRef);
	printf("back list:\n");
	printList(backRef);

	printList(backRef);
	printf("remove duplicates:\n");
	RemoveDuplicates(backRef);
	printList(backRef);
	//printList(Newnode);


	printf("old lists:\n");
	printList(frontRef);
	printList(backRef);
	printf("pop first element in second list toand push into first list:\n");
	MoveNode(&frontRef, &backRef);
	printList(frontRef);

	Append(&Newnode, &backRef);
	List_nodes even = NULL;
	List_nodes odd = NULL;

	printf("Current lists:\n");
	printList(Newnode);
	AlternatingSplit(Newnode, &even, &odd);
	printf("even lists:\n");
	printList(even);
	printf("odd lists:\n");
	printList(odd);

	DeleteList(&Newnode);
	printf("before ShuffleMerge:\n");
	printList(Newnode);

	printf("even lists:\n");
	printList(even);
	printf("odd lists:\n");
	printList(odd);

	//InsertNth(&Newnode, 2, 55);
	Newnode = ShuffleMerge(even, odd);
	printf("after ShuffleMerge:\n");
	printList(Newnode);
	



	getchar();
	return 0;
}