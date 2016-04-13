#include <stdio.h>

void showbits(unsigned int);
void setBit(int x, unsigned char position);
void clearBit(int x, unsigned char position);
int isPowerOfTwo(int x);


int main()
{
	unsigned int X =0x100;
	unsigned char n = 3;
	printf("\nOld value : %x\n", X);
	showbits(X);
	//Ex 2B1:
	printf("\nEx 2B1 - setBit\n");
	setBit(X, n);

	//Ex 2B2:
	printf("\nEx 2B2 - clearBit\n");
	clearBit(X, n);

	//Ex 2B3:
	printf("\nEx 2B3 - isPowerOfTwo\n");
	printf("\n(isPowerOfTwo)\nX = %x\nis PowerOf Two?\nYES->(1);\nNO ->(0);\nRESULT: %d\n", X, isPowerOfTwo(X));

	//Ex 2B4:
	printf("Ex 2B4 - checkOneBitSet\n");
	//isn't this the same function as power of 2?. 
	printf("\n(checkOneBitSet)\nX = %x\nYES->(1);\nNO ->(0);\nRESULT: %d\n", X, isPowerOfTwo(X));
	
	
	
	//Ex 2B6:
	printf("\nEx 2B6 swap\n");
	int a = 5, b = 3;
	
	printf("\nOld: a = %d, b = %d\n", a, b);

	//bynary
	a = a^b;
	b = b^a;
	a = a^b;

	printf("\nNew(Binary ^) :\n a = %d, b = %d\n", a, b);
	

	//decimal
	a = 5;
	b = 3;
	a = a + b;
	b = a - b;
	a = a - b;

	printf("\nNew(Decimal '+', '-') A shiukd be max INT / 2 or it'll lose data from overflow :\n a = %d, b = %d\n", a, b);
	


	getchar();
	return 0;
}

void setBit(int X, unsigned char position)
{
	X |= 1u << position;
	printf("\nNew value (setBit) : %x\n", X);
	showbits(X);
}

void clearBit(int x, unsigned char position)

{
	x &= ~(1u << position);
	printf("\nNew value (clearBit) : %x\n", x);
	showbits(x);
}

int isPowerOfTwo(int x)
{
	return ((x!=0)&((x&(x-1))==0));
}

void showbits(unsigned int x)
	{
		int i;
		for (i = (sizeof(x) * 8) - 1; i >= 0; i--)
		{
			(x&(1u << i)) ? putchar('1') : putchar('0');
		}
		printf("\n");
	}