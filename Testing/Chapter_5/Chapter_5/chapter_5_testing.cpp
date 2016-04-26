#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static char daytab_0[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char daytab_1[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char *daytab_p[] = { daytab_0, daytab_1 };


//optional scenarios:
void zadacha5_4();	//'-'
	int strlen_2(char[]);
	bool strend(char[], char[]);
void zadacha5_5(); // functions: strncpy_2; strncat_2; strncmp_2
	void strncpy_2(char[], char[], int, int);
	void strncat_2(char[], char[], int, int);
	int strncmp_2(char[], char[], int n = -1);
void zadacha5_8(); // 
	int day_of_year(int, int, int);
	void month_day(int, int, int *, int *);
void zadacha5_9(); // 
	int day_of_year_2(int, int, int);
	void month_day_2(int, int, int *, int *);

	
int main()
{
	int Exercise;


	char testing = 'Y';
	while (testing == 'Y' || testing == 'y')
	{
		printf("Please choose one of the optional scenarios: \n");
		printf("\t*  1 * - 5-4 \n"
				"\t*  2 * - 5-5\n"
				"\t*  3 * - 5-8\n"
				"\t*  4 * - 5-9\n");

		Exercise = getchar();
		//fseek(stdin, 0, SEEK_END);
		switch (Exercise)
		{
		case '1':
			while (getchar() != '\n');
			zadacha5_4(); //Expand shornotation based on '-'
			break;
		case '2':
			while (getchar() != '\n');
			zadacha5_5(); // 
			break;
		case '3':
			while (getchar() != '\n');
			zadacha5_8(); // 
			break;
		case '4':
			while (getchar() != '\n');
			zadacha5_9(); // 
			break;
		}

		printf("Press any key to continue ... :) \n");
		while (getchar() != '\n');
		do
		{
			printf("Do you want to continue: 'Y' or 'y' and 'N' or 'n':\t");
			testing = getchar();
			fseek(stdin, 0, SEEK_END);
		} while ((testing != 'Y') && (testing != 'N') && (testing != 'y') && (testing != 'n'));

	}
	printf("\nPress any key to continue .... :)\n");
	getchar();


	return 0;
}
void zadacha5_4()
{
	char s[100], t[100];
	//int a;
	printf("Please input first string:\n");
	fgets(s, sizeof s, stdin);

	printf("Please input second string:\n");
	fgets(t, sizeof t, stdin);

	//a = strlen_2(s);
	//printf("\n%d,\n",a);
	printf("\nIf first string occures at the end of seconf string \n print'1'\n else '0'\nResult: %d\n", strend(s, t));
}
int strlen_2(char str[])
{
	int i = 0;
	while (str[i++] != '\n');
	return i;
}

bool strend(char s[], char t[])
{
	bool check = false;
	//int tempsize = strlen_2(s) - strlen_2(t);
	for (int i = 0; i <(strlen_2(s) - strlen_2(t)); i++)
	{
		if (s[i + strlen_2(s) - strlen_2(t)] != t[i])
		{
			bool check = false;
			return (check);
		}
		else
		{
			check = true;
		}
	}

	return (check);
}
void zadacha5_5()
{
	//char str1[10] = "123456", str2[20] = "132456789";
	char str1[20], str2[20];
	//int n=3;
	int n;
	int ret;

	char funcselect;
	do
	{
		printf("Please chouse which function do you want to test:\n"
			"a -> strncpy_2\n"
			"b -> strncat_2\n"
			"c -> strncmp_2\n"
		);
		funcselect = getchar();
		fseek(stdin, 0, SEEK_END);
	} while ((funcselect != 'a') && (funcselect != 'b') && (funcselect != 'c'));

	printf("Please input first string:\n");
	fgets(str1, sizeof str1, stdin);
	fseek(stdin, 0, SEEK_END);

	printf("Please input second string:\n");
	fgets(str2, sizeof str2, stdin);
	fseek(stdin, 0, SEEK_END);
	switch (funcselect)
	{
	case 'a':
		do
		{
			printf("How much symbols you wan to change:\n");
			scanf_s("%d", &n);
			fseek(stdin, 0, SEEK_END);
		} while (!(n > 0));
		// strncpy_s(str1, str2, n);
		strncpy_2(str1, str2, n, sizeof str1);
		printf(str1);
		printf("\n");
		break;
	case 'b':
		do
		{
			printf("How much symbols you wan to concatenate to first string:\n");
			scanf_s("%d", &n);
			fseek(stdin, 0, SEEK_END);
		} while (!(n > 0));
		//strncat_s(str1, str2, n);
		strncat_2(str1, str2, n, sizeof str1);
		printf(str1);
		printf("\n");
		break;
	case 'c':
		do
		{
			printf("How till which symbol should compare:\n");
			scanf_s("%d", &n);
			fseek(stdin, 0, SEEK_END);
		} while (!(n > 0));
		//ret = strncmp(str1, str2, n);
		ret = strncmp_2(str1, str2, 4);
		printf("Result: %d\n", ret);
		break;
	}
}

