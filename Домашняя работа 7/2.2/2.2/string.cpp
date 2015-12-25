#include "string.h"
#include <cstdio>
#include <iostream>

using namespace std;

void debugOutput(String *currentString)
{
	Char *currentChar = currentString->head;
	const int sizeOfString = currentString->size;
	for (int i = 0; i < sizeOfString; ++i)
	{
		cout << currentChar->value;
		currentChar = currentChar->next;
	}
}

void deleteString(String *currentString)
{
	Char *currentChar = currentString->head;
	while (currentChar != nullptr)
	{
		Char *tempForDelete = currentChar->next;
		delete currentChar;
		currentChar = tempForDelete;
	}
	delete currentChar;
}

int sizeOfString(String *currentString)
{
	return currentString->size;
}

bool isEmpty(String *currentString)
{
	return (sizeOfString(currentString));
}

void add(String *currentString, char character)
{
	if (character == '\n')
	{
		return;
	}
	Char *currentChar = new Char{ character, nullptr };
	currentString->size++;
	if (currentString->size == 1)
	{
		currentString->head = currentChar;
		currentString->tail = currentChar;
		return;
	}
	if (currentString->head->next == nullptr)
	{
		currentString->head->next = currentChar;
	}
	currentString->tail->next = currentChar;
	currentString->tail = currentChar;
}

void input(String *currentString)
{
	char character = '?';
	int count = 0;
	while ((character = getchar()) != '\n' || count == 0)
	{
		add(currentString, character);
		++count;
	}
}

String clone(String *currentString, int left, int right)
{
	String newString = { nullptr, nullptr, 0 };
	Char *currentChar = currentString->head;
	int sizeOfCurrentString = sizeOfString(currentString);
	for (int i = 0; i < sizeOfCurrentString; ++i)
	{
		if (left <= i && i <= right)
		{
			add(&newString, currentChar->value);
		}
		currentChar = currentChar->next;
	}
	return newString;
}

bool isEqual(String *currentString)
{
	String newString = { nullptr, nullptr, 0 };
	input(&newString);
	if (sizeOfString(&newString) != sizeOfString(currentString))
	{
		return 0;
	}
	Char *currentChar = currentString->head;
	Char *newChar = newString.head;
	for (int i = 0; i < sizeOfString(currentString); ++i)
	{
		if (currentChar->value != newChar->value)
		{
			return 0;
		}
		currentChar = currentChar->next;
		newChar = newChar->next;
	}
	return 1;
}

char* transformation(String *currentString)
{
	Char *currentChar = currentString->head;
	const int maxSize = int(1e2);
	char result[maxSize];
	for (int i = 0; i < sizeOfString(currentString); ++i)
	{
		result[i] = currentChar->value;
		currentChar = currentChar->next;
	}
	return result;
}

