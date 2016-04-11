#include<stdio.h>


void showbits(unsigned int);
void Print_hex(unsigned int, unsigned char);

int main()
{
	unsigned int X = 0x123f5a7d;
	unsigned char n = 8;
	printf("Old value : %x\n", X);
	
	Print_hex(X, n);
	
	
	

	//showbits(X);
	/*
	

	//showbits(X);

	//Print_hex(X);



	for (int i = (sizeof(X) * 8) - 1; i >= 0; i -= 4)
	{

		if (X&(0u << (i)))
		{
			putchar('0');
		}
		else if (X&(1u << (i - 3)))
		{
			putchar('1');
		}
		else if (X&(10u << (i - 2)))
		{
			putchar('2');
		}
		else if (X&(11u << (i - 2)))
		{
			putchar('3');
		}
		else if (X&(1u << (i - 1)))
		{
			putchar('4');
		}

	
	
	}
	*/
	putchar('\n');
	getchar();

	return 0;
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

void Print_hex(unsigned int X, unsigned char n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (X&(1u << (sizeof(X) * 8 -1)))
		{
			X <<= 1;
			X++;
		}
		else
		{
			X <<= 1;
		}
	}
	printf("New value :%x\n", X);

}