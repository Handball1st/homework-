#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Contact
{
    char name[100];
    char number[40];
};

bool isEqual(char string1[], char string2[])
{
    if (strlen(string1) != strlen(string2))
    {
        return 0;
    }
    int n = strlen(string1);
    for (int i = 0; i < n; ++i)
    {
        if (string1[i] != string2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "sdfsf" << endl;
    /*cout << "0 - �����" << endl << "1 - �������� ������ (��� � �������)" << endl << "2 - ����� ������� �� �����"
         << endl << "3 - ����� ��� �� ��������" << endl << "4 - ��������� ������� ������ � ����" << endl;
    ifstream fin("phonebook.txt");
    const int maxSize = int(1e4);
    int n = 0;
    fin >> n;
    Contact phonebook[maxSize];
    for (int i = 0; i < n; ++i)
    {
        fin >> phonebook[i].name >> phonebook[i].number;
    }
    int type = -1;
    while (type != 0)
    {
        const int maxSizeOfNumber = 40;
        const int maxSizeOfName = 100;
        char name[maxSizeOfName];
        char number[maxSizeOfNumber];
        cout << "������� ��� ��������: ";
        cin >> type;
        if (type == 1)
        {
            cout << "������� ��� � �������: ";
            cin >> name >> number;
            for (int i = 0; i < strlen(name); ++i)
            {
                phonebook[n].name[i] = name[i];
            }
            for (int i = 0; i < strlen(number); ++i)
            {
                phonebook[n].number[i] = number[i];
            }
            ++n;
        }
        if (type == 2) /// ����� ������� �� �����
        {
            cout << "������� ��� ��������: ";
            cin >> name;
            for (int i = 0; i < n; ++i)
            {
                if (isEqual(name, phonebook[i].name))
                {
                    cout << "� �������� " << name << " ����� " << phonebook[i].number << "." << endl;
                    break;
                }
            }
        }
        if (type == 3) /// ����� ��� �� ��������
        {
            cout << "������� ����� ��������: ";
            cin >> number;
            for (int i = 0; i < n; ++i)
            {
                if (isEqual(number, phonebook[i].number))
                {
                    cout << "� �������� � ������� " << number << " ��� " << phonebook[i].name << "." << endl;
                    break;
                }
            }
        }
        if (type == 4)
        {
            ofstream fout("phonebook.txt");
            fout << n << endl;
            for (int i = 0; i < n; ++i)
            {
                fout << phonebook[i].name << " " << phonebook[i].number << endl;
            }
            cout << "�������� ���������." << endl;
            fout.close();
        }
    }
    cout << "����� ������.";*/
    return 0;
}
