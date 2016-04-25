#include<stdio.h>



static char daytab[2][13] = {
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static char daytab_0[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char daytab_1[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static char *daytab_p[2] = { daytab_0,  daytab_1 };


int main()
{


	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	//int a = daytab_p[0][0][2];
	printf("POINTER %d", *(*(daytab_p +0) +5));

	getchar();




	return 0;
	
}