#include <stdio.h>

int power(int, int);

int main()
{

	char hexadec[100];
	char hexadecreverse[100];
	int fin_dec = 0, count=0;
	//int i = 2;
	printf("Enter Your Hexadecimal:\t");
	fgets(hexadec, sizeof hexadec, stdin);
	
	//printf("%c\n", hexadec[i]);

	int intconverter;
	//temp = hexadec[i] - '0'; //(int)hexadec[1];
	//printf("%d\n", temp);

	for (int i = 0; (i < (sizeof hexadec) && hexadec[i] != '\n'); i++)
	{
		if ((hexadec[i] == 'a') || (hexadec[i] == 'A'))
		{
			fin_dec = (fin_dec + 10) * 16;
		}
		else if ((hexadec[i] == 'b') || (hexadec[i] == 'B'))
		{
			fin_dec = (fin_dec + 11) * 16;
		}
		else if ((hexadec[i] == 'c') || (hexadec[i] == 'C'))
		{
			fin_dec = (fin_dec + 12) * 16;
		}
		else if ((hexadec[i] == 'd') || (hexadec[i] == 'D'))
		{
			fin_dec = (fin_dec + 13) * 16;
		}
		else if ((hexadec[i] == 'e') || (hexadec[i] == 'E'))
		{
			fin_dec = (fin_dec + 14) * 16;
		}
		else if ((hexadec[i] == 'f') || (hexadec[i] == 'F'))
		{
			fin_dec = (fin_dec + 15) * 16;
		}
		else
		{
			fin_dec = (fin_dec + (hexadec[i] - '0')) * 16;

		}
	}
	fin_dec = fin_dec / 16;
	printf("\nConverted to decimal:\t%d\n", fin_dec);
	/*for (int i = count-1; i >0; i--)
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