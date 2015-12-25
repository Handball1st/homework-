#pragma once

struct Char
{
    char value;
    Char *next;
};

struct String
{
    Char *head;
    Char *tail;
    unsigned long long hash;
    int size;
    String *next;
};

struct HashList
{
    String *head;
    String *tail;
    int size;
};

void debugOutput(String *currentString);
void add(String *currentString, char character);
void deleteString(String *currentString);
String clone(String *currentString, int left, int right);
int sizeOfString(String *currentString);
void input(String *currentString, bool &isEOF);
bool isEqual(String *currentString);
bool isEmpty(String *currentString);
char* transformation(String *currentString);
void addToHashTable(String *currentString, HashList *hashTable[], int primeNumber);
