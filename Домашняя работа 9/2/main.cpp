#include <iostream>
#include <cstring>

using namespace std;

void output(char currentString[])
{
    for (int i = 0; i < strlen(currentString); ++i)
    {
        cout << currentString[i];
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int primeNumber = 37;
    const int maxSize = 1e2;
    char firstString[maxSize];
    char secondString[maxSize];
    cout << "Введите строку: ";
    cin >> firstString;
    cout << "Введите строку образец: ";
    cin >> secondString;
    unsigned long long primeNumberInPower[maxSize];
    primeNumberInPower[0] = 1;
    for (int i = 1; i < strlen(firstString); ++i)
    {
        primeNumberInPower[i] = primeNumberInPower[i - 1] * primeNumber;
    }
    unsigned long long hashOfFirstString[maxSize];
    hashOfFirstString[0] = 0;
    for (int i = 0; i <= strlen(firstString); ++i)
    {
        hashOfFirstString[i] = primeNumberInPower[i] * firstString[i];
        if (i)
        {
            hashOfFirstString[i] += hashOfFirstString[i - 1];
        }
    }
    unsigned long long hashOfSecondString = 0;
    for (int i = 0; i < strlen(secondString); ++i)
    {
        hashOfSecondString += primeNumberInPower[i] * secondString[i];
    }
    bool isFindSubstring = 0;
    for (int i = 0; i + strlen(secondString) - 1 < strlen(firstString); ++i)
    {
        unsigned long long currentHash = hashOfFirstString[i + strlen(secondString) - 1];
        if (i)
        {
            currentHash -= hashOfFirstString[i - 1];
        }
        if (currentHash == hashOfSecondString * primeNumberInPower[i])
        {
            isFindSubstring = 1;
        }
    }
    cout << "Строка ";
    output(secondString);
    if (!isFindSubstring)
    {
        cout << " не";
    }
    cout << " является подсрокой строки ";
    output(firstString);
    return 0;
}
