#pragma once


struct NODE // declearing node sructure
{
	int data;
	struct NODE *next;
};

typedef NODE * List_nodes;




void Push(List_nodes *, int); //Adds a new node at the head of the list;
void DeleteNode(List_nodes *); //delete node by pointer;
int DestroyNode(List_nodes *, int); //delete node from list with position;
void ChangeToNull(List_nodes *);
void printList(List_nodes); // Print content

int Length(List_nodes);

List_nodes AddAtHead();

List_nodes BuildOneTwoThree();



//Testing:
void LengthTest();
void TestPush();


//List of functions:

int Count(List_nodes, int); // count of chousen valu in the data;				1)

int GetNth(List_nodes, int); //returns the value of chousen node;				2)

void DeleteList(List_nodes *); //delete list;									3)

int Pop(List_nodes *); //delete head and return it's data						4)

void InsertNth(List_nodes *, int, int); // insert element in list;				5)

void SortedInsert(List_nodes*, List_nodes); //insert Node in list				6)

void InsertSort(List_nodes* headRef);	//sorteing - increasing order			7)

void Append(List_nodes*, List_nodes*); //append nodes							8)

void FrontBackSplit(List_nodes, List_nodes*, List_nodes*); //split list			9)

void RemoveDuplicates(List_nodes);		//remove duplicates						10)

void MoveNode(List_nodes*, List_nodes*);		//pop first node				11)

void AlternatingSplit(List_nodes, List_nodes*, List_nodes*);// splite by rule	12)

List_nodes ShuffleMerge(List_nodes, List_nodes); //shuffle marge				13)

List_nodes SortedMerge(List_nodes, List_nodes); //sorted marge					14)
		List_nodes SortedMerge_2(List_nodes, List_nodes);// extra try 

void MergeSort(List_nodes*);		//marge sort								15)

List_nodes SortedIntersect(List_nodes, List_nodes);		//						16)

void Reverse(List_nodes*);		//												17)

void RecursiveReverse(List_nodes*);		//										18)
