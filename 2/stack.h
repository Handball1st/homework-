#pragma once

struct ListElement
{
    char value;
    ListElement *next;
};

struct Stack
{
    ListElement *head;
    int size;
};

void push(Stack *currentStack, char value);
void pop(Stack *currentStack);
char haveCurrentHeadOfStack(Stack *currentStack);
