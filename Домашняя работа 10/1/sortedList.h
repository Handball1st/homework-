#pragma once

struct ListElement
{
    Tree currentTree;
    ListElement *next;
};

struct List
{
    ListElement *head;
    ListElement *tail;
    int size;
};

void add(List *currentList, int value);
ListElement remove(List *currentList, int value);
//void output(List *currentList);
