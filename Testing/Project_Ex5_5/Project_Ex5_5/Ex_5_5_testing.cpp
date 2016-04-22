#include<stdio.h>
#include <string.h>
#include <stdlib.h>
void strncpy_2(char[], char[], int, int);
void strncat_2(char[], char[], int, int);
int strncmp_2(char[], char[], int n=-1);

int main()
{
	//char str1[10] = "123456", str2[20] = "132456789";
	char str1[10], str2[20];
	//int n=3;
	int n;	
	int ret;
	
	char funcselect;
	do
	{
		printf("Please chouse which function do you want to test:\n"
			"a -> strncpy_2\n"
			"b -> strncat_2\n"
			"c -> strncmp_2\n"
		);
		funcselect = getchar();
		fseek(stdin, 0, SEEK_END);
	} while ((funcselect!='a')&& (funcselect != 'b')&& (funcselect != 'c'));
	
	printf("Please input first string:\n");
	fgets(str1, sizeof str1, stdin);
	fseek(stdin, 0, SEEK_END);

	printf("Please input second string:\n");
	fgets(str2, sizeof str2, stdin);
	fseek(stdin, 0, SEEK_END);
	switch (funcselect)
	{
		case 'a':
			do
			{
				printf("How much symbols you wan to change:\n");
				scanf_s("%d\n", &n);
				fseek(stdin, 0, SEEK_END);
			} while (!(n > 0));
			// strncpy_s(str1, str2, n);
			strncpy_2(str1, str2, n, sizeof str1);
			printf(str1);
			break;
		case 'b':
			do
			{
				printf("How much symbols you wan to concatenate to first string:\n");
				scanf_s("%d\n", &n);
				fseek(stdin, 0, SEEK_END);
			} while (!(n > 0));
			//strncat_s(str1, str2, n);
			strncat_2(str1, str2, n, sizeof str1);
			printf(str1);
			break;
		case 'c':
			do
			{
				printf("How till which symbol should compare:\n");
				scanf_s("%d\n", &n);
				fseek(stdin, 0, SEEK_END);
			} while (!(n > 0));
			//ret = strncmp(str1, str2, n);
			ret = strncmp_2(str1, str2, 4);
			printf("Result: %d", ret);
			break;
	}
	
	
	//while (getchar() != '\n');
	getchar();
	return 0;
}

void strncpy_2(char str1[], char str2[], int n, int size)
{
	int i = 0;
	do
	{	
		if (!(i < size))
		{
			printf("Run time ERROR: Buffer is too small!\n");
			getchar();
			exit(1);
		}
		str1[i] = str2[i++];
		
	} while ((str2[i] != '\0') && (i<n));
	str1[i] = '\0';
}

void strncat_2(char str1[],char str2[], int n, int size)
{
	int i;
	for (i = 0; str1[i] != '\0'; ++i);
	for (int j = 0; (str2[j] != '\0') && (j<n); ++j, ++i)
	{
		if (!(i < size))
		{
			printf("Run time ERROR: Buffer is too small!\n");
			getchar();
			exit(1);
		}
		str1[i] = str2[j];
	}
	if (i <= size)
	{
		str1[i] = '\0';
	}
}

int strncmp_2(char str1[], char str2[],int n)
{
	printf("n=%d\n", n);
	int i;
	int check;
	for (i = 0; ((str1[i] != '\0')&&(str2[i] != '\0')&&((i<n)|(n==-1))); ++i)
	{
		printf("i=%d\n", i);

		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
			{
				return check = -1;
			}
			else
			{
				return check = 1;
			}
		}
	}
	return check = 0;
}