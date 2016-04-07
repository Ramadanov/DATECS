#include <stdio.h>


int main()
{
	int lim = 5;
	int c;

	printf("Please inpute some line:\n");
	c = getchar();

	
//	printf("Print first %d symbols with * between them (from input):\n", lim-1);

	//printf("usein: 'for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)' :\n");
	/*
	printf("%c*", (char)c);
	for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)
	{
		printf("%c", (char)c);
		if ((c != '\n')&&(i < lim - 1))
		{
			printf("*");

		}
	}
*/

	printf(" usein: for (int i = 0;(i < lim - 1); ++i)\n");
	printf("{\n");
	printf("\tif (c = getchar() != (EOF)) :\n");
	printf("%c*", (char)c);
	for (int i = 0;(i < lim - 1); ++i)
	{
		c = getchar();
		if (c != (EOF))
		{
			printf("%c", (char)c);
			if (c != '\n')
			{
				if(i + 1 < lim - 1)
				{
					printf("*");
				}
			}
			
		}
		else
		{
			//break;
		}
	}
	getchar();
	return 0;
}
