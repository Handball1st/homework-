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

void add(String *addToString, char character)
{
    if (character == '\n')
    {
        return;
    }
    Char *currentChar = new Char{character, nullptr};
    addToString->size++;
    if (addToString->size == 1)
    {
        addToString->head = currentChar;
        addToString->tail = currentChar;
        return;
    }
    if (addToString->head->next == nullptr)
    {
        addToString->head->next = currentChar;
    }
    addToString->tail->next = currentChar;
    addToString->tail = currentChar;
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

void addToHashTable(String *currentString, HashList hashTable[], unsigned long long primeNumber)
{
    if (isEmpty(currentString))
    {
        return;
    }
    unsigned long long currentIndex = currentString->hash % primeNumber;
    for (int i = 0; i < primeNumber; ++i)
    {
        debugOutput(hashTable[i].head);
        cout << endl;
    }
    cout << endl << endl;
    ++hashTable[currentIndex].size;
    if (hashTable[currentIndex].size == 1)
    {
        Char *currentChar = currentString->head;
        for (int i = 0; i < sizeOfString(currentString); ++i)
        {
            add(hashTable[currentIndex].head, currentChar->value);
            currentChar = currentChar->next;
        }
        return;
    }
    /*if (hashCell->head->next == nullptr)
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
    cout << endl;*/
}

/*String clone(String *currentString, int left, int right)
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

bool isEqual(String *currentString)
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

