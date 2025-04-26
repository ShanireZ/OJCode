#include <algorithm>
#include <iostream>
using namespace std;
int sd[10][10], h[10][10], l[10][10], bk[10][10];
bool dfs(int x, int y)
{
    if (x > 9)
    {
        return 1;
    }
    int nx = x, ny = y;
    (y == 9) ? (nx++, ny = 1) : (ny++);
    if (sd[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            int id = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
            if (h[x][i] || l[y][i] || bk[id][i])
            {
                continue;
            }
            sd[x][y] = i, h[x][i] = l[y][i] = bk[id][i] = 1;
            if (dfs(nx, ny))
            {
                return 1;
            }
            sd[x][y] = 0, h[x][i] = l[y][i] = bk[id][i] = 0;
        }
        return 0;
    }
    else
    {
        return dfs(nx, ny);
    }
}
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            char ch;
            cin >> ch;
            if (ch != '.')
            {
                sd[i][j] = ch - '0';
                int id = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
                h[i][ch - '0'] = l[j][ch - '0'] = bk[id][ch - '0'] = 1;
            }
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << sd[i][j];
        }
        cout << endl;
    }
    return 0;
}