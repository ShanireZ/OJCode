#include <algorithm>
#include <iostream>
using namespace std;
int a[105][105], b[105][105], c[105][105], n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int o = 1; o <= m; o++)
            {
                c[i][j] += a[i][o] * b[o][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}