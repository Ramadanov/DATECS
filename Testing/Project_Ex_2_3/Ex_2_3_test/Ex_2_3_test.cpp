#include <stdio.h>

int power(int, int);
int hotoi(char[], int);

int main()
{

	char hexadec[100];
//	char hexadecreverse[100];
	int fin_dec = 0, count=0;
//	int dec_converted;
	//int i = 2;
	printf("Enter Your Hexadecimal:\t");
	fgets(hexadec, sizeof hexadec, stdin);
	
	//printf("%c\n", hexadec[i]);

	//int intconverter;
	//temp = hexadec[i] - '0'; //(int)hexadec[1];
	//printf("%d\n", temp);
	fin_dec = hotoi(hexadec, 100);
	
	printf("\nConverted to decimal:\t%d\n", fin_dec);

	/*
	for (int i = count-1; i >0; i--)
	{
		intconverter = hexadec[i] - '0';
		fin_dec = fin_dec + (intconverter)* power(16, i);
	}


	/*
	printf("[0] - > %c\n", c[0]);
	printf("[1] - > %c\n", c[1]);
	printf("[2] - > %c\n", c[2]);
	
	printf("c (d) - > %d\n", c);
	printf("c (c) - > %c\n", c);
	char temp = (char)c[0];
	
	printf("temp - > %d\n", temp);

	/*

	char hexadec[2];
	//unsigned char to_int;
	int i=0;
		printf("Please input HEXDECIMAL value: \n");
		fgets(hexadec, sizeof hexadec, stdin);
		
		printf("[0] -> %c\n", hexadec[0]);
		printf("[1] ->%c\n", hexadec[1]);
		
	*/

	getchar();
	
	return 0;
}

int hotoi(char hexadec[], int size)
{
	int dec_converted=0;
	
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