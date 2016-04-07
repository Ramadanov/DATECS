#include <stdio.h>

int main()
{


	char words[100];
	int  ascii_symbol[127] = { 0 };


	printf("Please write something: \n");
	fgets(words, sizeof words, stdin);

	for (int i = 0; i < 100; i++)
	{
		if ((words[i] != NULL) && ((int)words[i] != 10) && ((int)words[i] != 0) && ((int)words[i] != -52))
		{
			ascii_symbol[(int)words[i]]++;
			//printf("%d\t", (int)words[i]);
			//printf("%d\t", ascii_symbol[(int)words[i]]);
			//printf("\n");

		}
	}

	for (int i = 0; i < 128; i++)
	{
		if (ascii_symbol[i] > 0)
		{
			//printf("%d\n", i);
			char temp;
			temp = (char)i;
			printf("%c", temp);
			for (int j = 0; j < ascii_symbol[i]; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	getchar();
	return 0;
}