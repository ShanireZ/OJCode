#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, q, pos, root;
int g[100005], last[100005], dp[100005], vis[100005], anc[100005][17], mv[100005][17];
struct Edge
{
    int u, v, w;
    bool operator<(const Edge x) const
    {
        return w < x.w;
    }
};
Edge es[300005];
struct EdgeK
{
    int to, w, pre;
};
EdgeK esk[300005];
int read();
void addEdge(int u, int v, int w)
{
    esk[++pos].pre = last[u];
    last[u] = pos;
    esk[pos].w = w, esk[pos].to = v;
}
int dfn(int now)
{
    if (g[now] > 0)
    {
        return g[now] = dfn(g[now]);
    }
    return now;
}
void dfs(int now, int deep)
{
    dp[now] = deep;
    vis[now] = 1;
    for (int i = last[now]; i != 0; i = esk[i].pre)
    {
        int to = esk[i].to, w = esk[i].w;
        if (to == anc[now][0])
        {
            continue;
        }
        anc[to][0] = now;
        mv[to][0] = w;
        dfs(to, deep + 1);
    }
}
void init()
{
    memset(mv, 0, sizeof(mv));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i, 1);
    }
    for (int i = 1; i <= log2(n); i++) //层级
    {
        for (int j = 1; j <= n; j++) //点
        {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
            mv[j][i] = max(mv[anc[j][i - 1]][i - 1], mv[j][i - 1]);
        }
    }
}
int lca(int x, int y)
{
    int ans = 0;
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    if (dp[x] != dp[y])
    {
        for (int i = log2(dp[x] - dp[y]); i >= 0; i--)
        {
            if (dp[anc[x][i]] < dp[y])
            {
                continue;
            }
            ans = max(ans, mv[x][i]);
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return ans;
    }
    for (int i = log2(dp[x]); i >= 0; i--)
    {
        if (anc[x][i] == anc[y][i])
        {
            continue;
        }
        ans = max(ans, max(mv[x][i], mv[y][i]));
        x = anc[x][i], y = anc[y][i];
    }
    ans = max(ans, max(mv[x][0], mv[y][0]));
    return ans;
}
int main()
{
    n = read(), m = read();
    memset(g, -1, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        es[i].u = read(), es[i].v = read(), es[i].w = read();
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        int u = es[i].u, v = es[i].v, w = es[i].w;
        int x = dfn(u), y = dfn(v);
        //printf("ok %d %d\n", x, y);
        if (x == y)
        {
            continue;
        }
        if (g[x] < g[y])
        {
            g[x] += g[y];
            g[y] = x;
        }
        else
        {
            g[y] += g[x];
            g[x] = y;
        }
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    init();
    q = read();
    for (int i = 1; i <= q; i++)
    {
        int x = read(), y = read();
        if (dfn(x) != dfn(y))
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n", lca(x, y));
        }
    }
    return 0;
}
int read()
{
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    int ans = 0, t = 1;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}