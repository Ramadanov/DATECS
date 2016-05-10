#include<stdio.h>
#include <time.h>
#include "SortingHeader.h"




int main()
{

	int test=NULL;
	do
	{
		printf("Withc algoritam do you want to test:\n"
			"Insertion Sor	-> 1\n"
			"Selection Sort	-> 2\n"
			"Bubble Sort	-> 3\n"
			"Merge Sort	-> 4\n"
			"Quick Sort	-> 5\n");
		test = getchar();
		fseek(stdin, 0, SEEK_END);
	} while ((test-'0'<1)||( test - '0'>5));
	
	Testsort(test);
	
	getchar();
}



