#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
Edge es[1000005];
int anc[MX][20], score[MX], g[MX], dp[MX], pos;
vector<int> to[MX];
int dfn(int x)
{
    return (x == g[x] ? x : g[x] = dfn(g[x]));
}
void dfs(int now)
{
    for (int i = 1; i <= 16; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        dp[nxt] = dp[now] + 1;
        dfs(nxt);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 16; i >= 0; i--)
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
    for (int i = 16; i >= 0; i--)
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
    int n, m, q, ok = 0;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (ok)
        {
            printf("\n");
        }
        memset(anc, 0, sizeof(anc)), memset(score, 0, sizeof(score));
        memset(g, 0, sizeof(g)), memset(dp, 0, sizeof(dp));
        memset(es, 0, sizeof(es)), ok = 1;
        for (int i = 1; i <= 100000; i++)
        {
            to[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &es[i].u, &es[i].v, &es[i].w);
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
                score[++pos] = es[i].w;
                anc[u][0] = anc[v][0] = pos, g[u] = g[v] = g[pos] = pos;
                to[pos].push_back(u), to[pos].push_back(v);
            }
        }
        dp[pos] = 1, dfs(pos);
        scanf("%d", &q);
        for (int i = 1; i <= q; i++)
        {
            int s, t;
            scanf("%d %d", &s, &t);
            printf("%d\n", score[lca(s, t)]);
        }
    }
    return 0;
}
// TAG: Kruskal重构树 LCA 并查集