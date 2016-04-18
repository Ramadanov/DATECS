/*Write a version of itoa that accepts three arguments instead of two.
The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make enough.*/

/*
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	//record sign
	n = -n;			//make n positive
	i = 0;
	do {		/* generate digits in reverse order
	s[i++] = n % 10 + '0';	// get next digit
	} while ((n /= 10) > 0);	// delete it

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
}

*/


#include <stdio.h>

void itoa_02(int, char[], int);
void reverse(char[]);

int main()
{

	int s_width=10;
	int n = -12345678;
	char s[1000];

	//printf("Please inpit integer value:\n");
	itoa_02(n,s, s_width);

	

	printf("\nreverse value with blanks if nesesary\n");
	printf(s);
	getchar();
	return 0;
}

void itoa_02(int n, char s[], int s_width)
{
	int i, sign;

	if ((sign = n) < 0)	// record sign 
		n = -n;			// make n positive
	i = 0;
	do
	{		// generate digits in reverse order
		s[i++] = n % 10 + '0';	// get next digit 
	} while ((n /= 10) > 0);	// delete it 

	if (sign < 0)
	{
		s[i++] = '-';
	}

	while (i < 10)
	{
		s[i++] = ' ';
	}
	

	s[i] = '\n';
	s[i + 1] = '\0';

	//printf(s);
	reverse(s);


	//printf("\n");
	//printf(s);
}

void reverse(char s[])
{
	char temp;
	int i = 0;
	while (s[i] != '\n')
		++i;
	int j = 0;
	while (i >j)
	{

		i--;
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;

		j++;
	}
}

