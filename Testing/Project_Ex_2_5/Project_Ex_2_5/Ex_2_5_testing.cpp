#include <stdio.h>

int Chech_for_character(char[], char[]); //function for squeezin the string 


int main()
	{
		int const lenght = 100;
		char s1[lenght];
		char s2[lenght];
		int char_position;
		printf("Input first string :\n");
		fgets(s1, sizeof s1, stdin);



		printf("input second string :\n");
		fgets(s2, sizeof s2, stdin);

		char_position = Chech_for_character(s1, s2);

		printf("First chracter that ocures from sreing S2 in String S1 ocures in \n\tposition: %d\n \tS1[%d] = %c", char_position, char_position, s1[char_position]);
		
		
		



		getchar();

		return 0;
	}




	int Chech_for_character(char s1[], char s2[])
	{

		bool endloop = false;
		int i, j;

		for (int k = 0; (s2[k] != '\0') ; k++) //&& (endloop == false)
		{
			for (i = 0; s1[i] != '\0'; i++)
			{
				if (s1[i] == s2[k])
				{
					return i;
					//endloop = true;
				}
			}


		}	
	}

