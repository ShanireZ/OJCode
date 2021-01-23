#include <iostream>
#include <algorithm>
using namespace std;
int a[505][505], b[505][505];
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = (i - 1) * n + j;
        }
    }
    for (int t = 1; t <= m; t++)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                if (z == 0)
                {
                    b[x - y + j][y + x - i] = a[i][j];
                }
                else
                {
                    b[x + y - j][y - x + i] = a[i][j];
                }
            }
        }
        for (int i = x - r; i <= x + r; i++)
        {
            for (int j = y - r; j <= y + r; j++)
            {
                a[i][j] = b[i][j];
            }
        }
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