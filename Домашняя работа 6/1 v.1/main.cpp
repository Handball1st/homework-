#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    Tree currentTree = {nullptr, 0};
    int type = -1;
    while (type != 0)
    {
        cout << "������� ��� ��������: ";
        cin >> type;
        switch (type)
        {
            case 1:
            {
                int value = 0;
                cout << "������� �������� ������������ ��������: ";
                cin >> value;
                add(&currentTree, value);
                break;
                //debugOutput(currentTree.root);
            }
            case 2:
            {
                int value = 0;
                cout << "������� �������� ���������� ��������: ";
                cin >> value;
                TreeNode removedVertex = remove(&currentTree, value);
                break;
                //debugOutput(currentTree.root);
            }
            case 3:
            {
                int value = 0;
                cout << "������� ��������: ";
                cin >> value;
                cout << "������� " << value;
                bool result = isExists(&currentTree, value);
                (result) ? cout << " ����������� " : cout << " �� ����������� ";
                cout << "���������" << endl;
                break;
            }
            case 4:
            {
                cout << "�������� �������� ��������� � ������������ �������: ";
                printAscending(currentTree.root);
                cout << endl;
                break;
            }
            case 5:
            {
                cout << "�������� �������� ��������� � ��������� �������: ";
                printDescending(currentTree.root);
                cout << endl;
                break;
            }
            case 6:
            {
                cout << "���������� �����: ";
                debugOutput(currentTree.root);
                cout << endl;
                break;
            }
        }
    }
    cout << "����� ���������� ��������.";
    return 0;
}
