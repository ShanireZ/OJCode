#include <algorithm>
#include <iostream>
using namespace std;
int a[55][55], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j = n - i + 1;
        for (int x = i; x <= j; x++)
        {
            for (int y = i; y <= j; y++)
            {
                a[x][y] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (a[i][j] % 2 ? '#' : '.');
        }
        cout << endl;
    }
    return 0;
}