#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int h[505][505], vis[505][505], l[505][505], r[505][505];
int n, m, cnt, f[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
struct Line
{
    int l, r;
    bool operator<(const Line oth) const
    {
        return l == oth.l ? r > oth.r : l < oth.l;
    }
};
Line ls[505];
void dfs(int x, int y)
{
    vis[x][y] = 1, cnt += (x == n);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + f[i][0], ny = y + f[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > m || h[nx][ny] >= h[x][y])
        {
            continue;
        }
        if (vis[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
        l[x][y] = min(l[x][y], l[nx][ny]), r[x][y] = max(r[x][y], r[nx][ny]);
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
    memset(l, 0x3f, sizeof(l));
    for (int j = 1; j <= m; j++)
    {
        l[n][j] = r[n][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        if (vis[1][i] == 0)
        {
            dfs(1, i);
        }
    }
    if (cnt < m)
    {
        cout << 0 << endl
             << m - cnt << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        ls[i].l = l[1][i], ls[i].r = r[1][i];
    }
    sort(ls + 1, ls + 1 + m);
    int last = ls[1].r, pos = ls[1].r, ans = 1;
    for (int i = 2; i <= m && ls[i].l != 0x3f3f3f3f; i++)
    {
        if (ls[i].l > pos + 1)
        {
            pos = last, ans++;
        }
        last = max(last, ls[i].r);
    }
    ans += (pos != m);
    cout << 1 << endl
         << ans << endl;
    return 0;
}