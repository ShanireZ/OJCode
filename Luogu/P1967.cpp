#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
Edge es[500005];
vector<int> tr[20005];
int n, m, q, g[20005], dp[20005], val[20005], anc[20005][20];
int dfn(int x)
{
    return (g[x] == x ? x : g[x] = dfn(g[x]));
}
void dfs(int now)
{
    for (int i = 1; i < 20; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : tr[now])
    {
        anc[nxt][0] = now, dp[nxt] = dp[now] + 1, dfs(nxt);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 19; i >= 0; i--)
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
    for (int i = 19; i >= 0; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i], y = anc[y][i];
        }
    }
    return anc[x][0];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w;
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u = es[i].u, v = es[i].v, w = es[i].w;
        u = dfn(u), v = dfn(v);
        if (u != v)
        {
            n++;
            g[n] = g[u] = g[v] = n, val[n] = w;
            tr[n].push_back(u), tr[n].push_back(v);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (g[i] == i)
        {
            dp[i] = n, dfs(i);
        }
    }
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (dfn(u) != dfn(v) ? -1 : val[lca(u, v)]) << "\n";
    }
    return 0;
}