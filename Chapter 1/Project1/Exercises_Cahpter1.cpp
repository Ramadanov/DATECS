#include <stdio.h>

//optional scenarios:
void zadacha1();	// Hello world
void zadacha3();	// Fahrenheit to Celsius conversion
void zadacha4();	// Celsius to Fahrenheit conversion
void zadacha6();	// Check for EOF
void zadacha12();	// Counting words
void zadacha13();	// Histogram
void zadacha14();	// Histogram based on different simbols
void zadacha15();	// show symbol
	void zadacha3sub();
		int concetrFtoC(int);
	void zadacha4sub();
		int concetrCtoF(int);
//void zadacha19();	// 


int main()
{
	int Exercise;

	char testing='Y';
	while (testing == 'Y'|| testing == 'y')
	{
		printf("Izberete edna ot zadachite: \n");
		printf("\t*  1 * - Hello world \n");
		printf("\t*  2 * - Fahrenheit to Celsius conversion \n");
		printf("\t*  3 * - Celsius to Fahrenheit conversion\n");
		printf("\t*  4 * - Check for EOF\n");
		printf("\t*  5 * - Counting words\n");
		printf("\t*  6 * - Histogram\n");
		printf("\t*  7 * - Histogram based on different simbols\n");
		printf("\t*  8 * - Fahrenheit to Celsius conversion - caling a function for converion\n");
		//printf("\n\t*  0 * - show symbol\n");

		Exercise = getchar();
		
		switch (Exercise) 
		{
			case '1':
				while (getchar() != '\n');
				zadacha1();
				break;
			case '2':
				while (getchar() != '\n');
				zadacha3();
				break;
			case '3':
				zadacha4();
				while (getchar() != '\n');
				break;
			case '4':
				zadacha6();
				while (getchar() != '\n');
				break;
			case '5':
				zadacha12();
				while (getchar() != '\n');
				break;
			case '6':
				while (getchar() != '\n');
				zadacha13();
				break;
			case '7':
				while (getchar() != '\n');
				zadacha14();
				break;
			case '8':
				while (getchar() != '\n');
				zadacha15();
				break;
			//case '0':
			//	test();
			//	break;


		};

		do
		{
			while (getchar() != '\n');
			printf("Do you want to continue testing: (Y/N)\n");
			testing = getchar();
			if (!(((testing - '0') == 'Y') || ((testing - '0') == 'y') || ((testing - '0') == 'N') || ((testing - '0') == 'n')))
			{
				printf("!!!...Invalid input...!!!\n\n");
			}
		}
		while(((testing - '0')== 'Y' )|| ((testing - '0') == 'y'));
	
		//testing = 'N';
		getchar();
	}

	getchar();

	return 0;

}




void zadacha1()
{
	printf("!!!!!Hello ");
	printf("world!!!!! :) \n");
	printf("Press any key to continue ... :) \n");
}

void zadacha3()
{
	double fahr, celsius;
	float min, step, max;

	min = 0.0;	//lower limit 
	step = 20.0;	//setep size
	max = 300.0;	//upper limit

	fahr = min;

	printf(" (F)\t   (C)\n");	//header
	while (fahr <= max)
		{
			celsius = (5.0 / 9.0) * (fahr - 32.0);
			printf("%3.0f \t %6.1f\n", fahr, celsius);
			fahr = fahr + step;
		}
	getchar();
}

void zadacha4()
{
	double fahr1, celsius1;
	float min1, step1, max1;

	min1 = -20.0;	//lower limit 
	step1 = 10.0;	//setep size
	max1 = 100.0;	//upper limit

	celsius1 = min1;

	printf("   (C)\t (F)\n");	//header
	while (celsius1 <= max1)
	{
		fahr1 = (9.0 / 5.0 * celsius1) + 32.0;
		printf("%6.0f \t %3.1f\n", celsius1, fahr1);
		celsius1 = celsius1 + step1;
	}
	getchar();
}

void zadacha6()
{
	int c;
		while (c=getchar() != EOF)
		{
	//		printf("%d", c);
			printf("\n*EOF is 0*\n");
		}
	//printf("%d", c);

	printf("\n *EOF is 1* \t\n");
	getchar();
}

