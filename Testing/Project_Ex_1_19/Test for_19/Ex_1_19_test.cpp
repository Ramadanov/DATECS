#include <stdio.h>


int  main()
{
	char line[1000];
	char templine[1000];
	int linelenght = 0;

	printf("write youre line:\n");
	fgets(line, sizeof line, stdin);

	int i = 0;
	while (line[i] != '\0')
	{
		//printf("%d\n", line[i]);
		if ((line[i] != '\n') && (line[i] != '\t')&&(line[i] != ' '))
		{
			templine[linelenght] = line[i];
			linelenght++;	
		}
		else
		{
			//printf("\n%d\t test\n", linelenght);
			while (linelenght > 0)
			{	
				//printf("\%d\t test\n", linelenght);
				
				linelenght--;
			//	printf("\t%d test\t", linelenght);
				char tempchar;
				tempchar = char(templine[linelenght]);
				printf("%c", templine[linelenght]);
	//			linelenght--;
				if (linelenght == 0)
				{
					printf("\n");
				}
			}
		}
		i++;
	}
	getchar();
		return 0;
}