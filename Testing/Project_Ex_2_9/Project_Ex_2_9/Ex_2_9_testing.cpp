#include <stdio.h>

int bitcount(unsigned);
int bitcount_new(unsigned);

int main()
{	

	/*Selution for in variables -- to be updated for HEX*/

	printf("Plese input numeric value:");
	unsigned int n1, n2, n;
	//printf("%d\n", n);

	scanf("%d",&n);

	//n &= (n - 1);

	n1 = bitcount(n);
	printf("%d\n", n1);


	n2 = bitcount_new(n);
	printf("%d\n", n2);
	
	while (getchar() != '\n'); //cleaning buffer :)
		
	getchar();
	return 0;
}


int bitcount(unsigned x)
{
	int b, bitcount=0 ;
	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
		{
			b++;
		}
		bitcount++;
	}
	printf("function 'bitcount()' iterations:%d\n", bitcount);
	return b;
}

int bitcount_new(unsigned x)
{
	int b, bitcount = 0;
	bitcount = 0;
	for (b = 0; x != 00; x >>= 1)
	{
		if (x != 00)
		{
			x &= (x - 1);
			b++;
		}
		bitcount++;
	}
	printf("function 'bitcount_new()' iterations:%d\n", bitcount);
	return b;
}