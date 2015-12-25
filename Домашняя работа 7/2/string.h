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

void debugOutput(String *string);
void create(String *string, char currentString[]);
void deleteString(String *string);
String clone(String *string);

