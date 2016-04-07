#include <stdio.h>

int main()
{
	int c, count_words = 0;
	//	int nc, nw;
	//int check_for_word;

	//printf("\n%d\n", count_words);

	printf("Please write something: \n");
	c = getchar();

	//printf("\n%d\n", counte_words);
	//nc = nw = 0;
	while (c != EOF)
	{
		//	++nc;

		if ((c == ' ' || c == '\n' || c == '\t')) //checking for delimiter
		{
			putchar('\n');
			//check_for_word = 0; // nead to be addedn additiona check for double spacing and so...
			//++nw;
			count_words = count_words + 1;
		}
		else
		{
			putchar(c);
		}
		c = getchar();

	}

	printf("\n%d\n", count_words);
	//printf("%d %d\n", nw, nc);
	getchar();
	return 0;
}