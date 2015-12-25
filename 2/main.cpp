#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n = 0;
    int m = 0;
    const int maxSize = int(1e4);
    int a[maxSize], b[maxSize], res[maxSize];
    Stack vasya;
    Stack petya;
    vasya.head = nullptr;
    vasya.size = 0;
    petya.head = nullptr;
    petya.size = 0;
    cout << "Введите количество тетрадей у Пети: ";
    cin >> n;
    cout << "Введите сложности предметов в порядке убывания для Пети: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        push(&petya, a[i]);
    }
    cout << "Введите количество тетрадей у Васи: ";
    cin >> m;
    cout << "Введите сложности предметов в порядке убывания для Васи: ";
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    for (int i = m - 1; i >= 0; --i)
    {
        push(&vasya, b[i]);
    }
    int id = 0;
    while (petya.size != 0 || vasya.size != 0)
    {
        if (vasya.size == 0)
        {
            res[id++] = haveCurrentHeadOfStack(&petya);
            pop(&petya);
        }
        else if (petya.size == 0)
        {
            res[id++] = haveCurrentHeadOfStack(&vasya);
            pop(&vasya);
        }
        else
        {
            int petyaHead = haveCurrentHeadOfStack(&petya);
            int vasyaHead = haveCurrentHeadOfStack(&vasya);
            if (petyaHead > vasyaHead)
            {
                res[id++] = petyaHead;
                pop(&petya);
            }
            else
            {
                res[id++] = vasyaHead;
                pop(&vasya);
            }
        }
    }
    cout << "Отсортированная стопка: ";
    for (int i = 0; i < id; ++i)
    {
        cout << res[i] << " ";
    }
    return 0;
}
// сложность O(n)
