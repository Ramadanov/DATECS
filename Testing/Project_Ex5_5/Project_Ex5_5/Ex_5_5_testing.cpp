#include<stdio.h>
//#include <string.h>
//#include <stdlib.h>
void strncpy (char[], char[], int);

int main()
{
	char str1[10], str2[20];
	int n = 5;
	//int a;
	printf("Please input first string:\n");
	fgets(str1, sizeof str1, stdin);

	printf("Please input second string:\n");
	fgets(str2, sizeof str2, stdin);
	
	strncpy(str1, str2, n);
	//strncpy_s(str1, str2, 6);

	printf(str1);

	//while (getchar() != '\n');
	getchar();
	return 0;
}

void strncpy(char str1[], char str2[], int n)
{
	int i = 0;
	do
	{
		str1[i] = str2[i];
		i++;
		if (i > (sizeof str1))
		{	
			printf("Run time ERROR: Buffer is too small!\n");
			break;
			//exit(0);
		}
	} while ((str2[i] != '\0')||(i<n));
	str1[i] = '\0';
}