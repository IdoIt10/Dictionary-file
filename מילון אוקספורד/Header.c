#pragma once
#include "Header.h";

// Global defenition
char* gFileName = "Dictionary.txt";

//---------------------------------------------------------------------------------------
//                                        Insert Word
//                                       -------------
//
// General      : The procedure gets a word and it's definition and sends them 
//				  to the function called "AddNewWord".
//
// Parameters   : None
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void InsertWord()
{
	// Variable definitions
	char* iszNewWord[SizeOfWord];
	char* iszWordDef[SizeOfDef];

	// Code section

	/*iszNewWord = malloc(SizeOfWord);
	iszWordDef = malloc(SizeOfDef);*/

	printf("Enter a word\n");
	scanf("%s", &iszNewWord);

	printf("Enter word definition\n");
	scanf("%s", &iszWordDef);

	AddNewWord(iszNewWord, iszWordDef);
}

//---------------------------------------------------------------------------------------
//                                         GetWordDef
//                                       --------------
//
// General      : The procedure gets a word, sends it to the function called
//				  "GetWordDefenition" and prints the string the function returns.
//
// Parameters   : None
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void GetWordDef()
{
	// Variable definitions
	char* iszNewWord[SizeOfWord];
	char* def;

	// Code section

	printf("Enter a word\n");
	scanf("%s", &iszNewWord);

	def = GetWordDefenition(iszNewWord);

	if (!def)
	{
		printf("Word isn't exist!\n\n");
	}
	else
	{
		printf("%s\n\n", def);
	}
}

//---------------------------------------------------------------------------------------
//                                   Print Words By Letter
//                                  -----------------------
//
// General      : The procedure gets a letter and sends it to
//				  the function called "PrintWordsOf".
//
// Parameters   : None
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void PrintWordsByLetter()
{
	// Variable definition
	char* iszLetter[1];

	// Code section

	printf("Enter a letter\n");
	scanf("%s", iszLetter);

	PrintWordsOf(iszLetter[0]);
}

//---------------------------------------------------------------------------------------
//                                       Add New Word
//                                      --------------
//
// General      : The procedure adds a new word with it's definition
//				  to the current dictionary File.
//
// Parameters   : 
//		iszNewWord - a string which presents the word to add
//		iszWordDef - a string which presents the definition to add
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void AddNewWord(char* iszNewWord, char* iszWordDef)
{
	// Variable definition
	FILE* File;

	// Code section

	// Opening the file for writing at the ending
	File = fopen(gFileName, "at");
	// Alocaiton check
	if (!File)
	{
		perror("ERROR");
		exit(1);
	}

	fprintf(File, "%s %s\n", iszNewWord, iszWordDef);
	fclose(File);
}

//---------------------------------------------------------------------------------------
//                                    Get Word Defenition
//                                   ---------------------
//
// General      : The function finds and returns the right defenition to the gooten word.
//
// Parameters   : 
//		iszWord - a string which presents a word
//
// Return Value : String of: The word - It's defenition
// 
//---------------------------------------------------------------------------------------
char* GetWordDefenition(char* iszWord)
{
	// Variable definitions
	char* iszWordBuffer[SizeOfWord];
	char* iszDef[SizeOfDef];
	char* iszFinalWordPlusDef;
	FILE* File;

	// Code section
	
	// Opening the file for reading
	File = fopen(gFileName, "rt");
	// Alocaiton check
	if (!File)
	{
		perror("ERROR");
		exit(1);
	}

	//Going throuth all the file
	while (!feof(File))
	{
		fscanf(File, "%s %s\n", &iszWordBuffer, &iszDef);
		//checking if reached the desired word
		if (!strcmp(iszWord, iszWordBuffer))
		{
			fclose(File);
			iszFinalWordPlusDef = malloc(sizeof(iszWordBuffer));
			strcpy(iszFinalWordPlusDef, iszWordBuffer);
			JoinStrings(iszFinalWordPlusDef, iszDef);
			return iszFinalWordPlusDef;
			break;
		}
	}
	fclose(File);
	return NULL;
}

//---------------------------------------------------------------------------------------
//                                    Get Word Defenition
//                                   ---------------------
//
// General      : The procedure changes the first string to a string which look this:
//				  First string - Second string.
//
// Parameters   : 
//		iopszFirstString - a string
//		iszSecondString  - a string
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void JoinStrings(char** iopszFirstString, char* iszSecondString)
{
	// Code section

	strcat(iopszFirstString, "-");
	strcat(iopszFirstString, iszSecondString);
}

//---------------------------------------------------------------------------------------
//										 PrintWordsOf
//                                      --------------
//
// General      : The procedure prints all the words in the dictionary that starts with
//				  the letter the procedure gets.
//
// Parameters   : 
//		icStartChar - a character
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------
void PrintWordsOf(char icStartChar)
{
	// Variable definitions
	char Word[SizeOfWord];
	char Def[SizeOfDef];
	FILE* File;

	// Code section

	// Opening the file for reading
	File = fopen(gFileName, "rt");
	// Alocaiton check
	if (!File)
	{
		perror("ERROR");
		exit(1);
	}

	//Going throuth all the file
	while (!feof(File))
	{
		fscanf(File, "%s %s\n", &Word, &Def);
		//checking if reached a desired word
		if (icStartChar == Word[0])
		{
			printf("%s\n", Word);
		}
	}
	fclose(File);
}

//---------------------------------------------------------------------------------------
//								     Print All Dictionary
//                                  -----------------------
//
// General      : The procedure prints all the dictionary.
//
// Parameters   : None
//
// Return Value : None (procedure)
// 
//---------------------------------------------------------------------------------------

void PrintAllDictionary()
{
	// Variable definitions
	char* iszWordBuffer[SizeOfWord];
	char* iszDef[SizeOfDef];
	FILE* File;

	// Code section

	// Opening the file for reading
	File = fopen(gFileName, "rt");
	// Alocaiton check
	if (!File)
	{
		perror("ERROR");
		exit(1);
	}

	//Going throuth all the file
	while (!feof(File))
	{
		fscanf(File, "%s %s\n", &iszWordBuffer, &iszDef);
		JoinStrings(iszWordBuffer, iszDef);
		printf("%s\n", iszWordBuffer);
	}
	fclose(File);
}
