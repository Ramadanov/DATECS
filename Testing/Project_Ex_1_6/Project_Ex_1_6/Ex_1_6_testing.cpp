/*Exercise 1-6 Verify that the effect of setting c to 0 or 1, depending on whether or not
the call of getchar encounters end of file. (More on this in Chapetr 2.)*/
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