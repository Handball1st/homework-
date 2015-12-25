#include <iostream>
#include <cstdio>
#include "string.h"

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    const int primeNumber = 239;
    String currentString = {nullptr, nullptr, 0, 0, nullptr};
    HashList hashTable[primeNumber];
    for (int i = 0; i < primeNumber; ++i)
    {
        hashTable[i] = {nullptr, nullptr, 0};
    }
    bool isEOF = 0;
    while (!isEOF)
    {
        input(&currentString, isEOF);
        //addToHashTable(&currentString, &hashTable, primeNumber);
    }
    return 0;
}
