#include <stdio.h>

//optional scenarios:
void zadacha2_2();	//  Using 'OR', 'AND', 'NOT' instead of '||', '&&', '!='
void zadacha2_3();	//	Hexadecimal converted to decimal
int validh(char[]); //check for valid hexadecimal
	int hotoi(char[]); //convert from string to hexadecimal
void zadacha2_4();	//	Squeeze
	void squeezes_2(char[], char[]); //Squeeze in s1
	void squeezes_3(char[], char[], char[]); // Squeeze in third string s3
void zadacha2_5();  
	int Chech_for_character(char[], char[]);// check for symbols in s1 from s2
void zadacha2_9();	//	Alternate version for bitcount
	int bitcount(unsigned int); //old version of bit count
	int bitcount_new(unsigned int); //new version of bitcount




int main()
{
	int Exercise;

		
	char testing = 'Y';
	while (testing == 'Y' || testing == 'y')
	{	
		printf("Please choose one of the optional scenarios: \n");
		printf("\t*  1 * - Using something else instead of '||', '&&'  \n");
		printf("\t*  2 * - Hexadecimal converted to decimal \n");
		printf("\t*  3 * - Squeeze S1 from S2\n");
		printf("\t*  4 * - Check for symbols in s1 from s2\n");
		printf("\t*  5 * - Alternate version for bitcount\n");
	

		Exercise = getchar();
	
		switch (Exercise)
		{
			case '1':
				while (getchar() != '\n');
				zadacha2_2(); //Using something else instead of '||', '&&'  \n
				break;
			case '2':
				while (getchar() != '\n');
				zadacha2_3(); // Hexadecimal converted to decimal
				break;
			case '3':
				while (getchar() != '\n');
				zadacha2_4(); //Squeeze S1 from S2
				break;
			case '4':
				while (getchar() != '\n');
				zadacha2_5(); //check for symbols in s1 from s2
				break;
			case '5':
				while (getchar() != '\n');
				zadacha2_9();
				break;
	
			}
		
		printf("Press any key to continue ... :) \n");
		while (getchar() != '\n');
		do
		{
			printf("Do you want to continue: 'Y' or 'y' and 'N' or 'n':\t");
			testing = getchar();
			while (getchar() != '\n');
		} while ((testing != 'Y') && (testing != 'N')&& (testing != 'y') && (testing != 'n'));

		//testing = 'N';
		//getchar();
	}
	//getchar();

	return 0;	
}

/***********************Function **************************/
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


	//getchar();
}
/***********************END Function **************************/



/***********************Function **************************/
void zadacha2_3()// Hexadecimal converted to decimal
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

}
/***********************END Function **************************/

/*********************** Function **************************/
int validh(char hexadec[]) //check for valid hexadecimal
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
/***********************END Function **************************/


/***********************Function **************************/
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



	return dec_converted;
}
/***********************END Function **************************/

/***********************Function **************************/
void zadacha2_4()
{
	int const lenght = 100;
	char str1[lenght];
	char str2[lenght];
	char str3[lenght];
	printf("Input first string :\n");
	fgets(str1, sizeof str1, stdin);
	//char c = 'a';




	printf("input second string :\n");
	fgets(str2, sizeof str2, stdin);

	printf("\n first string before: ");
	printf(str1);


	squeezes_3(str1, str2, str3);
	//squeezes_2(str1, str2);
	printf("\n");

	printf("\n");

}
/***********************END Function **************************/


/***********************Function **************************/
void squeezes_2(char str1[], char str2[])
{
	bool match = false;
	int i = 0, j;
	for (int k = 0; str1[k] != '\n'; k++)
	{
		for (int j = 0; str2[j] != '\n'; j++)
		{
			if (str1[k] == str2[j])
			{
				match = true;
				break;
			}
		}

		if (!(match))
		{
			str1[i++] = str1[k];
			match = false;
		}

	}
	str1[i++] = '\n';
	str1[i] = '\0';
	printf("\n first string after squeezes_2:\n ");
	printf(str1);
}
/***********************END Function **************************/



/*********************** Function **************************/
void squeezes_3(char str1[], char str2[], char str3[])
{
	bool match = false;
	int i = 0, j;
	for (int k = 0; str1[k] != '\n'; k++)
	{
		for (int j = 0; str2[j] != '\n'; j++)
		{
			if (str1[k] == str2[j])
			{
				match = true;
				break;
			}
		}

		if (!(match))
		{
			str3[i++] = str1[k];
		}
		else
		{
			match = false;
		}
	}
	str3[i++] = '\n';
	str3[i] = '\0';
	printf("\n third string after squeezes_3:\n ");
	printf(str3);
}

/***********************END Function **************************/


/*********************** Function **************************/

void zadacha2_5()
{
	int const lenght = 100;
	char s1[lenght];
	char s2[lenght];
	int char_position;
	printf("Input first string :\n");
	fgets(s1, sizeof s1, stdin);



	printf("input second string :\n");
	fgets(s2, sizeof s2, stdin);

	char_position = Chech_for_character(s1, s2);
	if (char_position == -1)
	{
		printf("First chracter that ocures from sreing S2 in String S1 ocures in \n\tposition: %d\n strings don't have same symbols.", char_position);
	}
	else
	{
		printf("First chracter that ocures from sreing S2 in String S1 ocures in \n\tposition: %d\n \tS1[%d] = %c", char_position, char_position, s1[char_position]);
	}


}
/***********************END Function **************************/


/*********************** Function **************************/
int Chech_for_character(char s1[], char s2[])
{

	bool endloop = false;
	int i, j;

	for (int k = 0; (s2[k] != '\n'); k++) //&& (endloop == false)
	{
		for (i = 0; s1[i] != '\n'; i++)
		{
			if (s1[i] == s2[k])
			{
				return i;
				//endloop = true;
			}
		}


	}
	return -1;
}

/***********************END Function **************************/



/*********************** zadacha2_5 **************************/
void zadacha2_9()
{
	char hexadec[9];
	printf("Plese input numeric value:");
	unsigned int n1, n2, n;
	//printf("%d\n", n);

	do
	{
		printf("Enter Your Hexadecimal:\t");
		fgets(hexadec, sizeof hexadec, stdin);
	} while (!(validh(hexadec)));

	n = hotoi(hexadec);

	//n &= (n - 1);

	n1 = bitcount(n);
	printf("Number of bits: %d\n", n1);


	n2 = bitcount_new(n);
	printf("Number of bits: %d\n", n2);

	while (getchar() != '\n'); //cleaning buffer :)

}
/***********************END Function **************************/

/*********************** bitcount **************************/
int bitcount(unsigned int x)
{
	int b, bitcount = 0;
	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
		{
			b++;
		}
		bitcount += 2;
	}
	printf("function 'bitcount()' iterations:%d\n", bitcount);
	return b;
}
/***********************END Function **************************/

/*********************** bitcount_new **************************/
int bitcount_new(unsigned int x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
	{
		x &= (x - 1);
		b++;
	}
	printf("function 'bitcount_new()' iterations:%d\n", b);
	return b;
}
/***********************END Function (bitcount_new) **************************/

