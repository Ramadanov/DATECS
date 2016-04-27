/*Write a version of library functions strncpy, strncat and strncmp which operate on first n character on their argument
strings. For example, strncpy(s, t, n); copiesar most n character of t to s.*/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 20

void strncpy_2(char[], char[], int size = MAXSIZE, int n = -1);
void strncat_2(char [], char[], int size = MAXSIZE, int n = -1); //
int strncmp_2(char[], char[], int n = -1);

int main()
{
	//char str1[10] = "123456", str2[20] = "132456789";
	char str1[MAXSIZE], str2[MAXSIZE];
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

	int i = 0;

	switch (funcselect)
	{
		case 'a':
			/*do
			{
				printf("How much symbols you wan to change:\n");
				scanf_s("%d", &n);
				fseek(stdin, 0, SEEK_END);
			} while (!(n > 0));*/
			// strncpy_s(str1, str2, n);
			
			strncpy_2(str1, str2);
			printf(str1);
			break;
		case 'b':
			/*do
			{
				printf("How much symbols you wan to concatenate to first string:\n");
				scanf_s("%d", &n);
				fseek(stdin, 0, SEEK_END);
			} while (!(n > 1));
			*/
			//strncat_s(str1, str2, n);
			strncat_2(str1, str2);
			printf(str1);
			break;
		case 'c':
			/*do
			{
				printf("How till which symbol should compare:\n");
				scanf_s("%d", &n);
				fseek(stdin, 0, SEEK_END);
			} while (!(n > 0));
			*/
			//ret = strncmp(str1, str2, n);
			ret = strncmp_2(str1, str2);
			printf("Result: %d", ret);
			break;
	}
	
	
	//while (getchar() != '\n');
	getchar();
	return 0;
}

void strncpy_2(char str1[], char str2[], int size, int n)
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
		
	} while ((str2[i] != '\0') && ((i<n) | (n == -1)));
	str1[i] = '\0';
}

void strncat_2(char str1[],char str2[], int size, int n)
{
	int i;
	for (i = 0; str1[i] != '\0'; ++i);
	for (int j = 0; (str2[j] != '\0') && ((j<n) | (n == -1)); ++j, ++i)
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