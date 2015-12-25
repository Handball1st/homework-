#include <iostream>
#include "stack.h"

void push(Stack *currentStack, char value)
{
    ListElement *newElement = new ListElement {value, (currentStack->size) ? currentStack->head : nullptr};
    currentStack->head = newElement;
    ++currentStack->size;
}

void pop(Stack *currentStack)
{
    if (currentStack->size != 0)
    {
        currentStack->head = currentStack->head->next;
        --currentStack->size;
    }
}

char haveCurrentHeadOfStack(Stack *currentStack)
{
    char headElement = currentStack->head->value;
    return headElement;
}
