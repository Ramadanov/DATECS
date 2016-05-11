#include <stdio.h>
#include "LinkedList.h"
#include<stdlib.h>

int main()
{

	List_nodes Newnode = NULL;
	
	Newnode = AddAtHead();

	Push(&Newnode, 6);
	Push(&Newnode, 6);

	printList(Newnode);

	printf("\n=================================================================\n\n");

	printf("\nCount of nodes %d;\n", Length(Newnode));
	printList(Newnode);
	
	printf("\n=================================================================\n\n");

	printf("Count of '6' in data: %d;\n", Count(Newnode, 6));
	printList(Newnode);

	printf("\n=================================================================\n\n");

	printf("Node '2'-data: %d;\n", GetNth(Newnode, 2));
	printList(Newnode);

	printf("\n=================================================================\n\n");
	//DeleteList(&Newnode);
	
	printf("Count of nodes %d;\n", Length(Newnode));
	printList(Newnode);
	
	DeleteList(&Newnode); //clear Newnode;
	printList(Newnode);

	printf("\n=================================================================\n\n");


	//Newnode = AddAtHead();
	Push(&Newnode, 3);
	Push(&Newnode, 3);
	Push(&Newnode, 3);
	printList(Newnode);
	printf("Pop head of structure %d;\n", Pop(&Newnode));
	printList(Newnode);
	//*
	printf("\n=================================================================\n\n");


	printf("Insert element in 2nd position (starting from 0):\n");
	InsertNth(&Newnode, 2, 55);
	printList(Newnode);

	
	DeleteList(&Newnode); //clear Newnode
	//*
	printf("\n=================================================================\n\n");

	Push(&Newnode, 66);
	Push(&Newnode, 66);
	Push(&Newnode, 66);
	Push(&Newnode, 65);
	Push(&Newnode, 64);
	Push(&Newnode, 63);
	Push(&Newnode, 32);

	List_nodes node2 = NULL;
	Push(&node2, 4);

	printf("Insert existing node:\n");
	printList(node2);
	printf("in sorted llist:\n");
	printList(Newnode);
	SortedInsert(&Newnode, node2);
		
	printf("in sorted llist:\n");
	printList(Newnode);

	
	printf("\n=================================================================\n\n");
	
	printList(Newnode);
	int position = 2;
	printf("Delete node in %d position (starting from 0):\n", position);
	DestroyNode(&Newnode, position); //destroy is under testing!!!!!!!
	printList(Newnode);
	
	//*
	printf("\n=================================================================\n\n");
	
	Push(&Newnode, 70);
	Push(&Newnode, 71);
	Push(&Newnode, 72);
	Push(&Newnode, 73);

	
	printList(Newnode);
	printf("Sorting a list of nodes:\n"); 
	InsertSort(&Newnode);	 //InsertSort is under testing!!!!!!!!
	printList(Newnode);

	printf("\n=================================================================\n\n");

	Push(&node2, 5);
	Push(&node2, 6);

	
	printList(Newnode);
	printList(node2);

	printf("Append 2 nodes:\n");
	Append(&Newnode, &node2);
	printList(Newnode);

	DeleteList(&Newnode); //clear Newnode
	
	
	

	//*
	printf("\n=================================================================\n\n");


	List_nodes frontRef = NULL;
	List_nodes backRef = NULL;
	Push(&Newnode, 66);
	Push(&Newnode, 66);
	Push(&Newnode, 66);
	Push(&Newnode, 65);
	Push(&Newnode, 64);
	Push(&Newnode, 63);
	Push(&Newnode, 32);
	Push(&Newnode, 66);
	Push(&Newnode, 0);

	printList(Newnode);
	FrontBackSplit(Newnode, &frontRef, &backRef);
	printf("front list:\n");
	printList(frontRef);
	printf("back list:\n");
	printList(backRef);

	DeleteList(&Newnode);
	frontRef=NULL;

	//*
	printf("\n=================================================================\n\n");

	printList(backRef);
	printf("remove duplicates:\n");
	RemoveDuplicates(backRef);
	printList(backRef);
	
	printf("\n=================================================================\n\n");

	printf("old lists:\n");
	Push(&frontRef,0);
	printList(frontRef);
	printList(backRef);
	printf("pop first element in second list toand push into first list:\n");
	MoveNode(&frontRef, &backRef);
	printList(frontRef);
	printList(backRef);
	//*
	DeleteList(&frontRef); //clear frontRef
	DeleteList(&Newnode);	//clear 
	printf("\n=================================================================\n\n");
	
	Push(&Newnode, 17);
	Push(&Newnode, 18);
	Push(&Newnode, 18);
	printList(Newnode);
	printList(backRef);
	printf("Append second list into first list:\n");
	Append(&Newnode, &backRef);
	printList(Newnode);

	DeleteList(&Newnode);//cleaning lists :)
	//*
	printf("\n=================================================================\n\n");

	
	List_nodes even = NULL;
	List_nodes odd = NULL;
	Newnode = AddAtHead();


	printf("Current lists:\n");
	printList(Newnode);
	AlternatingSplit(Newnode, &even, &odd);
	printf("even lists:\n");
	printList(even);
	printf("odd lists:\n");
	printList(odd);
	//*

	printf("\n=================================================================\n\n");
	//******13 — ShuffleMerge()
	

	DeleteList(&Newnode);
	printf("before ShuffleMerge should be empty:\n");
	printList(Newnode);

	printf("first lists:\n");
	printList(even);
	printf("second lists:\n");
	printList(odd);

	//InsertNth(&Newnode, 2, 55);
	Newnode = ShuffleMerge(even, odd);
	printf("after ShuffleMerge:\n");
	printList(Newnode);	

	DeleteList(&Newnode);
	even = NULL; //check later
	odd = NULL; //check later
	printf("after ShuffleMerge:\n");
	//*
	printf("\n=================================================================\n\n");
	//******14 — SortedMerge()

	
	List_nodes first = NULL;
	List_nodes second = NULL;



	Push(&first, 14);
	Push(&first, 9);
	Push(&first, 7);
	Push(&first, 7);
	Push(&first, 5);
	Push(&first, 1);
	Push(&first, 0);

	Push(&second, 16);
	Push(&second, 9);
	Push(&second, 6);
	Push(&second, 6);
	Push(&second, 2);
	
	
	printf("first list:\n");
	printList(first);
	printf("second list:\n");
	printList(second);

	List_nodes sorted_list = NULL;

	sorted_list = SortedMerge(first, second); //need update

	printf("ordered list:\n");
	printList(sorted_list);
	
	

	
	DeleteList(&sorted_list);
	second = NULL;//check later
	first = NULL;//check later

	//
	printf("\n=================================================================\n\n");
	//******15 — MergeSort()

	Push(&Newnode, 14);
	Push(&Newnode, 9);
	Push(&Newnode, 7);
	Push(&Newnode, 17);
	Push(&Newnode, 51);
	Push(&Newnode, 1);
	Push(&Newnode, 0);
	Push(&Newnode, 16);

	printf("shuffled list:\n");
	printList(Newnode);
	MergeSort(&Newnode);
	printf("after MergeSort:\n");
	printList(Newnode);

	
	
	printf("\n=================================================================\n\n");

	//16 — SortedIntersect()

	Push(&first, 14);
	Push(&first, 9);
	Push(&first, 9);
	Push(&first, 3);
	Push(&first, 1);

	Push(&second, 14);
	Push(&second, 13);
	Push(&second, 9);
	Push(&second, 9);
	Push(&second, 5);
	Push(&second, 5); 
	Push(&second, 4); 
	Push(&second, 3);

	printf("first list:\n");
	printList(first);
	printf("second list:\n");
	printList(second);

//	List_nodes sorted_list = NULL;

	sorted_list  = SortedIntersect(first, second);
	printf("first list:\n");
	printList(sorted_list);

	printf("first list:\n");
	printList(first);
	printf("second list:\n");
	printList(second);
	DeleteList(&first);
	DeleteList(&second);

	printf("\n=================================================================\n\n");

	printf("before:\n");
	printList(sorted_list);
	Reverse(&sorted_list);
	printf("reverse list:\n");
	printList(sorted_list);

	printf("\n=================================================================\n\n");
	
	printf("before:\n");
	printList(sorted_list);
	RecursiveReverse(&sorted_list);
	printf("reverse list:\n");
	printList(sorted_list);

	getchar();
	return 0;
}