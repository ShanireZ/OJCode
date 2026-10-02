#include <algorithm>
#include <iostream>
using namespace std;
long long tot;
int n, m, k, w, ok, f[1005][1005], vis[1005][1005], bee[10][2];
void dfs(int now, int p, int d)
{
    if (now == k + 1)
    {
        if (tot >= w)
        {
            ok = 1;
        }
        return;
    }
    long long res = 0;
    if (d == 0)
    {
        int x = bee[now][0];
        for (int y = max(1, bee[now][1] - p); y <= min(m, bee[now][1] + p); y++)
        {
            if (vis[x][y] == 0)
            {
                res += f[x][y];
            }
            vis[x][y]++;
        }
    }
    else
    {
        int y = bee[now][1];
        for (int x = max(1, bee[now][0] - p); x <= min(n, bee[now][0] + p); x++)
        {
            if (vis[x][y] == 0)
            {
                res += f[x][y];
            }
            vis[x][y]++;
        }
    }
    tot += res;
    dfs(now + 1, p, 0);
    dfs(now + 1, p, 1);
    tot -= res;
    if (d == 0)
    {
        int x = bee[now][0];
        for (int y = max(1, bee[now][1] - p); y <= min(m, bee[now][1] + p); y++)
        {
            vis[x][y]--;
        }
    }
    else
    {
        int y = bee[now][1];
        for (int x = max(1, bee[now][0] - p); x <= min(n, bee[now][0] + p); x++)
        {
            vis[x][y]--;
        }
    }
}
bool check(int p)
{
    for (int i = 0; i <= 1; i++)
    {
        tot = 0, ok = 0;
        dfs(1, p, i);
        if (ok)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m >> k >> w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> bee[i][0] >> bee[i][1];
    }
    int l = 0, r = 1000;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        check(mid) ? r = mid - 1 : l = mid + 1;
    }
    if (l > 1000)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << l << endl;
    }
    // for (int p = 0; p < 1000; p++)
    // {
    //     if (check(p))
    //     {
    //         cout << p << endl;
    //         return 0;
    //     }
    // }
    // cout << "Impossible" << endl;
    return 0;
}