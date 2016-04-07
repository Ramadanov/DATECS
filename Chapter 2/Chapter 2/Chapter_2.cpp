#include <stdio.h>

//optional scenarios:
void zadacha1_2(); //  Using 'OR', 'AND', 'NOT' instead of '||', '&&', '!='

int main()
{
	int Exercise;

		
	char testing = 'Y';
	while (testing == 'Y' || testing == 'y')
	{
		printf("Please choose one of the optional scenarios: \n");
		printf("\t*  1 * - Using something else instead of '||', '&&'  \n");
//		printf("\t*  2 * - Fahrenheit to Celsius conversion \n");
//		printf("\t*  3 * - Celsius to Fahrenheit conversion\n");
//		printf("\t*  4 * - Check for EOF\n");
//		printf("\t*  5 * - Counting words\n");
//		printf("\t*  6 * - Histogram\n");
//		printf("\t*  7 * - Histogram based on different simbols\n");
//		printf("\t*  8 * - Fahrenheit to Celsius conversion - caling a function for converion\n");
		//printf("\n\t*  0 * - show symbol\n");

		Exercise = getchar();
	
		switch (Exercise)
		{
			case '1':
				zadacha1_2();
				break;
			/*case '2':
				zadacha3();
				break;
			case '3':
				zadacha4();
				break;
			case '4':
				zadacha6();
				break;
			case '5':
				zadacha12();
				break;
			case '6':
				zadacha13();
				break;
			case '7':
				zadacha14();
				break;
				*/
			}
		char testing = 'N';
		break;
		}
	getchar();

	return 0;	
}


void zadacha1_2()
{	

	int lim=5;
	int c;

	printf("Please inpute some line:\n");
	c = getchar();
	
	
	printf("Print first %d symbols with * between them (from input):\n", lim-1);

	printf("usein: 'for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)' :\n");

	for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)
	{
		printf("%c", (char)c);
		if (c != '\n', i+1<lim - 1)
		{
			printf("*");

		}
	}

	printf(" usein: for (int i = 0;(i < lim - 1); ++i)\n");
	printf("{\n");
	printf("\tif (c = getchar() != (EOF)) :\n");
	for (int i = 0;(i < lim - 1); ++i)
	{
		if (c = getchar() != (EOF))
		{
			printf("%c", (char)c);
			if (c != '\n', i + 1 < lim - 1)
			{
				printf("*");

			}
		}
		else
		{
			break;
		}
	}
		getchar();

}
