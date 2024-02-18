#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, q, pos, root, epos, read();
int g[100005], last[100005], dp[100005], vis[100005], anc[100005][17], mv[100005][17], cv[100005][17];
long long tot, cxt = 1e16;
struct Edge
{
    int u, v, w, usd;
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
pair<int, int> bjdx(int a, int b, int c, int d, int e = -1, int f = -1)
{
    int all[6] = {a, b, c, d, e, f};
    sort(all, all + 6);
    pair<int, int> ans;
    ans.first = all[5], ans.second = -1;
    for (int i = 4; i >= 0; i--)
    {
        if (all[i] != all[i + 1])
        {
            ans.second = all[i];
            break;
        }
    }
    return ans;
}
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
    dp[now] = deep, vis[now] = 1;
    for (int i = last[now]; i; i = esk[i].pre)
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
pair<int, int> lca(int x, int y)
{
    pair<int, int> ans;
    ans.first = ans.second = -1;
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
            ans = bjdx(ans.first, ans.second, mv[x][i], cv[x][i]);
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
        ans = bjdx(ans.first, ans.second, mv[x][i], mv[y][i], cv[x][i], cv[y][i]);
        x = anc[x][i], y = anc[y][i];
    }
    ans = bjdx(ans.first, ans.second, mv[x][0], mv[y][0], cv[x][0], cv[y][0]);
    return ans;
}
int main()
{
    memset(cv, -1, sizeof(cv)), memset(g, -1, sizeof(g));
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        if (u != v)
        {
            es[++epos] = Edge{u, v, w, 0};
        }
    }
    sort(es + 1, es + 1 + epos);
    for (int i = 1; i <= epos; i++)
    {
        int u = es[i].u, v = es[i].v, w = es[i].w;
        int x = dfn(u), y = dfn(v);
        if (x != y)
        {
            g[x] < g[y] ? (g[x] += g[y], g[y] = x) : (g[y] += g[x], g[x] = y);
            addEdge(u, v, w), addEdge(v, u, w);
            es[i].usd = 1, tot = tot + es[i].w;
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= log2(n); i++) // 层级
    {
        for (int j = 1; j <= n; j++) // 点
        {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
            pair<int, int> tmp = bjdx(mv[j][i - 1], cv[j][i - 1], mv[anc[j][i - 1]][i - 1], cv[anc[j][i - 1]][i - 1]);
            mv[j][i] = tmp.first, cv[j][i] = tmp.second;
        }
    }
    for (int i = 1; i <= epos; i++)
    {
        if (es[i].usd == 1)
        {
            continue;
        }
        int u = es[i].u, v = es[i].v, w = es[i].w;
        pair<int, int> tmp = lca(u, v);
        if (w > tmp.first)
        {
            cxt = min(cxt, tot - tmp.first + w);
        }
        else if (tmp.second != -1)
        {
            cxt = min(cxt, tot - tmp.second + w);
        }
    }
    printf("%lld", cxt);
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