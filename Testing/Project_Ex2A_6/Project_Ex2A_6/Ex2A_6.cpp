#include <stdio.h>

int hotoi();
void showbits(int);
int VariantA(int);
int VariantC(int);
int VariantD(int);

int main()
{
	int X;
	//bool tempcheck;
	//bool valid;
	//unsigned char c;
	printf("Please input value for X:\n");

	X = hotoi();
	//	printf("The number you typed was %d\n", X);


		//printf("Please input value for X:\n");

		//c [0]= X;
		//unsigned char c=0x77;
		//c++;
		//printf("C = ");
	printf("Binary X = 0b");
	showbits(X);
	printf("\n");

	char Variante;

	do
	{
		printf("Chouse Variante:\n'a';\n'b';\n'c';\n'd';\n");
		Variante = getchar();
		switch (Variante)
		{
			case 'a':
			(VariantA(X)) ? printf("TRUE") : printf("FALSE");
				break;
			case 'b':
				(X != 0) ? printf("TRUE") : printf("FALSE");
				break;
			case 'c':
				(VariantC(X)) ? printf("TRUE") : printf("FALSE");
				break;
			case 'd':
				(VariantD(X)) ? printf("TRUE") : printf("FALSE");
				break;
			default:
				printf("!!!Invalid inut!!! . . .\n");
		}

		while (getchar() != '\n');
	}


	while (Variante != 'a'&& Variante != 'b' && Variante != 'c' && Variante != 'd');

	
	

	getchar();


	return 0;
}


int hotoi()
{	
	char hexadec[100];
	int dec_converted = 0;
	fgets(hexadec, sizeof hexadec, stdin);

	for (int i = 0; (i < (sizeof hexadec) && hexadec[i] != '\n' && hexadec[i] != '\0'); i++)
	{
		if (hexadec[0] == '0')
		{
			i++;
			if (hexadec[1] == 'x')
			{
				i++;
			}
		}
		if ((hexadec[i] == 'a') || (hexadec[i] == 'A'))
		{
			dec_converted = (dec_converted + 10) * 16;
		}
		else if ((hexadec[i] == 'b') || (hexadec[i] == 'B'))
		{
			dec_converted = (dec_converted + 11) * 16;
		}
		else if ((hexadec[i] == 'c') || (hexadec[i] == 'C'))
		{
			dec_converted = (dec_converted + 12) * 16;
		}
		else if ((hexadec[i] == 'd') || (hexadec[i] == 'D'))
		{
			dec_converted = (dec_converted + 13) * 16;
		}
		else if ((hexadec[i] == 'e') || (hexadec[i] == 'E'))
		{
			dec_converted = (dec_converted + 14) * 16;
		}
		else if ((hexadec[i] == 'f') || (hexadec[i] == 'F'))
		{
			dec_converted = (dec_converted + 15) * 16;
			//printf("\dec_converted   :\t%d\n", dec_converted);
		}
		else if (hexadec[i] == '0' || hexadec[i] == '1' || hexadec[i] == '2' || hexadec[i] == '3' || hexadec[i] == '4' || hexadec[i] == '5' || hexadec[i] == '6' || hexadec[i] == '7' || hexadec[i] == '8' || hexadec[i] == '9')
		{
			dec_converted = (dec_converted + (hexadec[i] - '0')) * 16;
		}
	}
	dec_converted = dec_converted / 16;

	return dec_converted;
}

void showbits(int x)
{
	int i;
	for (i = (sizeof(x) * 8) - 1; i >= 0; i--)
	{
		(x&(1u << i)) ? putchar('1') : putchar('0');
	}
	printf("\n");
}

int VariantA(int x)
{
	bool valid=false;
	int i;
	for (i = (sizeof(x) * 8) - 1; i >= 0; i--)
	{
		if (!(x&(1u << i)))
		{
			valid = true;
			return valid;
		}
	}
	return valid;

}

int VariantD(int x)
{
	bool valid = false;
	int i;
	int counter=0;
	for (i = (sizeof(x) * 8) - 1; ((i >= 0)&&(counter<8)); i--)
	{
		if (!(x&(1u << i)))
		{
			valid = true;
			return valid;
		}
		counter++;
	}
	return valid;

}

int VariantC(int x)
{
	bool valid = false;
	int i;
	int counter = 0;
	for (i = 0; (i < 8); i++)
	{
		if (x&(1u << i))
		{
			valid = true;
			return valid;
		}
		counter++;
	}
	return valid;

}