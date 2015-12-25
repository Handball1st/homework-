#include <iostream>
#include <fstream>

using namespace std;

struct Phonebook
{
    char name[12];
    char number[12];
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n = 0;
    in >> n;
    const int maxLenght = 12;
    Phonebook current[n];
    for (int i = 0; i < n; ++i)
    {
        in >> current[i].name >> current[i].number;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << current[i].name << " " << current[i].number << endl;
    }
    /*int type = -1;
    while (type != 0)
    {
        cout << "Введите тип операции: ";
        cin >> type;
        if (type == 1)
        {
            cin >> current[n].name >> current[n++].number;
        }
        else if (type == 2)
        {
            char number[maxLenght];
            cin >> number;
            bool isEqual = 1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < maxLenght; ++j)
                {
                    if (current[i].number[j] != number[j])
                    {
                        isEqual = 0;
                    }
                }
                if (isEqual)
                {
                    cout << "У пользователя " << current[i].name << " номер " << number << endl;
                    break;
                }
            }
            if (!isEqual)
            {
                cout << "Нет пользователя с данным номером" << endl;
            }
        }
        else if (type == 3)
        {
            char name[maxLenght];
            cin >> name;
            bool isEqual = 1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < maxLenght; ++j)
                {
                    if(current[i].name[j] == name[j])
                    {
                        isEqual = 0;
                    }
                }
                if (isEqual)
                {
                    cout << "У пользователя " << name << " номер " << current[i].number << endl;
                    break;
                }
            }
            if (!isEqual)
            {
                cout << "Нет пользователя с данным номером" << endl;
            }
        }
        else if (type == 4)
        {
            cout << n << endl;
            for (int i = 0; i < n; ++i)
            {
                cout << current[i].name << " " << current[i].number << endl;
            }
        }
    }
    in.close();
    out.close();*/
    return 0;
}
