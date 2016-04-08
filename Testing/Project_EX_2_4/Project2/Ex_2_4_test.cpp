#include<stdio.h>

void squeezes(char[], char[]); //function for squeezin the string 


int main()
{
	int const lenght = 100;
	char str1[lenght];
	char str2[lenght];
	printf("Input first string :\n");
	fgets(str1, sizeof str1, stdin);
	//char c = 'a';
	
	
	printf("input second string :\n");
	fgets(str2, sizeof str2, stdin);

	squeezes(str1, str2); //

	printf("\n first string before: ");
	for (int i = 0; str1[i] != '\0'; i++)
	{
		printf("%c", str1[i]);
	}
	printf("\n");

	//squeezes(s1, c);
	

	

	printf("\n first after after:");
	for (int i = 0; str1[i] != '\0'; i++)
	{
		printf("%c", str1[i]);
	}
	printf("\n");


	getchar();

	return 0;
}



void squeezes(char str1[], char str2[])
{


	int i, j;

	for (int k = 0; str2[k] != '\0'; k++)
	{
		for (i = j = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] != str2[k])
			{
				str1[j++] = str1[i];
			}
		}

		str1[j] = '\0';
	}
	/*
	int j, i;// k;
	//for (k = 0; s[k] != '\0'; k++)
	//{
		for (i = j = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != c);
			{
				s1[j++] = s1[i];
			}
			s1[j] = '\0';
		}
	//}
	*/
}
