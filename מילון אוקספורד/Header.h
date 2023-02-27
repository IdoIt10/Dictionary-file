#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define definitions
#define SizeOfWord 20
#define SizeOfDef 200

// Function prototypes
void InsertWord();
void GetWordDef();
void PrintWordsByLetter();
void AddNewWord(char* iszNewWord, char* iszWordDef);
char* GetWordDefenition(char* iszWord);
void JoinStrings(char** iopszFirstString, char* iszSecondString);
void PrintWordsOf(char icStartChar);
void PrintAllDictionary();