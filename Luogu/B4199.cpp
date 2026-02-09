#include <algorithm>
#include <iostream>
using namespace std;
int a[55][55], n, v;
void ssz(int x, int y)
{
    for (int j = y; j <= n - y + 1; j++)
    {
        a[x][j] = ++v;
    }
    for (int i = x + 1; i <= n - x + 1; i++)
    {
        a[i][n - y + 1] = ++v;
    }
    for (int j = n - y; j >= y; j--)
    {
        a[n - x + 1][j] = ++v;
    }
    for (int i = n - x; i > x; i--)
    {
        a[i][y] = ++v;
    }
}
void nsz(int x, int y)
{
    for (int i = x; i <= n - x + 1; i++)
    {
        a[i][y] = ++v;
    }
    for (int j = y + 1; j <= n - y + 1; j++)
    {
        a[n - x + 1][j] = ++v;
    }
    for (int i = n - x; i >= x; i--)
    {
        a[i][n - y + 1] = ++v;
    }
    for (int j = n - y; j > y; j--)
    {
        a[x][j] = ++v;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        i % 2 ? ssz(i, i) : nsz(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}