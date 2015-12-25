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
        cout << "¬ведите тип операции: ";
        cin >> type;
        switch (type)
        {
            case 1:
            {
                int value = 0;
                cout << "¬ведите значение добавл€емого элемента: ";
                cin >> value;
                add(&currentTree, value);
                break;
                //debugOutput(currentTree.root);
            }
            case 2:
            {
                int value = 0;
                cout << "¬ведите значение удал€емого элемента: ";
                cin >> value;
                TreeNode removedVertex = remove(&currentTree, value);
                break;
                //debugOutput(currentTree.root);
            }
            case 3:
            {
                int value = 0;
                cout << "¬ведите значение: ";
                cin >> value;
                cout << "Ёлемент " << value;
                bool result = isExists(&currentTree, value);
                (result) ? cout << " принадлежит " : cout << " не принадлежит ";
                cout << "множеству" << endl;
                break;
            }
            case 4:
            {
                cout << "Ёлементы текущего множества в возрастающем пор€дке: ";
                printAscending(currentTree.root);
                cout << endl;
                break;
            }
            case 5:
            {
                cout << "Ёлементы текущего множества в убывающем пор€дке: ";
                printDescending(currentTree.root);
                cout << endl;
                break;
            }
            case 6:
            {
                cout << "ќтладочный вывод: ";
                debugOutput(currentTree.root);
                cout << endl;
                break;
            }
        }
    }
    cout << " онец выполнени€ операций.";
    return 0;
}
