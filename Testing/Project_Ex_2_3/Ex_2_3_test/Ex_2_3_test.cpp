#include <stdio.h>

int power(int, int);
int hotoi(char[]);
int validh(char[]);


int main()
{

	char hexadec[9];
	int fin_dec = 0, count = 0;
	do
	{
		printf("Enter Your Hexadecimal:\t");
		fgets(hexadec, sizeof hexadec, stdin);
	}

	while (!(validh(hexadec)));
		//printf("\n%d", validh(hexadec));
	//printf("%c\n", hexadec[i]);

	
	fin_dec = hotoi(hexadec);

	printf("\nConverted to decimal:\t%d\n", fin_dec);

	getchar();
	
	return 0;
}

int validh(char hexadec[])
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
			
			
			
			
			
			/*
		//printf("\i:\t%d\n", i);
		//printf("\hexadec[i]:\t%d\n", hexadec[i]);
		if ((hexadec[i] == 'a') || (hexadec[i] == 'A'))
		{
			//printf("\A\t\n");
			dec_converted = (dec_converted + 10) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else if ((hexadec[i] == 'b') || (hexadec[i] == 'B'))
		{
			dec_converted = (dec_converted + 11) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else if ((hexadec[i] == 'c') || (hexadec[i] == 'C'))
		{
			dec_converted = (dec_converted + 12) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else if ((hexadec[i] == 'd') || (hexadec[i] == 'D'))
		{
			dec_converted = (dec_converted + 13) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else if ((hexadec[i] == 'e') || (hexadec[i] == 'E'))
		{
			dec_converted = (dec_converted + 14) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else if ((hexadec[i] == 'f') || (hexadec[i] == 'F'))
		{
			dec_converted = (dec_converted + 15) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else if (hexadec[i] == '0' || hexadec[i] == '1' || hexadec[i] == '2' || hexadec[i] == '3' || hexadec[i] == '4' || hexadec[i] == '5' || hexadec[i] == '6' || hexadec[i] == '7' || hexadec[i] == '8' || hexadec[i] == '9')
		{
			dec_converted = (dec_converted + (hexadec[i] - '0')) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
			printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
		}
		else
		{
			printf("\*%c: -> Is not a valid HEX so it won't be counted!!!!!!!!!!!!!!!!!\n", hexadec[i]);
		}
		
		i++;
	};
	*/
	//dec_converted = dec_converted / 16;

	//printf("\nConverted to decimal:\t%d\n", dec_converted);

	return dec_converted;
}

int power(int X, int P)
{
	int sum=1;
	if (P != 0)
	{
		for (int i = P; i > 0; i--)
		{
			sum = sum * X;
		}
	}
	return sum;
}