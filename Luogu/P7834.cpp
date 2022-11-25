#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 200005
struct Edge
{
    int u, v, w;
    bool operator<(const Edge oth) const
    {
        return w < oth.w;
    }
};
Edge es[MX * 3];
struct Node
{
    int lc, rc, v;
};
Node ns[MX * 20];
int read(), n, m, q, epos, spos, npos, cnt, lastans, stn, ls[MX], h[MX], g[MX], dp[MX], anc[MX][20];
int pre[MX], to[MX], last[MX], val[MX], sid[MX], sz[MX], root[MX];
void init(int &now, int l, int r) // 主席树用来查找区间排名
{
    now = ++npos;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
}
void edit(int &now, int old, int l, int r, int p)
{
    now = ++npos;
    ns[now] = ns[old];
    if (l == r)
    {
        ns[now].v++;
        return;
    }
    int mid = (l + r) / 2;
    (p <= mid) ? edit(ns[now].lc, ns[old].lc, l, mid, p) : edit(ns[now].rc, ns[old].rc, mid + 1, r, p);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int now, int old, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2, x = ns[ns[now].lc].v - ns[ns[old].lc].v;
    return (x >= k) ? query(ns[now].lc, ns[old].lc, l, mid, k) : query(ns[now].rc, ns[old].rc, mid + 1, r, k - x);
}
int dfn(int x)
{
    return (x == g[x]) ? x : g[x] = dfn(g[x]);
}
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], last[u] = id;
    to[id] = v, anc[v][0] = u;
}
void dfs(int now, int deep) // sid记录当前点在主席树上的序号起始 sz统计元素个数
{
    dp[now] = deep, sid[now] = 0x3f3f3f3f;
    if (val[now] == 0) // 叶节点
    {
        sz[now] = 1, sid[now] = ++spos;
        edit(root[spos], root[spos - 1], 1, cnt, lower_bound(ls + 1, ls + cnt + 1, h[now]) - ls);
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        dfs(nxt, deep + 1);
        sz[now] += sz[nxt], sid[now] = min(sid[now], sid[nxt]);
    }
}
int main()
{
    stn = n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        ls[i] = h[i] = read();
        g[i] = i;
    }
    sort(ls + 1, ls + 1 + n);
    cnt = unique(ls + 1, ls + 1 + n) - (ls + 1);
    init(root[0], 1, cnt);
    for (int i = 1; i <= m; i++)
    {
        es[i] = Edge{read(), read(), read()};
    }
    sort(es + 1, es + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int a = es[i].u, b = es[i].v;
        a = dfn(a), b = dfn(b);
        if (a != b)
        {
            addEdge(++n, a, ++epos), addEdge(n, b, ++epos);
            val[n] = es[i].w, g[a] = g[b] = g[n] = n;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] == 0)
        {
            dfs(i, 1);
        }
    }
    for (int i = 1; i <= log2(n); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        lastans = max(0, lastans);
        int v = read(), x = read(), k = read();
        v = (v ^ lastans) % stn + 1, k = (k ^ lastans) % stn + 1, x = x ^ lastans;
        int pos = v;
        for (int i = log2(dp[pos]); i >= 0; i--)
        {
            if (anc[pos][i] && val[anc[pos][i]] <= x)
            {
                pos = anc[pos][i];
            }
        }
        lastans = -1;
        if (k <= sz[pos])
        {
            int l = sid[pos], r = sid[pos] + sz[pos] - 1;
            lastans = ls[query(root[r], root[l - 1], 1, cnt, sz[pos] - k + 1)];
        }
        printf("%d\n", lastans);
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