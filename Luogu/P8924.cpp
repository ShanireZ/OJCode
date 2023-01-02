#include <iostream>
using namespace std;
int a[105], mp[105][105];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int x = 0; x < n; x++)
    {
        long long base = 1, f = 0;
        for (int i = 0; i <= k; i++)
        {
            f += base * a[i];
            base *= x;
        }
        if (f < m && f >= 0) // f行x列
        {
            mp[f][x] = 1;
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ((mp[i][j] == 0) ? "." : "*");
        }
        cout << "\n";
    }
    return 0;
}