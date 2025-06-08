#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
};
int n, m, root, npos, gpos, ans, val[105], from[105], g[105], dfn[105], low[105];
vector<int> pth;
vector<Edge> es;
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos, pth.push_back(now);
    int nxt = from[now];
    if (dfn[nxt] == 0)
    {
        tarjan(nxt);
        low[now] = min(low[now], low[nxt]);
    }
    else if (g[nxt] == 0)
    {
        low[now] = min(low[now], dfn[nxt]);
    }
    if (low[now] == dfn[now])
    {
        ++gpos;
        while (pth.back() != now)
        {
            g[pth.back()] = gpos, ans += val[pth.back()];
            pth.pop_back();
        }
        g[pth.back()] = gpos, ans += val[pth.back()];
        pth.pop_back();
    }
}
void solve()
{
    while (true)
    {
        fill(val + 1, val + 1 + n, 1000005);
        for (Edge e : es) // 构建最短边集
        {
            int u = e.u, v = e.v, w = e.w;
            if (val[v] > w && u != v)
            {
                val[v] = w, from[v] = u;
            }
        }
        fill(dfn + 1, dfn + 1 + n, 0);
        fill(low + 1, low + 1 + n, 0);
        fill(g + 1, g + 1 + n, 0);
        gpos = npos = val[root] = 0, from[root] = root;
        for (int i = 1; i <= n; i++) // 找环+统计联通性
        {
            if (val[i] == 1000005)
            {
                ans = -1;
                return;
            }
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        if (gpos == n)
        {
            return;
        }
        for (int i = 0; i < m; i++) // 缩点
        {
            int gu = g[es[i].u], gv = g[es[i].v], gw = es[i].w;
            es[i] = (gu == gv ? Edge{gu, gv, 0} : Edge{gu, gv, gw - val[es[i].v]});
        }
        n = gpos, root = g[root];
    }
}
int main()
{
    cin >> n >> m >> root;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es.push_back(Edge{u, v, w});
    }
    solve();
    cout << ans << endl;
    return 0;
}