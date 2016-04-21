/*Exercise 4-12 Adapt the ideas of printd to write a recursive version of itoa ;
that is, convert an integer into a string by calling a recursive routine.*/
/*
void itoa (int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) // record sign 
		n = - n;		// make n positive 
	i=0;
	do		//generate digits in reverse order
	{
		s[i++] = n% 10 + '0';	//get next digit
	}while((n /= 10) > 0);		//delete it
	if(sign<0)
		s[i++] = '-';
	s[i] = '\0'
	reverse(s)
}
*/

/*
void printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = - n;	
	}
	if(n/10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

*/
#include<stdio.h>

void printd(int);
int itoa_rec(int, char[]);

int main()

{

	int n, i=0;
	char s[9];

	scanf_s("%d",&n);


	//printd(n);
	//printf("\n");


	itoa_rec(n, s);


	printf(s);

	while(getchar() != '\n');
	getchar();
	return 0;
}

int itoa_rec(int n, char s[])
{
	int i;

	if (n / 10) {
		i = itoa_rec(n / 10, s);
	}
	else
	{	
		i = 0;
		if (n < 0)
		{
			s[i++] = '-';
		}
	}
	if (n < 0)
	{
		n *= -1;
	}
	s[i++] = n % 10 + '0';
	s[i] = '\0';

	return i;
}

void printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

