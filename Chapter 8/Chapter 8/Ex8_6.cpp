
#include<stdio.h>
#include<stdlib.h>

void *calloc_2(unsigned, unsigned);



int main() 
{
	char *p = NULL;
	int i = 0;
	unsigned params;

	printf("Please input number of values you want to use:");
	scanf_s("%d", &params);

	fseek(stdin, 0, SEEK_END);

	p = (char*)calloc_2(params, sizeof *p);
	if (NULL == p) 
	{
		printf("calloc_2 returned NULL");
	}
	else {
		for (i = 0; i <= params; i++)
		{
			printf("%x", p[i]);
			if (i % 8 == 7) 
			{
				printf("\n");
			}
		}
		printf("\n");
		free(p);
	}

	getchar();
	return 0;
}

void *calloc_2(unsigned n, unsigned size)
{
	unsigned i, size_bytes;
	char *p, *q;

	size_bytes = n * size;
	p = q = (char *)malloc(size_bytes);

	if (p != NULL)
	{
		for (i = 0; i < size_bytes; i++)
		{
			*p++ = 0;
		}
	}
	return q;

}