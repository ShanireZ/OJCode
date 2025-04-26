#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tr[1000005];
int n, m, ans, val[1000005], dp[1000005], anc[1000005][25];
void dfs(int now, int fa)
{
    anc[now][0] = fa, dp[now] = dp[fa] + 1;
    for (int i = 1; i <= 20; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : tr[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (dp[anc[x][i]] >= dp[y])
        {
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i], y = anc[y][i];
        }
    }
    return anc[x][0];
}
void ct(int now, int fa)
{
    for (int nxt : tr[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        ct(nxt, now), val[now] += val[nxt];
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tr[u].push_back(v), tr[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        val[u]++, val[v]++;
        int l = lca(u, v);
        val[l]--, val[anc[l][0]]--;
    }
    ct(1, 0); // 点值为正的点需要保留
    int u, v;
    cin >> u >> v; // 查看u,v路径上所有边的点值是否为正
    if (dp[u] < dp[v])
    {
        swap(u, v);
    }
    while (dp[u] != dp[v])
    {
        ans += (val[u] <= 0);
        u = anc[u][0];
    }
    while (u != v)
    {
        ans += (val[u] <= 0) + (val[v] <= 0);
        u = anc[u][0], v = anc[v][0];
    }
    cout << ans + (val[u] <= 0) << endl;
    return 0;
}