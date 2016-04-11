
#include <stdio.h>

void zadacha3();
void zadacha4();
int concetrFtoC(int);
int concetrCtoF(int);

int main()
{

	char TemperatureType;
	printf("Please couse which from which you want to convert ->\n");	//header
	printf("C to F type ->'C' \n");
	printf("F to C type ->'F' \n");
	TemperatureType = getchar();

	switch (TemperatureType)
	{
	case 'C':
		zadacha4();
		break;
	case 'F':
		zadacha3();
		break;
	default:
		printf("!!!Incorrect input.!!! \n");
		break;
	}

	while (getchar() != '\n');

	getchar();

	return 0;
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

		celsius = concetrFtoC(fahr);
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
		fahr1 = concetrCtoF(celsius1);
		printf("%6.0f \t %3.1f\n", celsius1, fahr1);

		celsius1 = celsius1 + step1;
	}
	//getchar();
}

int concetrCtoF (int celsius1)
{
	int fahr1;
	fahr1 = (9.0 / 5.0 * celsius1) + 32.0;
	return fahr1;
}