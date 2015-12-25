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
    currentString->size = 0;
    currentString->tail = nullptr;
    currentString->head = nullptr;
}

int sizeOfString(String *currentString)
{
    return currentString->size;
}

bool isEmpty(String *currentString)
{
    return (!sizeOfString(currentString));
}

void add(String *currentString, char character)
{
    if (character == '\n')
    {
        return;
    }
    Char *currentChar = new Char{character, nullptr};
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

bool isEndOfWord(char character)
{
    char endOfWord[3] = {' ', '\n', '\r'};
    for (int i = 0; i < 3; ++i)
    {
        if (character == endOfWord[i])
        {
            return 1;
        }
    }
    return 0;
}

unsigned long long haveHash(String *currentString)
{
    unsigned long long result = int(1e9 + 7);
    const int primeNumber = 37;
    Char *currentChar = currentString->head;
    while (currentChar != nullptr)
    {
        result += result * primeNumber + currentChar->value;
        currentChar = currentChar->next;
    }
    return result;
}

void input(String *currentString, bool &isEOF)
{
    char character = '?';
    deleteString(currentString);
    while (!isEndOfWord(character = getc(stdin)) && !isEOF)
    {
        if (character == EOF)
        {
            isEOF = 1;
            break;
        }
        add(currentString, character);
    }
    if (!isEOF)
    {
        currentString->hash = haveHash(currentString);
    }
}

/*void addToHashCell(String *currentString, HashList *hashCell)
{
    ++hashCell->size;
    cout << hashCell->size << endl;
    if (hashCell->size == 1)
    {
        Char *currentChar = currentString->head;
        while (currentChar != nullptr)
        {
            add(hashCell->head, currentChar->value);
            add(hashCell->tail, currentChar->value);
        }
        return;
    }
    if (hashCell->head->next == nullptr)
    {
        hashCell->head->next = currentString;
    }
    hashCell->tail->next = currentString;
    hashCell->tail = currentString;
    String *curString = hashCell->head;
    while (curString != nullptr)
    {
        debugOutput(curString);
        cout << " ";
        curString = curString->next;
    }
    cout << endl;
}

void addToHashTable(String *currentString, HashList *hashTable[], unsigned long long primeNumber)
{
    unsigned long long currentIndex = currentString->hash % primeNumber;
    addToHashCell(currentString, hashTable[currentIndex]);
}*/

String clone(String *currentString, int left, int right)
{
    String newString = {nullptr, nullptr, 0};
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

/*bool isEqual(String *currentString)
{
    String newString = {nullptr, nullptr, 0};
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
}*/

char* transformation(String *currentString)
{
    Char *currentChar = currentString->head;
    char* result;
    for (int i = 0; i < sizeOfString(currentString); ++i)
    {
        result[i] = currentChar->value;
        currentChar = currentChar->next;
    }
    return result;
}

