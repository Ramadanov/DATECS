/*Exercise 1-3 Modify the temperature conversion program to print a heading
above the table.*/
#include <stdio.h>

int main()
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