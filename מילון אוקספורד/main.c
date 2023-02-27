#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


//---------------------------------------------------------------------------------------
//                                    Oxford Dictionary
//                                   -------------------
//
// General : The program prints a menu and by the chosen option does for:
//			 1. Adding a word to the dictionary and sends back to the menu.
//			 2. Searching for a definition of a word in the dictionary
//				and sends back to the menu.
//			 3. printing all the words in the dictionary that start with a
//				certain letter and sends back to the menu.
//			 4. Print all Dictionary and sends back to the menu.
//			 Any othet key, prints it coudn't find the option entered
//			 and sends back to the menu.
//
// Input   : A file which represents the dictionary.
// 
// Process : The program gets a number and sends you to the right procedure to continue.
//
// Output  : According to the procedure you have been sent to.
// 
//---------------------------------------------------------------------------------------
// Programmer : Ido Itzhaki
// Student No : 15
// Date       : 23.11.2022
//---------------------------------------------------------------------------------------
void main()
{
	int Number;

	printf("HELLO! Wellcome to Ido's dictionary\n");
	printf("Options Menu:\n");
	printf("Type in 0 to - exit\n");
	printf("Type in 1 to - Add New Word\n");
	printf("Type in 2 to - Get Word Defenition\n");
	printf("Type in 3 to - Print Words statrting with a specific letter\n");
	printf("Type in 4 to - Print all dictionary\n");
	printf("\n");
	scanf("%d", &Number);

	switch (Number)
	{
	case 0:
		printf("THANK YOU for visiting!\nhave a good day and you are welcome back anytime!\n");
		break;
	case 1:
		InsertWord();
		printf("\n");
		main();
		break;
	case 2:
		GetWordDef();
		main();
		break;
	case 3:
		PrintWordsByLetter();
		printf("\n");
		main();
		break;
	case 4:
		PrintAllDictionary();
		printf("\n");
		main();
		break;
	default:
		printf("Sorry! We could'nt find what you where looking for.\nplease try again\n\n");
		main();
		break;
	}
}