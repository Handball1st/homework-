#include <iostream>
#include <cstdio>
#include "string.h"

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int primeNumber = 239;
    String currentString = {nullptr, nullptr, 0, 0, nullptr};
    String *newString = new String{nullptr, nullptr, 0, 0, nullptr};
    HashList hashTable[primeNumber];
    for (int i = 0; i < primeNumber; ++i)
    {
        hashTable[i] = {newString, newString, 0};
    }
    bool isEOF = 0;
    while (!isEOF)
    {
        input(&currentString, isEOF);
        if (!isEmpty(&currentString))
        {
            addToHashTable(&currentString, hashTable, primeNumber);
        }
    }
    return 0;
}
