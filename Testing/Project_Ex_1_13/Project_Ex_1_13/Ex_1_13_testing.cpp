/**/
#include <stdio.h>

int main()
{

	int c; //, counte_words = 0; // - code from zad12
		   //	int nc, nw;
		   //int check_for_word;

	printf("Please write something: \n");
	c = getchar();

	//nc = nw = 0;
	while (c != EOF)
	{
		//	++nc;

		if ((c == ' ' || c == '\n' || c == '\t')) //checking for delimiter
		{
			putchar('\n');
			//check_for_word = 0; // nead to be addedn additiona check for double spacing and so...
			//++nw;
			//counte_words = counte_words + 1;
		}
		else
		{
			printf("*");
		}
		c = getchar();
		//break;
	}

	//printf("%d \n", counte_words); // - code from zad12
	//printf("%d %d\n", nw, nc); // - code from zad12
	getchar();
	return 0;

}