void strncpy_2(char str1[], char str2[], int n, int size)
{
	int i = 0;
	do
	{
		if (!(i < size))
		{
			printf("Run time ERROR: Buffer is too small!\n");
			getchar();
			exit(1);
		}
		str1[i] = str2[i++];

	} while ((str2[i] != '\0') && (i<n));
	str1[i] = '\0';
}

void strncat_2(char str1[], char str2[], int n, int size)
{
	int i;
	for (i = 0; str1[i] != '\0'; ++i);
	for (int j = 0; (str2[j] != '\0') && (j<n); ++j, ++i)
	{
		if (!(i < size))
		{
			printf("Run time ERROR: Buffer is too small!\n");
			getchar();
			exit(1);
		}
		str1[i] = str2[j];
	}
	if (i <= size)
	{
		str1[i] = '\0';
	}
}

int strncmp_2(char str1[], char str2[], int n)
{
	printf("n=%d\n", n);
	int i;
	int check;
	for (i = 0; ((str1[i] != '\0') && (str2[i] != '\0') && ((i<n) | (n == -1))); ++i)
	{
		printf("i=%d\n", i);

		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
			{
				return check = -1;
			}
			else
			{
				return check = 1;
			}
		}
	}
	return check = 0;
}
void zadacha5_8()
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
void zadacha5_9()
{
	int day;
	int month;
	int year;
	int function_select;
	bool leap;

	printf("Please select function : \n day_of_year -> 0\n month_day -> 1\n\n!!!Note that negative yers will indicate B.C.!!! \n");
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
			printf("%d\n", day_of_year_2(year, month, day));

			//;printf("%d\n", month, day);
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


			month_day_2(year, yearday, &month, &day);
			printf("Month: %d\n Day :%d\n", month, day);
		}
	}

}
int day_of_year_2(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if ((month < 1) || (month > 12))
	{
		printf("ERROR!\nWrong input.\nMONTH should be between  1-12\n"
			"Press any key to terminate...");
		exit(getchar());
	}
	if ((day < 1) || (day > *(*(daytab_p + leap) + month)))
	{

		printf("ERROR!\nWrong input.\DAY should be between  1-%d\nPress any key to terminate...", *(*(daytab_p + leap) + month));
		exit(getchar());
	}

	for (i = 1; i < month; i++)
	{
		day += *(*(daytab_p + leap) + i);
	}
	return day;
}


void month_day_2(int year, int yearday, int *pmonth, int *pday)
{

	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if ((yearday < 1) || (yearday >365 + leap))
	{
		printf("ERROR!\nWrong input.\'yearday' should be between  1-%d\nPress any key to terminate...", (365 + leap));
		exit(getchar());
	}
	for (i = 1; yearday>daytab_p[leap][i]; i++)
		yearday -= *(*(daytab_p + leap) + i);

	*pmonth = i;
	*pday = yearday;

}
