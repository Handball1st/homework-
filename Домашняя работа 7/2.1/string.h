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
    int size;
};

void debugOutput(String *currentString);
void add(String *currentString, char character);
void deleteString(String *currentString);
//String clone(String *currentString);
String clone(String *currentString, int left, int right);
int sizeOfString(String *currentString);
void input(String *currentString);
bool isEqual(String *currentString);
bool isEmpty(String *currentString);
char* transformation(String *currentString);
