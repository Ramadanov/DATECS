#include <stdio.h>

int main()
{
	printf("Input: \n");
	int c;
	while (c = getchar() != EOF)
	{
		//		printf("%d", c);
		printf("\n*EOF is 0*\n");
	}
	//printf("%d", c);

	printf("\n *EOF is 1* \t\n");
	getchar();

	return 0;
}