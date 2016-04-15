/*Write a function reverse(s) that reverses the character string s.
Use it to program that reverses its input a line at a time*/
#include <stdio.h>

void reverse(char[]);

int  main()
{
	char line[1000];
	char templine[1000];
	int linelenght = 0;

	//printf("write youre line:\n");
	fgets(line, sizeof line, stdin);
	//printf("current line :\n");
	//printf(line);
	//printf("\n");

	

	
	
	for (int i = 0; line[i] != '\0'; i++)
	{
		//printf("%d\n", line[i]);
		if ((line[i] != '\n') && (line[i] != '\t') && (line[i] != ' '))
		{
			templine[linelenght] = line[i];
			linelenght++;
		}
		else if (templine[0] != '\0')
		{
			templine[linelenght] = '\n';
			templine[linelenght+1] = '\0';
			reverse(templine);
			printf(templine);
			//printf("\n");
			linelenght = 0;
			templine[0]='\0';
		}
	}

	/*	
	reverse(line);

	printf("new line :\n");
	printf(line);
	printf("\n");*/

	
	
	
	/*
	int i = 0;
	while (line[i] != '\0')
	{
		//printf("%d\n", line[i]);
		if ((line[i] != '\n') && (line[i] != '\t')&&(line[i] != ' '))
		{
			templine[linelenght] = line[i];
			linelenght++;	
		}
		else
		{
			//printf("\n%d\t test\n", linelenght);
			while (linelenght > 0)
			{	
				//printf("\%d\t test\n", linelenght);
				
				linelenght--;
			//	printf("\t%d test\t", linelenght);
				char tempchar;
				tempchar = char(templine[linelenght]);
				printf("%c", templine[linelenght]);
			//	linelenght--;
				if (linelenght == 0)
				{
					printf("\n");
				}
			}
		}
		i++;
	}
	*/
	getchar();
		return 0;
}

void reverse(char s[])
{
	//char templine[1000];
	char temp;
	int i = 0;
	while (s[i] != '\n')
			++i;
	/*
	printf("new line :\n");
	printf(s);
	printf("\n");
	*/
	int j = 0;
	while (i >j)
	{
		
		i--;
		//printf("\ni=%d ",i);
		//printf("\n s[%d]=%c ", j, s[j]);
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		//printf("\n s[%d]=%c\n", j, s[j]);
		j++;

	}
	/*
	printf("new line :\n");
	printf(s);
	printf("\n");
	*/
}