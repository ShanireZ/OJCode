#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v;
    double w;
};
vector<Edge> es;
vector<int> pth;
double ans, val[105];
int n, k, root, gpos, npos;
int m[55], dfn[105], low[105], g[105], from[105];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    pth.push_back(now);
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
    if (dfn[now] == low[now])
    {
        gpos++;
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
        fill(val + 1, val + 1 + n, 1e8);
        for (Edge e : es)
        {
            int u = e.u, v = e.v;
            double w = e.w;
            if (u != v && val[v] > w)
            {
                val[v] = w, from[v] = u;
            }
        }
        gpos = npos = val[root] = 0, from[root] = root;
        fill(dfn + 1, dfn + 1 + n, 0);
        fill(low + 1, low + 1 + n, 0);
        fill(g + 1, g + 1 + n, 0);
        for (int i = 1; i <= n; i++)
        {
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        if (gpos == n)
        {
            break;
        }
        for (int i = 0; i < (int)es.size(); i++)
        {
            int gu = g[es[i].u], gv = g[es[i].v];
            double gw = es[i].w;
            es[i] = Edge{gu, gv, (gu == gv ? 0 : gw - val[es[i].v])};
        }
        n = gpos, root = g[root];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) // 可能会出现先买1 再优惠买2 再优惠买其他的1这种情况
    {
        double c;
        scanf("%lf %d", &c, &m[i]);
        es.push_back(Edge{n * 2 + 1, i, c});                  // 买一个i
        es.push_back(Edge{n * 2 + 1, i + n, c * (m[i] - 1)}); // 买m-1个i
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        double c;
        scanf("%d %d %lf", &u, &v, &c);
        es.push_back(Edge{u, v, c});
        es.push_back(Edge{u, v + n, c * (m[v] - 1)});
    }
    root = n = n * 2 + 1;
    solve();
    printf("%.2lf\n", ans);
    return 0;
}