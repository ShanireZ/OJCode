#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, vis[55][55], ms[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char t[55][55];
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && (t[nx][ny] == '.' || t[nx][ny] == 'o') && vis[nx][ny] == 0)
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
            cin >> t[i][j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        if ((t[1][j] == '.' || t[1][j] == 'o') && vis[1][j] == 0)
        {
            dfs(1, j);
        }
        if ((t[n][j] == '.' || t[n][j] == 'o') && vis[n][j] == 0)
        {
            dfs(n, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if ((t[i][1] == '.' || t[i][1] == 'o') && vis[i][1] == 0)
        {
            dfs(i, 1);
        }
        if ((t[i][m] == '.' || t[i][m] == 'o') && vis[i][m] == 0)
        {
            dfs(i, m);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += (t[i][j] == 'o' && vis[i][j] == 0);
        }
    }
    cout << ans << endl;
    return 0;
}