#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "¬ведите размеры массива: ";
    int n = 0;
    int m = 0;
    const int maxSize = 1e2;
    long long arrayOfNumbers[maxSize][maxSize];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arrayOfNumbers[i][j];
        }
    }
    const long long infinity = 1e17;
    for (int i = 0; i < n; ++i)
    {
        long long minimum = infinity;
        int indexOfMinimum = -1;
        for (int j = 0; j < m; ++j)
        {
            if (minimum > arrayOfNumbers[i][j])
            {
                minimum = arrayOfNumbers[i][j];
                indexOfMinimum = i;
            }
        }
        long long maximum = -infinity;
        int indexOfMaximum = -1;
        for (int j = 0; j < n; ++j)
        {
            if (arrayOfNumbers[j][indexOfMinimum] > maximum)
            {
                maximum = arrayOfNumbers[j][indexOfMinimum];
                indexOfMaximum = j;
            }
        }
        if (arrayOfNumbers[indexOfMaximum][indexOfMinimum] == minimum &&
            arrayOfNumbers[indexOfMaximum][indexOfMinimum] == maximum)
        {
            cout << minimum << " - седлова€ точка. Ётот элемент минамилен в " << indexOfMinimum + 1 << " строке и максимален в " <<
            indexOfMaximum + 1 << " столбце." << endl;
        }
    }
    return 0;
}
