#include <iostream>
#include "sortedList.h"
#include "tree.h"

using namespace std;

void add(List *currentList, Character currentChar)
{
    ++currentList->size;
    TreeNode root = {currentChar, nullptr, nullptr};
    ListElement *currentListElement = new ListElement{root, nullptr};
    if (currentList->size == 1)
    {
        currentList->head = {root, nullptr};
        currentList->tail = {root, nullptr};
        return;
    }
    if (currentList->head->next == nullptr)
    {
        currentList->head->next = root;
    }
    currentList->tail->next =
}


