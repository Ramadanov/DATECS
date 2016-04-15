/*Exercise 1-4 Write a program to print the corresponding Celsius to Fahrenhiet table. */
#include <stdio.h>

int main()
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
	return 0;
}