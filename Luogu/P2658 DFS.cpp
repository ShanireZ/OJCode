#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, sx, sy, tot, cnt, h[505][505], sig[505][505], vis[505][505];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int lim, int x, int y)
{
    vis[x][y] = 1, cnt += sig[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > m || vis[nx][ny] || abs(h[x][y] - h[nx][ny]) > lim)
        {
            continue;
        }
        dfs(lim, nx, ny);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> sig[i][j];
            if (sig[i][j])
            {
                tot++, sx = i, sy = j;
            }
        }
    }
    int L = 0, R = 1e9;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        memset(vis, 0, sizeof(vis)), cnt = 0;
        dfs(mid, sx, sy);
        (cnt == tot) ? R = mid - 1 : L = mid + 1;
    }
    cout << L << endl;
    return 0;
}