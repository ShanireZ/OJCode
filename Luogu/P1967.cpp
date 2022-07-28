#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
struct Edge
{
    int a, b, w;
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
Edge es[50005];
int g[10005], dp[10005], anc[10005][15], lim[10005][15];
int last[10005], dis[100005], pre[100005], to[100005];
int n, m, q, epos;
int dfn(int now)
{
    return (now == g[now]) ? now : g[now] = dfn(g[now]);
}
void addEdge(int u, int v, int w, int eid)
{
    pre[eid] = last[u], to[eid] = v, dis[eid] = w;
    last[u] = eid;
}
void init(int now, int deep)
{
    dp[now] = deep;
    for (int i = 1; i <= log2(deep); i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
        lim[now][i] = min(lim[now][i - 1], lim[anc[now][i - 1]][i - 1]);
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (t == anc[now][0])
        {
            continue;
        }
        anc[t][0] = now, lim[t][0] = dis[i];
        init(t, deep + 1);
    }
}
int lca(int x, int y)
{
    int ans = 0x3f3f3f3f;
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    if (dp[x] > dp[y])
    {
        for (int i = log2(dp[x] - dp[y]); i >= 0; i--)
        {
            if (dp[anc[x][i]] >= dp[y])
            {
                ans = min(ans, lim[x][i]);
                x = anc[x][i];
            }
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
        ans = min(ans, min(lim[x][i], lim[y][i]));
        x = anc[x][i], y = anc[y][i];
    }
    ans = min(ans, min(lim[x][0], lim[y][0]));
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].a >> es[i].b >> es[i].w;
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int ga = dfn(es[i].a), gb = dfn(es[i].b);
        if (ga == gb)
        {
            continue;
        }
        g[ga] = gb;
        addEdge(es[i].a, es[i].b, es[i].w, ++epos);
        addEdge(es[i].b, es[i].a, es[i].w, ++epos);
    }
    memset(lim, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
        {
            init(i, 1);
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (dfn(a) != dfn(b))
        {
            cout << -1 << endl;
        }
        else
        {
            cout << lca(a, b) << endl;
        }
    }
    return 0;
}