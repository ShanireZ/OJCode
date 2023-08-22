#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 40005
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
Edge es[100005];
int read(), g[MX], dp[MX], wd[MX], anc[MX][20], pos, n, m, q;
vector<int> to[MX];
int dfn(int x)
{
    return (x == g[x] ? x : g[x] = dfn(g[x]));
}
void dfs(int now)
{
    dp[now] = dp[anc[now][0]] + 1;
    for (int i = 1; i <= 15; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        dfs(nxt);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 15; i >= 0; i--)
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
    for (int i = 15; i >= 0; i--)
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
    while (scanf("%d %d %d", &n, &m, &q) != EOF)
    {
        memset(anc, 0, sizeof(anc)), memset(dp, 0, sizeof(dp));
        memset(wd, 0, sizeof(wd)), memset(g, 0, sizeof(g));
        memset(es, 0, sizeof(es));
        for (int i = 1; i <= n * 2; i++)
        {
            to[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            es[i].u = read(), es[i].v = read(), es[i].w = read();
        }
        sort(es + 1, es + m + 1);
        for (int i = 1; i <= n; i++)
        {
            g[i] = i;
        }
        pos = n;
        for (int i = 1; i <= m; i++)
        {
            int u = dfn(es[i].u), v = dfn(es[i].v);
            if (u != v)
            {
                wd[++pos] = es[i].w;
                anc[u][0] = anc[v][0] = g[u] = g[v] = g[pos] = pos;
                to[pos].push_back(u), to[pos].push_back(v);
            }
        }
        dfs(pos);
        for (int i = 1; i <= q; i++)
        {
            int x = read(), y = read();
            printf("%d\n", wd[lca(x, y)]);
        }
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
// TAG: Kruskal重构树 LCA 并查集