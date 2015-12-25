#include <iostream>
#include <cstdio>
#include <cstring>
#include "string.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int type = -1;
    const int maxSize = 1e3;
    String currentString = {nullptr, nullptr, 0};
    while (type != 0)
    {
        cout << "1 - создать строку" << endl
             << "2 - удалить строку" << endl
             << "3 - копировать строку" << endl
             << "4 - добавить строку" << endl
             << "5 - сравнить строки" << endl
             << "6 - вычислить длину строки" << endl
             << "7 - проверка на путстоту" << endl
             << "8 - выделение подстроки" << endl
             << "9 - преобразование к char*" << endl;
        cout << "Введите номер операции: ";
        cin >> type;
        switch (type)
        {
            case 1:
            {
                cout << "Введите строку: ";
                input(&currentString);
                cout << "Строка создана." << endl << endl;
                break;
            }
            case 2:
            {
                deleteString(&currentString);
                cout << "Строка удалена." << endl << endl;
                break;
            }
            case 3:
            {
                String cloneString = clone(&currentString, 0, sizeOfString(&currentString));
                cout << "Строка скопирована." << endl << endl;
                break;
            }
            case 4:
            {
                cout << "Введите строку: ";
                input(&currentString);
                cout << "Строка добавлена" << endl << endl;
                break;
            }
            case 5:
            {
                cout << "Введите строку: ";
                bool equalStrings = isEqual(&currentString);
                cout << "Введенная строка ";
                if (!equalStrings)
                {
                    cout << "не ";
                }
                cout << "равна данной" << endl << endl;
                break;
            }
            case 6:
            {
                cout << "Длина текущей строки: " << sizeOfString(&currentString) << endl << endl;
                break;
            }
            case 7:
            {
                cout << "Текущая строка ";
                if (isEmpty(&currentString))
                {
                    cout << "не ";
                }
                cout << "пустая." << endl << endl;
                break;
            }
            case 8:
            {
                if (isEmpty(&currentString))
                {
                    cout << "Выделение подстроки невозможно." << endl << endl;
                }
                cout << "Введите два числа в диапазоне от 1 до " << sizeOfString(&currentString) << ": ";
                int left = 0;
                int right = 0;
                cin >> left >> right;
                String newString = clone(&currentString, left - 1, right - 1);
                cout << "Подстрока с " << left << "-го по " << right << "-й символ: ";
                debugOutput(&newString);
                cout << endl << endl;
                break;
            }
            case 9:
            {
                char* convertedString = transformation(&currentString);
                cout << "Строка преобразована к char*." << endl << endl;
                break;
            }
        }
    }
    return 0;
}
