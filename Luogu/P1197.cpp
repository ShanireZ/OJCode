#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 400005
vector<int> to[MX];
int n, m, res, g[MX], vis[MX], atk[MX], ans[MX];
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
void linknew(int x)
{
    int gx = dfn(x);
    for (int y : to[x])
    {
        if (vis[y] == 0 && dfn(y) != gx)
        {
            res--, g[dfn(y)] = gx;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        to[x].emplace_back(y), to[y].emplace_back(x);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> atk[i];
        vis[atk[i]] = 1;
    }
    res = n - m;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            linknew(i);
        }
    }
    ans[m + 1] = res;
    for (int i = m; i >= 1; i--)
    {
        res++, vis[atk[i]] = 0;
        linknew(atk[i]);
        ans[i] = res;
    }
    for (int i = 1; i <= m + 1; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}