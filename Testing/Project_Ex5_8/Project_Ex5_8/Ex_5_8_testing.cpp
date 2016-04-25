/*Exercise 5-8 There is no error chechking in day_of_year or month_day.
Remedy this defect.*/

/*
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i,leap;

	leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
	for (i=0; i<month; i++)
		day +=daytab[leap][i];
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{

	int i,leap;

	leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
	for (i=1; yearday>daytab[leap][i]; i++)
		year -= daytab[leap][i];

	*pmonth =i;
	*pday =yearday;
return pday;
}

*/

#include<stdio.h>
#include <stdlib.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);



static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int main()
{
	int day;
	int month;
	int year;
	int function_select;


	printf("Please select function : \n day_of_year -> 0\n month_day -> 1\n");
	scanf_s("%d", &function_select);
	switch (function_select)
	{
	case 0:
		{
			printf("Please input year : \n");
			scanf_s("%d", &year);
			fseek(stdin, 0, SEEK_END);

			printf("Please input month : ");
			scanf_s("%d", &month);
			fseek(stdin, 0, SEEK_END);

			printf("Please input day : ");
			scanf_s("%d", &day);
			fseek(stdin, 0, SEEK_END);

			printf("%d\n", day_of_year(year, month, day));
			break;
		}

	case 1:
		{
			int yearday = 0;

			printf("Please input year : \n");
			scanf_s("%d", &year);
			fseek(stdin, 0, SEEK_END);

			printf("Please input yearday : \n");
			scanf_s("%d", &yearday);
			fseek(stdin, 0, SEEK_END);

			
			month_day(year, yearday, &month, &day);
			printf("Month: %d\n Day :%d\n", month, day);
		}
	}

	

	
	
	
	getchar();


	return 0;
}
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if ((month < 1) || (month > 12))
	{
		printf("ERROR!\nWrong input.\nMONTH should be between  1-12\n"
			"Press any key to terminate...");
		exit(getchar());
	}
	if ((day < 1) || (day >daytab[leap][month]))
	{

		printf("ERROR!\nWrong input.\DAY should be between  1-%d\nPress any key to terminate...", daytab[leap][month]);
		exit(getchar());
	}

	for (i = 0; i < month; i++)
	{
		day += daytab[leap][i];
	}
	return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
{

	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if ((yearday < 1) || (yearday >365 + leap))
	{
		printf("ERROR!\nWrong input.\'yearday' should be between  1-%d\nPress any key to terminate...", (365 + leap));
		exit(getchar());
	}
	for (i = 1; yearday>daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	*pmonth = i;
	*pday = yearday;

}
