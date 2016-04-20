#include <stdio.h>

void showbits(unsigned int);
void setBit(int x, unsigned char position);
void clearBit(int x, unsigned char position);
int isPowerOfTwo(int x);
int checkParity(int x);


int main()
{
	unsigned int X = 8;
	unsigned char n=2;
	char Exercise;

	char testing = 'Y';
	while (testing == 'Y' || testing == 'y')
	{
		printf("Please choose one of the optional scenarios: \n");
		printf("\t*  1 * - setBit\n");
		printf("\t*  2 * - clearBit\n");
		printf("\t*  3 * - isPowerOfTwo\n");
		printf("\t*  4 * - checkOneBitSet\n");
		printf("\t*  5 * - checkParity\n");


		Exercise = getchar();

		printf("\nOld value : %x\n", X);
		showbits(X);
		switch (Exercise)
		{
		case '1': //Ex 2B1:
			while (getchar() != '\n');
			printf("\nposition n=%d : \n", n);
			printf("\nEx 2B1 - setBit\n");
			setBit(X, n);
			break;
		case '2'://Ex 2B2:
			while (getchar() != '\n');
			printf("\nposition n=%d : \n", n);
			printf("\nEx 2B2 - clearBit\n");
			clearBit(X, n);
			break;
		case '3'://Ex 2B3:
			while (getchar() != '\n');
			printf("\nEx 2B3 - isPowerOfTwo\n");
			printf("\n(isPowerOfTwo)\nX = %x\nis PowerOf Two?\nYES->(1);\nNO ->(0);\nRESULT: %d\n", X, isPowerOfTwo(X));
			break;
		case '4'://Ex 2B4:
			while (getchar() != '\n');
			printf("Ex 2B4 - checkOneBitSet\n");
			//isn't this the same function as power of 2?. 
			printf("\n(checkOneBitSet)\nX = %x\nYES->(1);\nNO ->(0);\nRESULT: %d\n", X, isPowerOfTwo(X));
			break;
		case '5'://Ex 2B5:
			while (getchar() != '\n');
			printf("\nEx 2B5:\ncheckParity:\n%d\n", checkParity(X));
			break;

		}

		printf("Press any key to continue ... :) \n");
		while (getchar() != '\n');
		do
		{
			printf("Do you want to continue: 'Y' or 'y' and 'N' or 'n':\t");
			testing = getchar();
			while (getchar() != '\n');
		} while ((testing != 'Y') && (testing != 'N') && (testing != 'y') && (testing != 'n'));

		//testing = 'N';
	}
	//getchar();

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

void setBit(int X, unsigned char position) //function that sets bit with position('position') in variable('x') to 1; 
{
	X |= 1u << position;
	printf("\nNew value (setBit) : %x\n", X);
	showbits(X);
}

void clearBit(int x, unsigned char position) //function that clears bit with position('position') in variable('x') to 0; 

{
	x &= ~(1u << position);
	printf("\nNew value (clearBit) : %x\n", x);
	showbits(x);
}

int isPowerOfTwo(int x) //function that checks if variable('x') is power of 2 - this can be used to check if only 1 bit from x is set to 1;
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

int checkParity(int x)
{
	//return (0|(x))?(1^(checkParity(x&(x - 1)))):0;

	x ^= x >> 16; //for 32 bits
	x ^= x >> 8;
	x ^= x >> 4; //for 8 bits
	x ^= x >> 2;
	x ^= x >> 1;
	return (x) & 1;
}