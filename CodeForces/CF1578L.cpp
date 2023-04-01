#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define MX 100005
struct Edge
{
    int u, v, w;
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
Edge es[MX];
long long sum[MX * 2], g[MX * 2], ans[MX * 2];
int read();
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        sum[i] = read(), g[i] = i, ans[i] = 1e18;
    }
    for (int i = 1; i <= m; i++)
    {
        es[i].u = read(), es[i].v = read(), es[i].w = read();
    }
    sort(es + 1, es + 1 + m);
    int pos = n;
    for (int i = 1; i <= m; i++)
    {
        int gu = dfn(es[i].u), gv = dfn(es[i].v);
        long long w = es[i].w;
        if (gu != gv)
        {
            g[gu] = g[gv] = ++pos,
            sum[pos] = sum[gu] + sum[gv], g[pos] = pos;
            ans[pos] = max(min(w, ans[gu]) - sum[gv], min(w, ans[gv]) - sum[gu]);
        }
    }
    cout << (ans[pos] <= 0 ? -1 : ans[pos]) << "\n";
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
// TAG: Kruskal重构树 生成树 树上DP