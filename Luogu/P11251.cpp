#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, ans, res, zf[100005], cf[100005], vis[100005], c[100005];
void dfs(int now, int from)
{
    vis[now] = 1;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        if (zf[nxt] + 1 > zf[now])
        {
            cf[now] = zf[now];
            zf[now] = zf[nxt] + 1;
        }
        else if (zf[nxt] + 1 > cf[now])
        {
            cf[now] = zf[nxt] + 1;
        }
    }
    res = max(res, zf[now] + cf[now]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (c[u] == c[v])
        {
            continue;
        }
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            res = 0, dfs(i, 0);
            ans = max(ans, res);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}