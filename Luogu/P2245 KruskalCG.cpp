#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge oth) const
    {
        return w < oth.w;
    }
};
Edge es[300005];
int read(), n, m, k, h, epos, g[200005], dp[200005], anc[200005][20];
int last[200005], pre[200005], to[200005], val[200005];
int dfn(int x)
{
    return (g[x] == x) ? x : g[x] = dfn(g[x]);
}
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], last[u] = id;
    to[id] = v, anc[v][0] = u;
}
void dfs(int now, int deep)
{
    dp[now] = deep, h = max(h, deep);
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        dfs(nxt, deep + 1);
    }
}
int lca(int a, int b)
{
    if (dp[a] < dp[b])
    {
        swap(a, b);
    }
    while (dp[a] != dp[b])
    {
        for (int i = log2(dp[a] - dp[b]); i >= 0; i--)
        {
            if (dp[a] - pow(2, i) >= dp[b])
            {
                a = anc[a][i];
            }
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = log2(dp[a]); i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i], b = anc[b][i];
        }
    }
    return anc[a][0];
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        es[i] = Edge{read(), read(), read()};
    }
    sort(es + 1, es + m + 1);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a = es[i].u, b = es[i].v, w = es[i].w;
        a = dfn(a), b = dfn(b);
        if (a != b)
        {
            addEdge(++n, a, ++epos);
            addEdge(n, b, ++epos);
            val[n] = w, g[a] = g[b] = g[n] = n;
        }
    }
    dfs(n, 1);
    for (int i = 1; i <= log2(h); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    k = read();
    for (int i = 1; i <= k; i++)
    {
        int a = read(), b = read();
        (dfn(a) != dfn(b)) ? printf("impossible\n") : printf("%d\n", val[lca(a, b)]);
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}