/*Write the function strend(s,t) which  returns 1
if the string t occures at the end of string s, and 0 otherwise*/

#include<stdio.h>
//#include<string.h>

int strlen_2(char[]);
bool strend(char[],char[]);

int main()
{
	char s[100], t[100];
	//int a;
	printf("Please input first string:\n");
	fgets(s, sizeof s, stdin);

	printf("Please input second string:\n");
	fgets(t, sizeof t, stdin);

	//a = strlen_2(s);
	//printf("\n%d,\n",a);
	printf("\nIf second string occures at the end of first string \n print'1'\n else '0'\nResult: %d\n", strend(s, t));

	
	
	getchar();

	//sizelen
	return 0;
}

int strlen_2(char str[])
{
	int i = 0;
	while (str[i++]!='\n');
	return i;
}

bool strend(char s[], char t[])
{
	bool check = false;
	int string_width_s = strlen_2(s);
	int string_width_t = strlen_2(t);
	//int tempsize = strlen_2(s) - strlen_2(t);
	for (int i = 0; i <(string_width_s - string_width_t); i++)
	{
		if (s[i + string_width_s - string_width_t] != t[i])
		{
			bool check = false;
			return (check);
		}
		else
		{
			check = true;
		}
	}

	return (check);
}