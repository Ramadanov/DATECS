/*Exercise 3-3 Write a  function (s1, s2) that expands shorthand notations like 
a-z in the string s1 into the ezuivalent complete list abc...xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases 
like a-b-c a-z1-9 and a-z. Arrange that a leading or tralling - is taken 
literally*/

#include<stdio.h>

void expand(char[], char[]); //expands sohrthand notation based on "-"  

int main()
{
	char s1[100];
	char s2[1000];

	printf("Please input data:\n");
	fgets(s1, sizeof s1, stdin);
	printf(s1);

	expand(s1, s2);
	

	printf("\nPress any key to continue .... :)\n");
	getchar();

	return 0;
}

void expand(char s1[], char s2[])
{
	int i_check = 0; // [position for s2]

	for (int i = 0; s1[i] != '\n'; i++)
	{
		if (s1[i] == '-')
		{

			if (s1[i - 1] < s1[i + 1])
			{
				if (((s1[i - 1] > 47) && (s1[i + 1] < 58)) || ((s1[i - 1] > 64) && (s1[i + 1] < 91)) || ((s1[i - 1] > 96) && (s1[i + 1] < 123)))
				{
					//i_check++;
					for (int i_1 = (int)s1[i - 1] + 1; i_1 < (int)s1[i + 1];i_1++, i_check++)
					{
						s2[i_check] = i_1;
					}

					printf("\naz|AZ|09 complete list:\n");
				}
			}
			else if (((s1[i + 1] > 47) && (s1[i - 1] < 58)) || ((s1[i + 1] > 64) && (s1[i - 1] < 91)) || ((s1[i + 1] > 96) && (s1[i - 1] < 123)))
			{
				//i_check++;
				for (int i_1 = (int)s1[i - 1] - 1; i_1 > (int)s1[i + 1];i_1--, i_check++)
				{
					s2[i_check] = i_1;
				}

				printf("\nza|ZA|09 complete list\n");
			}

		}
		else
			//if (s1[i-1] != '-')
		{
			s2[i_check++] = s1[i];
		}
	}
	s2[i_check++] = '\n';
	s2[i_check++] = '\0';

	printf("\n");
	printf(s2);
	printf("\n");

}