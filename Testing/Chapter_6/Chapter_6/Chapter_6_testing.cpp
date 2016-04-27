#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH    20
#define MAX_TEXT_LENGTH 1000
//#define TRUE                1
//#define FALSE               0

						// Structure defining a count of the occurrences of a given word 
struct WordCounter
{
	char *word;
	int word_count;
	struct WordCounter *pNext;                        // Pointer to the next word counter in the list 
};

							// Function prototypes 
void addWord(char *pWord);                          // Adds a word to the list or updates exisiting word 
int is_separator(char ch);                          // Tests for a separator character 
void show(struct WordCounter *pWordcounter);        // Outputs a word and its count of occurrences 
struct WordCounter* createWordCounter(char *word);  // Creates a new WordCounter structure 

													// Global variables 
struct WordCounter *pStart = NULL;                  // Pointer to first word counter in the list 
void strncpy_2(char[], char[], int size = MAX_WORD_LENGTH, int n = -1);

int main()
{
	char text[MAX_TEXT_LENGTH];				// Stores input text        
	char buffer[MAX_WORD_LENGTH];			// Buffer to hold a word    
	size_t i = 0;							// Index to text            
	int len = 0;							// Word length               
	struct WordCounter *pCounter = NULL;	// Pointer to a word counter

											// Read the text from the keyboard 
	printf("Enter the text:\n");
	fgets(text,sizeof text, stdin);

	// Extract the words from the text
	while (text[i] != '\0')
	{
		// Skip over separators 
		while (is_separator(text[i]))
		{
			++i;
		}
		// It is either the end of the string or the start of a word    
		// As long as it is not the string terminator copy the character
		len = 0;              // Reset count   
		while ((!is_separator(text[i])) && (text[i] != '\0'))
		{
			buffer[len++] = text[i++];
		}
		if (len>0)               // Check we have some characters in the word 
		{
			buffer[len] = '\0';   // We reached the end of a word so add terminator 
			addWord(buffer);      // Add the word to the list 
		}
	}

	// List the words and their counts 
	pCounter = pStart;
	while (pCounter != NULL)
	{
		show(pCounter);
		pCounter = pCounter->pNext;
	}
	printf("\n");

	// Free the memory that we allocated 
	pCounter = pStart;
	while (pCounter != NULL)
	{
		free(pCounter->word);        // Free space for the word 
		pStart = pCounter;           // Save address of current 
		pCounter = pCounter->pNext;  // Move to next counter    
		free(pStart);                // Free space for current  
	}

	getchar();
	return 0;
}

// Returns TRUE if the argument is a separator character and FALSE otherwise 
int is_separator(char ch)
{
	// Separators are space, comma, colon, semicolon, double quote, question mark, exclamation, and period 
	static char separators[] = { ' ' , ',',':' , '\"', '?' , '!' , '.' };
	int i = 0;

	for (i = 0; i < sizeof separators; i++)
	{
		if (ch == separators[i])
		{
			return true;
		}
	}

	return false;
}

void show(struct WordCounter *pWordcounter)
{
	// output the word left-justified in a fixed field width followed by the count 
	printf("\n%-20s   %5d", pWordcounter->word, pWordcounter->word_count);
}

void addWord(char *word)
{
	struct WordCounter *pCounter = NULL;
	struct WordCounter *pLast = NULL;

	if (pStart == NULL)
	{
		pStart = createWordCounter(word);
		return;
	}

	// If the word is in the list, increment its count 
	pCounter = pStart;
	while (pCounter != NULL)
	{
		if (strcmp(word, pCounter->word) == 0)
		{
			++pCounter->word_count;
			return;
		}
		pLast = pCounter;            // Save address of last in case we need it 
		pCounter = pCounter->pNext;  // Move pointer to next in the list        
	}

	// If we get to here it's not in the list - so add it 
	pLast->pNext = createWordCounter(word);
}

/* Create and returns a new WordCounter object for the argument */
struct WordCounter* createWordCounter(char *word)
{
	struct WordCounter *pCounter = NULL;
	pCounter = (struct WordCounter*)malloc(sizeof(struct WordCounter));
	pCounter->word = (char*)malloc(strlen(word) + 1);
	strncpy_2(pCounter->word, word);
	pCounter->word_count = 1;
	pCounter->pNext = NULL;
	return pCounter;
}

void strncpy_2(char str1[], char str2[], int size, int n)
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

	} while ((str2[i] != '\0') && ((i<n) | (n == -1)));
	str1[i] = '\0';
}