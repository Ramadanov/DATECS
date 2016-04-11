#include <stdio.h>

int bitcount(unsigned);
int bitcount_new(unsigned);
int hotoi(char[], int);

int main()
{	
	

	char hexadec[100];
	printf("Plese input numeric value:");
	unsigned int n1, n2, n;
	//printf("%d\n", n);

	printf("Enter Your Hexadecimal:\t");
	fgets(hexadec, sizeof hexadec, stdin);

	n = hotoi(hexadec, sizeof hexadec);

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
		bitcount = +2;
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
		bitcount += 2;
	}
	printf("function 'bitcount_new()' iterations:%d\n", bitcount);
	return b;
}

int hotoi(char hexadec[], int size)
{
	int dec_converted = 0;

	//printf("\size:\t%d\n", size);
	for (int i = 0; (i < (size) && hexadec[i] != '\n' && hexadec[i] != '\0'); i++)
	{
		if (hexadec[0] == '0')
		{
			i++;
			if (hexadec[1] == 'x')
			{
				i++;
			}
		}
		//printf("\i:\t%d\n", i);
		//printf("\hexadec[i]:\t%d\n", hexadec[i]);
		if ((hexadec[i] == 'a') || (hexadec[i] == 'A'))
		{
			//printf("\A\t\n");
			dec_converted = (dec_converted + 10) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if ((hexadec[i] == 'b') || (hexadec[i] == 'B'))
		{
			dec_converted = (dec_converted + 11) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if ((hexadec[i] == 'c') || (hexadec[i] == 'C'))
		{
			dec_converted = (dec_converted + 12) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if ((hexadec[i] == 'd') || (hexadec[i] == 'D'))
		{
			dec_converted = (dec_converted + 13) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if ((hexadec[i] == 'e') || (hexadec[i] == 'E'))
		{
			dec_converted = (dec_converted + 14) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if ((hexadec[i] == 'f') || (hexadec[i] == 'F'))
		{
			dec_converted = (dec_converted + 15) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if (hexadec[i] == '0' || hexadec[i] == '1' || hexadec[i] == '2' || hexadec[i] == '3' || hexadec[i] == '4' || hexadec[i] == '5' || hexadec[i] == '6' || hexadec[i] == '7' || hexadec[i] == '8' || hexadec[i] == '9')
		{
			dec_converted = (dec_converted + (hexadec[i] - '0')) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else
		{
			printf("\*%c: -> Is not a valid HEX so it won't be counted!!!!!!!!!!!!!!!!!\n", hexadec[i]);
		}
		printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
	}
	dec_converted = dec_converted / 16;

	//printf("\nConverted to decimal:\t%d\n", dec_converted);

	return dec_converted;
}