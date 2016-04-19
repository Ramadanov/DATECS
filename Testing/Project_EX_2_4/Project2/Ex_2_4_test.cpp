/*Write an alternate version of squeez(s1, s2) that deletes each character in s1 that matches any character in s2.*/
#include<stdio.h>

void squeezes(char[], char[]); //function for squeezin the string 
void squeezes_2(char[], char[]);
void squeezes_3(char[], char[], char[]);

int main()
{
	int const lenght = 100;
	char str1[lenght];
	char str2[lenght];
	char str3[lenght];
	printf("Input first string :\n");
	fgets(str1, sizeof str1, stdin);
	//char c = 'a';
	



	printf("input second string :\n");
	fgets(str2, sizeof str2, stdin);

	printf("\n first string before: ");
	printf(str1);

	
	squeezes_3(str1, str2, str3);
	//squeezes_2(str1, str2);
	//squeezes(str1, str2);
	printf("\n");

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

	printf("\n first string after squeezes: ");
	printf(str1);
}

void squeezes_2(char str1[], char str2[])
{
	bool match = false;
	int i=0, j;
	for (int k = 0; str1[k] != '\n'; k++)
	{
		for (int j = 0; str2[j] != '\n'; j++)
		{
			if (str1[k] == str2[j])
			{
				match = true;
				break;
			}
		}
	
		if (!(match))
		{
			str1[i++] = str1[k];
			match = false;
		}
		
	}
	str1[i++] = '\n';
	str1[i] = '\0';
	printf("\n first string after squeezes_2:\n ");
	printf(str1);
}

void squeezes_3(char str1[], char str2[], char str3[])
{
	bool match = false;
	int i = 0, j;
	for (int k = 0; str1[k] != '\n'; k++)
	{
		for (int j = 0; str2[j] != '\n'; j++)
		{
			if (str1[k] == str2[j])
			{
				match = true;
				break;
			}
		}

		if (!(match))
		{
			str3[i++] = str1[k];
		}
		else
		{
			match = false;
		}
	}
	str3[i++] = '\n';
	str3[i] = '\0';
	printf("\n third string after squeezes_3:\n ");
	printf(str3);
}