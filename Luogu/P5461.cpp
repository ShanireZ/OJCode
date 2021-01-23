#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1500][1500];
void make(int n, int x, int y)
{
    if (n == 0)
    {
        return;
    }
    for (int i = x; i < x + pow(2, n - 1); i++)
    {
        for (int j = y; j < y + pow(2, n - 1); j++)
        {
            a[i][j] = 0;
        }
    }
    make(n - 1, x + pow(2, n - 1), y);
    make(n - 1, x, y + pow(2, n - 1));
    make(n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= pow(2, n); i++)
    {
        for (int j = 1; j <= pow(2, n); j++)
        {
            a[i][j] = 1;
        }
    }
    make(n, 1, 1);
    for (int i = 1; i <= pow(2, n); i++)
    {
        for (int j = 1; j <= pow(2, n); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}