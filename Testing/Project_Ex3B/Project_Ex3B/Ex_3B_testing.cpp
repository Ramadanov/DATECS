/* This program provides a simple 5-function calculator.

===> OTHER DOCUMENTATION HERE

Input:  a char, stored in operation;
two reals, stored in op1 and op2;
Output: the result of the expression (op1 operation op2).
--------------------------------------------------------------*/

//#include <iostream>         // cin, cout, <<, >>
//#include <string>           // string
//#include <cassert>          // assert()
//#include <cmath>            // pow()
//using namespace std;

#include <stdio.h>

//char getMenuChoice(const string MENU);
//double apply(char operation, double op1, double op2);

char getMenuChoice(char[]);
double apply(char operation, double op1, double op2);

double dd_converter(char[]); // converting sting to double

int main()
{
	//*** ENTER YOUR OPENING OUTPUT STATEMENT(S) HERE
	char operation;
	do {
		char MENU[] = { "\nPlease enter:\n"
			"\t+ - to perform addition;\n"
			"\t- - to perform subtraction;\n"
			"\t* - to perform multiplication;\n"
			"\t/ - to perform division;\n"
			"\t^ - to perform exponentiation;\n"
			"--> " };

		operation = getMenuChoice(MENU);
		//while (getchar() != '\n');
	} while ((operation !='+')&&(operation != '-')&&(operation != '*')&&(operation != '/')&&(operation != '^'));

	//double op1, op2, result;
	char op1_str[100], op2_str[100];
	double op1, op2, result;
	printf("Now enter your operands: \n");	//cout << "Now enter your operands: ";
	//cin >> op1 >> op2;
	printf("Enter your first operand: \n");
	while (getchar() != '\n');
	fgets(op1_str, sizeof op1_str, stdin);
	op1 = dd_converter(op1_str);

	printf("Enter your second operand: \n");
	//while (getchar() != '\n');
	fgets(op2_str, sizeof op2_str, stdin);
	op2 = dd_converter(op2_str);	//assert(cin.good()); //->bad inout - return error
	
	printf("\n op1=%f op2=%f\n",op1, op2);


	result = apply(operation, op1, op2);

	printf("The result is %f\n",result);	//cout << "The result is " << result << endl;

	getchar();
}

char getMenuChoice(char MENU[])
{
	//while (getchar() != '\n');
	char choice;
	printf(MENU);
	printf("\n");		//cout << MENU;
	choice = getchar();	//cin >> choice;
	return choice;
}

double apply(char operation, double op1, double op2)
{
	//*** Add the remaining cases to this switch
	//*** Note:  Use pow() in case 'e' to calculate powers
	//*** Also, the default case is to handle illegal operators
	//*** as described in the lab exercise.
	switch (operation)
	{
	case '+':
		return op1 + op2;
		break;
	case '-':
		return op1 - op2;
		break;
	case '*':
		return op1 * op2;
		break;
	case '/':
		return op1 / op2;
		break;
	

	}
}

double dd_converter(char STR[])
{
	int sign = 0;
	bool dot = true;
	double converted_result = 0;
	double delimiter_counter = 10;

	if (STR[0] == '-')
	{
		sign++;
	}

	for (int i = (0 + sign); STR[i] != '\n'; i++)
	{

		if ((STR[i] > 47) && (STR[i] < 58))
		{
			converted_result = (converted_result + (STR[i] - '0')) * 10;
			if (!(dot))
			{
				delimiter_counter *= 10;
			}
		}

		else
		{
			if ((STR[i] == '.')&(dot))
			{
				dot = false;
			}
			else
			{
				printf("\n!!!BAD input ... !!!\n");
				break;
			}
		}
	}
	converted_result = converted_result / delimiter_counter;


	return converted_result;
}