#include <stdio.h>


int main()
{	
	int lim = 100;	//limit for input symbols
	int c;	//for old logic
	int c1;		//for new logic

	/*
	printf("Inpute limit:\n");		//logig for input from keyboard;
	lim = getchar();
	lim = (lim - '0');
	lim++;
	*/



	printf("\nPrint first %d symbols with * between them (from input):\n\n", lim  - 1);

	
/*
	//***********************old logic***************************
	printf("usein: 'for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)' :\n");
	
	printf("Please inpute some line:\n");
	
	c = getchar();
	
	//printf("%c*", (char)c);
	for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)
	{
		printf("%c", (char)c);
		if ((c != '\n')&&(i < lim - 1))
		{
			printf("*");

		}
	}
	//***********************************************************
*/



	//***************8*******new logic***************************

	printf(" usein: for (int i = 0;(i < lim - 1); ++i)\n");
	printf("{\n");
	printf("\tif (c = getchar() != (EOF)) :\n\n\t\t");

	printf("Please inpute some line:\n");
	c1 = getchar();
	//printf("%c*", (char)c);
	for (int i = 0;(i < lim - 1); i++)
	{
		if (c1 != (EOF))
		{
			printf("%c", (char)c1);
			c1 = getchar();
			if (c1 != '\n')
			{
				if (i < lim - 1)
				{
					printf("*");
				}
			}
			else
			{
				printf("\n");
				break;
			}

		}
		else
		{
			printf("\n");
			break;
		}

	}
	//***********************************************************

	getchar();
	return 0;
}
