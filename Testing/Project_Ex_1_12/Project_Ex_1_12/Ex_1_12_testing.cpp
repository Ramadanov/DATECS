/*Write a program that prints its input one word per line.*/
#include <stdio.h>

int main()
{
	int c, count_words = 0;
	//	int nc, nw;
	bool check_for_word = false;

	printf("Please write something: \n");
	c = getchar();
	while (c != '\n')
	{
		if ((c != ' ' && c != '\n' && c != '\t')&&(!check_for_word)) //checking for startinbg symbol
		{
			check_for_word = true;
			count_words++;
		}

		if ((c == ' ' || c == '\n' || c == '\t')&&(check_for_word)) //checking for delimiter
		{
			putchar('\n');
			check_for_word = false;
		}
		else
		{
			putchar(c);
		}
		c = getchar();

	}

	printf("\n%d\n", count_words);

	getchar();
	return 0;
}