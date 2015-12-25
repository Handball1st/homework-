#include <iostream>
#include <cstring>
#include <cstdio>
#include "sortedList.h"
#include "tree.h"

using namespace std;

struct Character
{
    char value;
    int frequence;
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int maxSize = 1e2;
    const int numberOfCharacters = 256;
    cout << "¬ведите строку: ";
    char currentString[maxSize];
    cin.get(currentString, maxSize);
    int numberOfCurrentCharacter[numberOfCharacters];
    for (int i = 0; i < numberOfCharacters; ++i)
    {
        numberOfCurrentCharacter[i] = 0;
    }
    for (int i = 0; i < strlen(currentString); ++i)
    {
        ++numberOfCurrentCharacter[currentString[i]];
    }
    Character alphabet[numberOfCharacters];
    int alphabetSize = 0;
    for (int i = 0; i < numberOfCharacters; ++i)
    {
        if (numberOfCurrentCharacter[i])
        {
            alphabet[alphabetSize++] = {i, numberOfCurrentCharacter[i]};
        }
    }
    const int infinum = -1e9;
    List currentList = {nullptr, nullptr, 0};
    add(&currentList, infinum);
    return 0;
}
