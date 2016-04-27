#include <stdio.h>

//optional scenarios:
void zadacha3_3();	// Expand shornotation based on '-'
	void expand(char[], char[]); //expend function
void zadacha3_6();	//
	void itoa_02(int, char[], int);//converts characters from int to string
	void reverse(char[]); //reverse string




int main()
{
	int Exercise;


	char testing = 'Y';
	while (testing == 'Y' || testing == 'y')
	{
		printf("Please choose one of the optional scenarios: \n");
		printf("\t*  1 * - Expand shornotation based on '-'\n");
		printf("\t*  2 * - \n");

		Exercise = getchar();

		switch (Exercise)
		{
		case '1':
			while (getchar() != '\n');
			zadacha3_3(); //Expand shornotation based on '-'
			break;
		case '2':
			while (getchar() != '\n');
			zadacha3_6(); // 
			break;
		}

		printf("Press any key to continue ... :) \n");
		//while (getchar() != '\n');
		fseek(stdin, 0, SEEK_END);
		do
		{
			printf("Do you want to continue: 'Y' or 'y' and 'N' or 'n':\t");
			testing = getchar();
			//while (getchar() != '\n');
			fseek(stdin, 0, SEEK_END);
		} while ((testing != 'Y') && (testing != 'N') && (testing != 'y') && (testing != 'n'));

	}
	printf("\nPress any key to continue .... :)\n");
	getchar();


	return 0;
}
void zadacha3_3()
{
char s1[100];
char s2[1000];

printf("Please input data:\n");
fgets(s1, sizeof s1, stdin);
printf(s1);

expand(s1, s2);
}

void expand(char s1[], char s2[])
{
	int i_check = 0;
	bool startup = false;

	for (int i = 0; s1[i] != '\n'; i++)
	{
		if (s1[i] == '-')
		{
			if (!startup)
			{
				s2[i_check++] = s1[i];
			}
			else if (s1[i - 1] < s1[i + 1])
			{
				if (((s1[i - 1] > 47) && (s1[i + 1] < 58)) || ((s1[i - 1] > 64) && (s1[i + 1] < 91)) || ((s1[i - 1] > 96) && (s1[i + 1] < 123)))
				{
					//i_check++;
					for (int i_1 = (int)s1[i - 1] + 1; i_1 < (int)s1[i + 1];i_1++, i_check++)
					{
						s2[i_check] = i_1;
					}
					printf("\naz|AZ|09 complete list:\n");
				}
			}
			else if (((s1[i + 1] > 47) && (s1[i - 1] < 58)) || ((s1[i + 1] > 64) && (s1[i - 1] < 91)) || ((s1[i + 1] > 96) && (s1[i - 1] < 123)))
			{
				//i_check++;
				for (int i_1 = (int)s1[i - 1] - 1; i_1 > (int)s1[i + 1];i_1--, i_check++)
				{
					s2[i_check] = i_1;
				}
				printf("\nza|ZA|09 complete list\n");
			}
		}
		else
		//if (s1[i-1] != '-')
		{
			startup = true;
			s2[i_check++] = s1[i];
		}
	}
	s2[i_check++] = '\n';
	s2[i_check++] = '\0';

	printf("\n");
	printf(s2);
	printf("\n");

}

void zadacha3_6()
{
	int s_width = 10;
	int n = -12345678;
	char s[20];

	//printf("Please inpit integer value:\n");
	itoa_02(n, s, s_width);



	printf("\nreverse value with blanks if nesesary\n");
	printf(s);
}

void itoa_02(int n, char s[], int s_width)
{
	int i, sign;
	sign = n;
	if (sign  < 0)	// record sign 
		n = -n;			// make n positive
	i = 0;
	do
	{		// generate digits in reverse order
		s[i++] = n % 10 + '0';	// get next digit 
	} while ((n /= 10) > 0);	// delete it 

	if (sign < 0)
	{
		s[i++] = '-';
	}

	while (i < 10)
	{
		s[i++] = ' ';
	}


	s[i] = '\n';
	s[i + 1] = '\0';

	//printf(s);
	reverse(s);


	//printf("\n");
	//printf(s);
}

void reverse(char s[])
{
	char temp;
	int i = 0;
	while (s[i] != '\n')
		++i;
	int j = 0;
	while (i >j)
	{

		i--;
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;

		j++;
	}
}


