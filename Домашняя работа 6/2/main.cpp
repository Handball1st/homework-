#include <iostream>
#include <cstdio>
#include <cstring>
#include "tree.h"

using namespace std;

bool isDigit(char current)
{
    return ('0' <= current && current <= '9');
}

bool isOperation(char current)
{
    int size = 4;
    char dictionary[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < size; ++i)
    {
        if (current == dictionary[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    const int maxSize = 1e2;
    char currentChar = '?';
    char dictionary[maxSize][maxSize];
    int sizeOfDictionary = 0;
    int sizeOfString = 0;
    while ((currentChar = getc(stdin)) != EOF)
    {
        if (isOperation(currentChar) || isDigit(currentChar))
        {
            dictionary[sizeOfDictionary][sizeOfString++] = currentChar;
        }
        else if (currentChar == '(')
        {
            dictionary[++sizeOfDictionary][sizeOfString = 0] = currentChar;
            sizeOfDictionary++;
            sizeOfString = 0;
        }
        else if (currentChar == ' ')
        {
            sizeOfString = 0;
            sizeOfDictionary++;
        }
    }
    sizeOfDictionary++;
    Tree currentTree = {nullptr, 0};
    for (int i = 0; i < sizeOfDictionary; ++i)
    {
        for (int j = 0; j < strlen(dictionary[i]); ++j)
        {
            cout << dictionary[i][j];
        }
        cout << endl;
    }
    /*for (int i = 0; i < sizeOfDictionary; ++i)
    {
        add(&currentTree, dictionary[i]);
        //printAscending(&currentTree);
    }*/
    return 0;
}
