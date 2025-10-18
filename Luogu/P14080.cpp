#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w, id, op;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
Edge es[100005];
vector<int> to[100005];
int n, m, dp[100005], fe[100005], f[100005], g[100005], dis[100005], rec[100005], anc[100005][20];
long long tot, ans[100005];
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
void dfs(int now, int from)
{
    for (int i = 1; i <= 16; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int eid : to[now])
    {
        int nxt = es[eid].u + es[eid].v - now;
        if (nxt == from || es[eid].op == 0) // 只在MST上dfs
        {
            continue;
        }
        f[nxt] = now, fe[nxt] = eid, dp[nxt] = dp[now] + 1, anc[nxt][0] = now;
        dfs(nxt, now);
    }
}
int LCA(int x, int y)
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
void mk(int now, int lca, long long w) // 不优化,每次暴力上行也能AC
{
    int upe = fe[now], up = f[now], rpos = 0;
    while (dp[up] >= dp[lca])
    {
        rec[++rpos] = now;
        ans[es[upe].id] = min(ans[es[upe].id], w);
        now = up, upe = fe[now], up = f[now];
    }
    for (int i = 1; i <= rpos; i++)
    {
        fe[rec[i]] = upe, f[rec[i]] = up;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w;
        es[i].id = i, dis[i] = es[i].w;
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        to[es[i].u].push_back(i);
        to[es[i].v].push_back(i);
        int gu = dfn(es[i].u), gv = dfn(es[i].v);
        if (gu != gv)
        {
            g[gu] = gv, tot += es[i].w;
            ans[es[i].id] = 1e18, es[i].op = 1;
        }
        else
        {
            ans[es[i].id] = -3; // 非MST边标记为-3
        }
    }
    dp[1] = 1, dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        if (es[i].op)
        {
            continue;
        }
        int lca = LCA(es[i].u, es[i].v);
        mk(es[i].u, lca, es[i].w);
        mk(es[i].v, lca, es[i].w);
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 1e18)
        {
            cout << -1 << "\n";
        }
        else if (ans[i] == -3)
        {
            cout << tot << "\n";
        }
        else
        {
            cout << (tot - dis[i] + ans[i]) << "\n";
        }
    }
    return 0;
}