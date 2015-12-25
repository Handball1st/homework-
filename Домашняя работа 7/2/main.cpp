#include <iostream>
#include "string.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int type = -1;
    const int maxSize = 1e3;
    String string = {nullptr, nullptr, 0};
    /*Char *chart = new Char{'A', nullptr};
    string.head = string.tail = chart;
    chart = new Char{'B', nullptr};
    string.tail->next = chart;
    string.tail = string.tail->next;
    string.size = 2;
    debugOutput(&string);*/
    while (type != 0)
    {
        cout << "1 - создать строку" << endl << "2 - удалить строку" << endl << "3 - копировать строку" << endl <<
        "4 - добавить строку" << endl << "5 - сравнить строки" << endl << "6 - вычислить длину строки" << endl <<
        "7 - проверка на путстоту" << endl << "8 - выделение подстроки" << endl << "9 - преобразование к char*" << endl;
        cout << "Введите номер операции: ";
        cin >> type;
        switch (type)
        {
            case 1:
            {
                char currentString[maxSize];
                cout << "Введите строку: ";
                cin >> currentString;
                create(&string, currentString);
                debugOutput(&string);
                break;
            }
            case 2:
            {
                deleteString(&string);
                break;
            }
            case 3:
            {
                String cloneString = clone(&string);
                break;
            }
        }
    }
    return 0;
}