void zadacha12()
{
	int c, count_words = 0;
//	int nc, nw;
	//int check_for_word;
	
	//printf("\n%d\n", count_words);

	printf("Please write something: \n");
	c = getchar();

	//printf("\n%d\n", counte_words);
	//nc = nw = 0;
	while (c != EOF)
	{
	//	++nc;

		if ((c == ' ' || c == '\n' || c == '\t') ) //checking for delimiter
		{
			putchar('\n');
			//check_for_word = 0; // nead to be addedn additiona check for double spacing and so...
			//++nw;
			count_words = count_words + 1;
					}
		else 
		{
			putchar(c);
		}
		c = getchar();
		
	}

	printf("\n%d\n", count_words);
	//printf("%d %d\n", nw, nc);
	getchar();
}

void zadacha13()
{
	int c; //, counte_words = 0; // - code from zad12
//	int nc, nw;
	//int check_for_word;

	printf("Please write something: \n");
	c = getchar();

	//nc = nw = 0;
	while (c != EOF)
	{
		//	++nc;

		if ((c == ' ' || c == '\n' || c == '\t')) //checking for delimiter
		{
			putchar('\n');
			//check_for_word = 0; // nead to be addedn additiona check for double spacing and so...
			//++nw;
			//counte_words = counte_words + 1;
		}
		else
		{
			printf("*");
		}
		c = getchar();
		//break;
	}

	//printf("%d \n", counte_words); // - code from zad12
	//printf("%d %d\n", nw, nc); // - code from zad12
	getchar();
}


void zadacha14() 
{

	char words[100];
	int  ascii_symbol[127] = { 0 };


	printf("Please write something (14): \n");
	fgets(words, sizeof words, stdin);

	for (int i = 0; i<100; i++)
	{
		if ((words[i] != NULL) && ((int)words[i] != 10) && ((int)words[i] != 0) && ((int)words[i] != -52))
		{
			ascii_symbol[(int)words[i]]++;
			//printf("%d\t", (int)words[i]);
			//printf("%d\t", ascii_symbol[(int)words[i]]);
			//printf("\n");

		}
	}

	for (int i = 0; i < 128; i++)
	{
		if (ascii_symbol[i]>0)
		{
			//printf("%d\n", i);
			char temp;
			temp = (char)i;
			printf("%c", temp);
			for (int j = 0; j < ascii_symbol[i]; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}

	getchar();
	
}


void zadacha15()
{
	char TemperatureType;
	do
	{
		printf("Please couse which from which you want to convert ->\n");	//header
		printf("C to F type ->'C' \n");
		printf("F to C type ->'F' \n");
		TemperatureType = getchar();

		switch (TemperatureType)
		{
		case 'C':
			zadacha4sub();
			break;
		case 'F':
			zadacha3sub();
			break;
		default:
			printf("!!!Incorrect input.!!! \n");
			while (getchar() != '\n');
		}
	}
	while (getchar() != '\n');
}
void zadacha3sub()
{	
	
	double fahr, celsius;
	float min, step, max;

	min = 0.0;	//lower limit 
	step = 20.0;	//setep size
	max = 300.0;	//upper limit

	fahr = min;

	printf(" (F)\t   (C)\n");	//header
	while (fahr <= max)
	{

		celsius = (fahr);
		printf("%3.0f \t %6.1f\n", fahr, celsius);
		fahr = fahr + step;
		//	celsius = (5.0 / 9.0) * (fahr - 32.0);
		//printf("%3.0f \t %6.1f\n", fahr, celsius);
		//	fahr = fahr + step;
	}
	//getchar();
}
int concetrFtoC(int fahr)
{
	int celsius;
	celsius = (5.0 / 9.0) * (fahr - 32.0);
	return celsius;

}

void zadacha4sub()
{
	double fahr1, celsius1;
	float min1, step1, max1;

	min1 = -20.0;	//lower limit 
	step1 = 10.0;	//setep size
	max1 = 100.0;	//upper limit

	celsius1 = min1;

	printf("   (C)\t (F)\n");	//header
	while (celsius1 <= max1)
	{
		fahr1 = concetrCtoF(celsius1);
		printf("%6.0f \t %3.1f\n", celsius1, fahr1);

		celsius1 = celsius1 + step1;
	}
	//getchar();
}

int concetrCtoF(int celsius1)
{
	int fahr1;
	fahr1 = (9.0 / 5.0 * celsius1) + 32.0;
	return fahr1;
}

