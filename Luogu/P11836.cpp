#include <algorithm>
#include <iostream>
using namespace std;
int n, m, res, g[1005][1005][4];
int trans(int x)
{
    return x <= n / 2 ? x : n - x + 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x = trans(i);
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            int y = trans(j), id = (i <= n / 2) * 2 + (j > n / 2);
            g[x][y][id] = (ch == '#' ? 1 : 0);
        }
    }
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {
            int cnt = g[i][j][0] + g[i][j][1] + g[i][j][2] + g[i][j][3];
            res += min(cnt, 4 - cnt);
        }
    }
    cout << res << endl;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        int x = trans(i), y = trans(j), id = (i <= n / 2) * 2 + (j > n / 2);
        int cnt = g[x][y][0] + g[x][y][1] + g[x][y][2] + g[x][y][3];
        res -= min(cnt, 4 - cnt), g[x][y][id] ^= 1;
        cnt = g[x][y][0] + g[x][y][1] + g[x][y][2] + g[x][y][3];
        res += min(cnt, 4 - cnt);
        cout << res << endl;
    }
    return 0;
}