#include <stdio.h>

//optional scenarios:
void zadacha2_2(); //  Using 'OR', 'AND', 'NOT' instead of '||', '&&', '!='
void zadacha2_3();

int hotoi(char[], int);


int main()
{
	int Exercise;

		
	char testing = 'Y';
	while (testing == 'Y' || testing == 'y')
	{
		printf("Please choose one of the optional scenarios: \n");
		printf("\t*  1 * - Using something else instead of '||', '&&'  \n");
		printf("\t*  2 * -  \n");
//		printf("\t*  3 * - \n");
//		printf("\t*  4 * - \n");
//		printf("\t*  5 * - \n");
//		printf("\t*  6 * - \n");
//	

		Exercise = getchar();
	
		switch (Exercise)
		{
			case '1':
				zadacha2_2();
				break;
			case '2':
				zadacha2_3();
				break;
			/*case '3':
				zadacha4();
				break;
			case '4':
				zadacha6();
				break;
			case '5':
				zadacha12();
				break;
			case '6':
				zadacha13();
				break;
			case '7':
				zadacha14();
				break;
				*/
			}
		char testing = 'N';
		break;
		}
	getchar();

	return 0;	
}


void zadacha2_2()
{

	int lim = 100;	//limit for input symbols
	int c;	//for old logic
	int c1;		//for new logic

				/*
				printf("Inpute limit:\n");		//logig for input from keyboard;
				lim = getchar();
				lim = (lim - '0');
				lim++;
				*/



	printf("\nPrint first %d symbols with * between them (from input):\n\n", lim - 1);


	/*
	//***********************old logic***************************
	printf("usein: 'for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)' :\n");

	printf("Please inpute some line:\n");

	c = getchar();

	//printf("%c*", (char)c);
	for (int i = 0;(i < lim - 1) && (c = getchar()) != EOF; ++i)
	{
	printf("%c", (char)c);
	if ((c != '\n')&&(i < lim - 1))
	{
	printf("*");

	}
	}
	//***********************************************************
	*/



	//***************8*******new logic***************************

	printf(" usein: for (int i = 0;(i < lim - 1); ++i)\n");
	printf("{\n");
	printf("\tif (c = getchar() != (EOF)) :\n\n\t\t");

	printf("Please inpute some line:\n");
	c1 = getchar();
	//printf("%c*", (char)c);
	for (int i = 0; (i < lim - 1); i++)
	{
		if (c1 != (EOF))
		{
			printf("%c", (char)c1);
			c1 = getchar();
			if (c1 != '\n')
			{
				if (i < lim - 1)
				{
					printf("*");
				}
			}
			else
			{
				printf("\n");
				break;
			}

		}
		else
		{
			printf("\n");
			break;
		}

	}
	//***********************************************************


	getchar();
}

void zadacha2_3()
{
	char hexadec[100];
	//	char hexadecreverse[100];
	int fin_dec = 0, count = 0;

	printf("Enter Your Hexadecimal:\t");
	fgets(hexadec, sizeof hexadec, stdin);

	fin_dec = hotoi(hexadec, 100);

	printf("\nConverted to decimal:\t%d\n", fin_dec);

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
		}
		else if (hexadec[i] == '0' || hexadec[i] == '1' || hexadec[i] == '2' || hexadec[i] == '3' || hexadec[i] == '4' || hexadec[i] == '5' || hexadec[i] == '6' || hexadec[i] == '7' || hexadec[i] == '8' || hexadec[i] == '9')
		{
			dec_converted = (dec_converted + (hexadec[i] - '0')) * 16;
		}
		else
		{
			printf("\*%c: -> Is not a valid HEX so it won't be counted!!!!!!!!!!!!!!!!!\n", hexadec[i]);
		}
		printf("\hexadec[%d]:\t%c\n", i, hexadec[i]);
	}
	dec_converted = dec_converted / 16;

	return dec_converted;
}