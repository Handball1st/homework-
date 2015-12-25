#include "string.h"
#include <cstring>
#include <iostream>

using namespace std;

void debugOutput(String *string)
{
    Char *currentChar = string->head;
    const int sizeOfString = string->size;
    for (int i = 0; i < sizeOfString; ++i)
    {
        cout << currentChar->value;
        currentChar = currentChar->next;
    }
}

void create(String *string, char currentString[])
{
    const int sizeOfCurrentString = strlen(currentString);
    for (int i = 0; i < sizeOfCurrentString; ++i)
    {
        Char *currentChar = new Char{currentString[i], nullptr};
        string->size++;
        if (string->size == 1)
        {
            string->head = currentChar;
            string->tail = currentChar;
            continue;
        }
        string->tail->next = currentChar;
        string->tail = currentChar;
    }
}

void deleteString(String *string)
{
    string->size = 0;
    string->tail = nullptr;
    string->head = nullptr;
}

String clone(String *string)
{
    String newString = {string->head, nullptr, string->size};
    Char *currentChar = string->head;
    const int sizeOfString = string->size;
    for (int i = 0; i < sizeOfString; ++i)
    {
        newString.tail = currentChar;
        currentChar = currentChar->next;
    }
    return newString;
}

