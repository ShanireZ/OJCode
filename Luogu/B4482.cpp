#include <algorithm>
#include <iostream>
using namespace std;
int a[5][5], h[5][5], l[5][5], g[5][5], ok;
int p(int x, int y)
{
    return 1 + (x > 2) * 2 + (y > 2);
}
void dfs(int x, int y)
{
    if (x == 5)
    {
        ok = 1;
        return;
    }
    int nx = x + (y == 4), ny = y % 4 + 1;
    if (a[x][y])
    {
        dfs(nx, ny);
        return;
    }
    for (int v = 1; v <= 4; v++)
    {
        if (h[x][v] || l[y][v] || g[p(x, y)][v])
        {
            continue;
        }
        a[x][y] = v;
        h[x][v] = l[y][v] = g[p(x, y)][v] = 1;
        dfs(nx, ny);
        if (ok)
        {
            return;
        }
        a[x][y] = 0;
        h[x][v] = l[y][v] = g[p(x, y)][v] = 0;
    }
}
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                h[i][a[i][j]] = l[j][a[i][j]] = g[p(i, j)][a[i][j]] = 1;
            }
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << a[i][j];
            if (j < 4)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}