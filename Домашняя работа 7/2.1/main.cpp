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
        cout << "1 - ������� ������" << endl
             << "2 - ������� ������" << endl
             << "3 - ���������� ������" << endl
             << "4 - �������� ������" << endl
             << "5 - �������� ������" << endl
             << "6 - ��������� ����� ������" << endl
             << "7 - �������� �� ��������" << endl
             << "8 - ��������� ���������" << endl
             << "9 - �������������� � char*" << endl;
        cout << "������� ����� ��������: ";
        cin >> type;
        switch (type)
        {
            case 1:
            {
                cout << "������� ������: ";
                input(&currentString);
                cout << "������ �������." << endl << endl;
                break;
            }
            case 2:
            {
                deleteString(&currentString);
                cout << "������ �������." << endl << endl;
                break;
            }
            case 3:
            {
                String cloneString = clone(&currentString, 0, sizeOfString(&currentString));
                cout << "������ �����������." << endl << endl;
                break;
            }
            case 4:
            {
                cout << "������� ������: ";
                input(&currentString);
                cout << "������ ���������" << endl << endl;
                break;
            }
            case 5:
            {
                cout << "������� ������: ";
                bool equalStrings = isEqual(&currentString);
                cout << "��������� ������ ";
                if (!equalStrings)
                {
                    cout << "�� ";
                }
                cout << "����� ������" << endl << endl;
                break;
            }
            case 6:
            {
                cout << "����� ������� ������: " << sizeOfString(&currentString) << endl << endl;
                break;
            }
            case 7:
            {
                cout << "������� ������ ";
                if (isEmpty(&currentString))
                {
                    cout << "�� ";
                }
                cout << "������." << endl << endl;
                break;
            }
            case 8:
            {
                if (isEmpty(&currentString))
                {
                    cout << "��������� ��������� ����������." << endl << endl;
                }
                cout << "������� ��� ����� � ��������� �� 1 �� " << sizeOfString(&currentString) << ": ";
                int left = 0;
                int right = 0;
                cin >> left >> right;
                String newString = clone(&currentString, left - 1, right - 1);
                cout << "��������� � " << left << "-�� �� " << right << "-� ������: ";
                debugOutput(&newString);
                cout << endl << endl;
                break;
            }
            case 9:
            {
                char* convertedString = transformation(&currentString);
                cout << "������ ������������� � char*." << endl << endl;
                break;
            }
        }
    }
    return 0;
}
