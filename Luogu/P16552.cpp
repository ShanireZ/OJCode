#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, h, res, ans, c[155], a[20][35], vis[20][35];
int f[6][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}};
void sign(int x, int y)
{
    vis[x][y] = 1, res++;
    for (int i = 0; i < 6; i++)
    {
        int nx = x + f[i][0], ny = y + f[i][1];
        if (a[x][y] == a[nx][ny] && vis[nx][ny] == 0)
        {
            sign(nx, ny);
        }
    }
}
void dfs(int step, int l, int r, int tpx, int tpy)
{
    if (step == n)
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= 15; i++)
        {
            for (int j = 1; j <= 33; j++)
            {
                if (a[i][j] && vis[i][j] == 0)
                {
                    res = 0, sign(i, j);
                    ans = max(ans, res);
                }
            }
        }
        return;
    }
    step++;
    if (tpx == 1)
    {
        a[1][l] = c[step];
        dfs(step, l - 1, r, tpx + 1, l);
        a[1][l] = 0;
        a[1][r] = c[step];
        dfs(step, l, r + 1, tpx + 1, r - 1);
        a[1][r] = 0;
    }
    else
    {
        a[tpx][tpy] = c[step];
        if (a[tpx][tpy - 1])
        {
            dfs(step, l, r, tpx + 1, tpy - 1);
        }
        else if (a[tpx][tpy + 1])
        {
            dfs(step, l, r, tpx + 1, tpy);
        }
        else
        {
            dfs(step, l, r, 1, -1);
        }
        a[tpx][tpy] = 0;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    a[1][17] = c[1];
    dfs(1, 16, 18, 1, -1);
    cout << ans << endl;
    return 0;
}