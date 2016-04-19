/*In a two's complement number system, x &=(x-1) deletes the rightmost 1-bit in x. Explain why.
Use this observation to write a faster version of bitcount.*/

#include <stdio.h>

int bitcount(unsigned);
int bitcount_new(unsigned);
int hotoi(char[]);
int validh(char[]);

int main()
{	
	

	char hexadec[9];
	printf("Plese input numeric value:");
	unsigned int n1, n2, n;
	//printf("%d\n", n);

	do
	{
		printf("Enter Your Hexadecimal:\t");
		fgets(hexadec, sizeof hexadec, stdin);
	}
	while (!(validh(hexadec)));

	n = hotoi(hexadec);

	//n &= (n - 1);

	n1 = bitcount(n);
	printf("Number of bits: %d\n", n1);


	n2 = bitcount_new(n);
	printf("Number of bits: %d\n", n2);
	
	while (getchar() != '\n'); //cleaning buffer :)
		
	getchar();
	return 0;
}


int bitcount(unsigned int x)
{
	int b, bitcount=0 ;
	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
		{
			b++;
		}
		bitcount += 2;
	}
	printf("function 'bitcount()' iterations:%d\n", bitcount);
	return b;
}

int bitcount_new(unsigned int x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
	{
			x &= (x - 1);
			b++;
	}
	printf("function 'bitcount_new()' iterations:%d\n", b);
	return b;
}

int validh(char hexadec[]) //check for valid hexadecimal
{
	bool valid = true;

	int i = 0;
	if (hexadec[0] == '0')
	{
		if ((hexadec[1] == 'x') || (hexadec[1] == 'X'))
		{
			i += 2;
		}
	}
	for (;hexadec[i] != '\n'; i++)
	{
		if ((hexadec[i] < 48) ||
			((hexadec[i] > 57) && (hexadec[i]<64)) ||
			((hexadec[i]>70) && (hexadec[i] < 97)) ||
			(hexadec[i] > 102))
		{
			printf("Bad input - not hexadecimal!\n\n");
			valid = false;
			return valid;
		}
	}
	return valid;
}

int hotoi(char hexadec[])
{
	int dec_converted = 0;
	int i = 0;
	if (hexadec[0] == '0')
	{
		if ((hexadec[1] == 'x') || (hexadec[1] == 'X'))
		{
			i += 2;
		}
	}
	//printf("\size:\t%d\n", size);

	while (hexadec[i] != '\n')
	{

		switch (hexadec[i])
		{
		case 'A':
		case 'a':
			dec_converted = (dec_converted + 10) * 16;
			break;
		case 'B':
		case 'b':
			dec_converted = (dec_converted + 11) * 16;
			break;
		case 'C':
		case 'c':
			dec_converted = (dec_converted + 12) * 16;
			break;
		case 'D':
		case 'd':
			dec_converted = (dec_converted + 13) * 16;
			break;
		case 'E':
		case 'e':
			dec_converted = (dec_converted + 14) * 16;
			break;
		case 'F':
		case 'f':
			dec_converted = (dec_converted + 15) * 16;
			break;
		default:
			dec_converted = (dec_converted + (hexadec[i] - '0')) * 16;
		}
		i++;
	}

	dec_converted /= 16;



	return dec_converted;
}