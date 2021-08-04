#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, q, pos, root;
int g[10005], last[10005], dp[10005], vis[10005], anc[10005][15], mv[10005][15];
struct Edge
{
    int u, v, w;
    bool operator<(const Edge x) const
    {
        return w > x.w;
    }
};
Edge es[50005];
struct EdgeK
{
    int to, w, pre;
};
EdgeK esk[50005];
int read();
int dfn(int now)
{
    if (now != g[now])
    {
        g[now] = dfn(g[now]);
    }
    return g[now];
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
    memset(mv, 0x3f, sizeof(mv));
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
            mv[j][i] = min(mv[anc[j][i - 1]][i - 1], mv[j][i - 1]);
        }
    }
}
int lca(int x, int y)
{
    int ans = 0x3f3f3f3f;
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
            ans = min(ans, mv[x][i]);
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
        ans = min(ans, min(mv[x][i], mv[y][i]));
        x = anc[x][i], y = anc[y][i];
    }
    ans = min(ans, min(mv[x][0], mv[y][0]));
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        es[i].u = read(), es[i].v = read(), es[i].w = read();
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        int u = es[i].u, v = es[i].v, w = es[i].w;
        int gx = dfn(u), gy = dfn(v);
        if (gx == gy)
        {
            continue;
        }
        g[gx] = gy;
        esk[++pos].pre = last[u];
        esk[pos].w = w;
        esk[pos].to = v;
        last[u] = pos;
        esk[++pos].pre = last[v];
        esk[pos].w = w;
        esk[pos].to = u;
        last[v] = pos;
    }
    init();
    q = read();
    for (int i = 1; i <= q; i++)
    {
        int x = read(), y = read();
        if (dfn(x) != dfn(y))
        {
            printf("-1\n");
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