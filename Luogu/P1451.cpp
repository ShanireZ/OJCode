#include <iostream>
#include <algorithm>
using namespace std;
int mp[105][105];
int vis[105][105];
int ans, n, m;
int f[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + f[i][0], ny = y + f[i][1];
        if (nx < 0 || ny < 0 || nx > n || ny > m)
        {
            continue;
        }
        if (mp[nx][ny] == 1 && vis[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x != '0')
            {
                mp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 1 && vis[i][j] == 0)
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}