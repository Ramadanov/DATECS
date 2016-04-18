#include <stdio.h>

//optional scenarios:
void zadacha1();	// Hello world
void zadacha3();	// Fahrenheit to Celsius conversion
void zadacha4();	// Celsius to Fahrenheit conversion
void zadacha6();	// Check for EOF
void zadacha12();	// Counting words
void zadacha13();	// Histogram
void zadacha14();	// Histogram based on different simbols
void zadacha15();	// Fahrenheit to Celsius conversion - caling a function for converion\n");
	void zadacha3sub();				//*******************
		int concetrFtoC(int);		//sub prigrams used 
	void zadacha4sub();				//in :zadacha 15
		int concetrCtoF(int);		//*******************
void zadacha19();	//Reverses input line at a time
	void reverse(char []); //Reverses line


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
		printf("\t*  9 * - Reverses input line at a time\n");
		//printf("\n\t*  0 * - show symbol\n");

		Exercise = getchar();
		
		switch (Exercise) 
		{
			case '1':
				while (getchar() != '\n');
				zadacha1(); // Hello world
				break;
			case '2':
				while (getchar() != '\n');
				zadacha3(); // Fahrenheit to Celsius conversion
				break;
			case '3':
				zadacha4();
				while (getchar() != '\n'); // Celsius to Fahrenheit conversion
				break;
			case '4': // Check for EOF
				zadacha6(); 
				while (getchar() != '\n');
				break;
			case '5': // Counting words
				zadacha12();
				while (getchar() != '\n');
				break;
			case '6': // Histogram
				while (getchar() != '\n');
				zadacha13();
				break;
			case '7': // Histogram based on different simbols
				while (getchar() != '\n');
				zadacha14();
				break;
			case '8': 
				while (getchar() != '\n');
				zadacha15();
				break;
			case '9':
				while (getchar() != '\n');
				zadacha19();
				break;
			//case '0':
			//	test();
			//	break;


		};
		printf("Press any key to continue ... :) \n");
		getchar();
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




void zadacha1() // Hello world
{
	printf("!!!!!Hello ");
	printf("world!!!!! :) \n");
}

void zadacha3() // Fahrenheit to Celsius conversion
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
	//getchar();
}

void zadacha4() // Celsius to Fahrenheit conversion
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
/********************END function ()****************************/


/********************(EOF)****************************/
void zadacha6() // Check for EOF
{
	int c;
		while (c=getchar() != EOF)
		{
	//		printf("%d", c);
			printf("\n*EOF is 0*\n");
		}
	//printf("%d", c);

	printf("\n *EOF is 1* \t\n");
	while (getchar() != '\n');
	//getchar();
}
/********************END function (EOF)****************************/

/********************Counting words****************************/
void zadacha12() // Counting words
{
	getchar();
	int c, count_words = 0;
	//	int nc, nw;
	bool check_for_word = false;

	printf("Please write something: \n");
	c = getchar();
	while (c != '\n')
	{
		if ((c != ' ' && c != '\n' && c != '\t') && (!check_for_word)) //checking for startinbg symbol
		{
			check_for_word = true;
			count_words++;
		}

		if ((c == ' ' || c == '\n' || c == '\t') && (check_for_word)) //checking for delimiter
		{
			putchar('\n');
			check_for_word = false;
		}
		else
		{
			putchar(c);
		}
		c = getchar();

	}

	printf("\n%d\n", count_words);
	//getchar();
}
/********************END function (Counting words)****************************/

/********************Histogram function****************************/
void zadacha13() // Histogram
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

	//getchar();
}
/********************END function (Histogram) **************************/

/********************Histogram based on different simbols****************************/
void zadacha14() // Histogram based on different simbols
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
	
}
/********************END function (Histogram based on different simbols) **********************/

/************ Temperature conversion - caling a function for converion ************/
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
	//getchar();
}
/********************END function (Temperature- caling a function for converion) **********************/


	/********************zadacha3sub ((zadacha15) **********************/
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
	/********************END function () **********************/

	/********************concetrFtoC(zadacha15)**********************/
	int concetrFtoC(int fahr)
	{
		int celsius;
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		return celsius;

	}
	/********************END function () **********************/

	/********************zadacha4sub (zadacha15)**********************/
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
	/********************END function () **********************/

	int concetrCtoF(int celsius1)
	{
		int fahr1;
		fahr1 = (9.0 / 5.0 * celsius1) + 32.0;
		return fahr1;
	}
	/********************END function () **********************/

/******************** Reverses input line at a time ********************/
void zadacha19()
{
	char line[1000];
	char templine[1000];
	int linelenght = 0;

	//printf("write youre line:\n");
	fgets(line, sizeof line, stdin);
	//printf("current line :\n");
	//printf(line);
	//printf("\n");





	for (int i = 0; line[i] != '\0'; i++)
	{
		//printf("%d\n", line[i]);
		if ((line[i] != '\n') && (line[i] != '\t') && (line[i] != ' '))
		{
			templine[linelenght] = line[i];
			linelenght++;
		}
		else if (templine[0] != '\0')
		{
			templine[linelenght] = '\n';
			templine[linelenght + 1] = '\0';
			reverse(templine);
			printf(templine);
			//printf("\n");
			linelenght = 0;
			templine[0] = '\0';
		}
	}

	/*
	reverse(line);

	printf("new line :\n");
	printf(line);
	printf("\n");*/




	/*
	int i = 0;
	while (line[i] != '\0')
	{
	//printf("%d\n", line[i]);
	if ((line[i] != '\n') && (line[i] != '\t')&&(line[i] != ' '))
	{
	templine[linelenght] = line[i];
	linelenght++;
	}
	else
	{
	//printf("\n%d\t test\n", linelenght);
	while (linelenght > 0)
	{
	//printf("\%d\t test\n", linelenght);

	linelenght--;
	//	printf("\t%d test\t", linelenght);
	char tempchar;
	tempchar = char(templine[linelenght]);
	printf("%c", templine[linelenght]);
	//	linelenght--;
	if (linelenght == 0)
	{
	printf("\n");
	}
	}
	}
	i++;
	}
	*/
	getchar();
}
/********************END function (Reverses input line at a time) **********************/

/******************** Reverses line **********************/
void reverse(char s[])
{
	//char templine[1000];
	char temp;
	int i = 0;
	while (s[i] != '\n')
		++i;
	/*
	printf("new line :\n");
	printf(s);
	printf("\n");
	*/
	int j = 0;
	while (i >j)
	{

		i--;
		//printf("\ni=%d ",i);
		//printf("\n s[%d]=%c ", j, s[j]);
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		//printf("\n s[%d]=%c\n", j, s[j]);
		j++;

	}
	/*
	printf("new line :\n");
	printf(s);
	printf("\n");
	*/
}
/********************END function (Reverses line) **********************/
