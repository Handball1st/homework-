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
    /*cout << "0 - выйти" << endl << "1 - добавить запись (имя и телефон)" << endl << "2 - найти телефон по имени"
         << endl << "3 - найти имя по телефону" << endl << "4 - сохранить текущие данные в файл" << endl;
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
        cout << "Введите тип операции: ";
        cin >> type;
        if (type == 1)
        {
            cout << "Введите имя и телефон: ";
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
        if (type == 2) /// Найти телефон по имени
        {
            cout << "Введите имя контакта: ";
            cin >> name;
            for (int i = 0; i < n; ++i)
            {
                if (isEqual(name, phonebook[i].name))
                {
                    cout << "У контакта " << name << " номер " << phonebook[i].number << "." << endl;
                    break;
                }
            }
        }
        if (type == 3) /// Найти имя по телефону
        {
            cout << "Введите номер контакта: ";
            cin >> number;
            for (int i = 0; i < n; ++i)
            {
                if (isEqual(number, phonebook[i].number))
                {
                    cout << "У контакта с номером " << number << " имя " << phonebook[i].name << "." << endl;
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
            cout << "Контакты сохранены." << endl;
            fout.close();
        }
    }
    cout << "Конец работы.";*/
    return 0;
}
