#include<stdio.h>

void squeezes(char s1[], int c);


int main()
{
	int const lenght = 10;
	char s1[lenght];
	int c;
	printf("Input sq :\n");
	fgets(s1, sizeof s1, stdin);
	printf("Input :\n");
	c = getchar();

	printf("\n before: %c", (char)s1);
	squeezes(s1, c);

	printf("\n after: %c", (char)s1);

	getchar();
}

void squeezes(char s1[], int c)
{
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
}