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
        cout << "1 - ������� ������" << endl << "2 - ������� ������" << endl << "3 - ���������� ������" << endl <<
        "4 - �������� ������" << endl << "5 - �������� ������" << endl << "6 - ��������� ����� ������" << endl <<
        "7 - �������� �� ��������" << endl << "8 - ��������� ���������" << endl << "9 - �������������� � char*" << endl;
        cout << "������� ����� ��������: ";
        cin >> type;
        switch (type)
        {
            case 1:
            {
                char currentString[maxSize];
                cout << "������� ������: ";
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
