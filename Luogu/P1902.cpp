#include <cstring>
#include <iostream>
using namespace std;
int mp[1005][1005], vis[1005][1005], n, m, trig;
int f[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y, int mid)
{
    if (x == n)
    {
        trig = 1;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + f[i][0], ny = y + f[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > m || vis[nx][ny] || mp[nx][ny] > mid)
        {
            continue;
        }
        dfs(nx, ny, mid);
        if (trig)
        {
            return;
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
            cin >> mp[i][j];
        }
    }
    int l = 0, r = 1000, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        trig = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1, 1, mid);
        trig ? r = mid - 1, ans = mid : l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}