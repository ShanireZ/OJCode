#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, m, gpos, cnt, res, mp[65][65], vis[65][65];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx > n || nx < 1 || ny > m || ny < 1 || mp[nx][ny] == 0)
        {
            continue;
        }
        vis[x][y]++;
        if (vis[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
    }
    res = min(res, vis[x][y]);
}
int main()
{
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof(vis)), gpos = cnt = 0, res = 2;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                mp[i][j] = (ch == 'G');
                cnt += mp[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] && vis[i][j] == 0)
                {
                    ++gpos, dfs(i, j);
                }
            }
        }
        if (gpos > 1)
        {
            res = 0;
        }
        else if (cnt <= 2)
        {
            res = -1;
        }
        cout << res << endl;
    }
    return 0;
}