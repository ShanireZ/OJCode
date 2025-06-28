#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
};
Edge es[10005];
int g[105], dfn[105], low[105], dis[105], from[105], n, m, r, ans, npos, gpos, epos;
vector<int> pth;
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
            g[pth.back()] = gpos, ans += dis[pth.back()];
            pth.pop_back();
        }
        g[pth.back()] = gpos, ans += dis[pth.back()];
        pth.pop_back();
    }
}
int main()
{
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w;
    }
    while (true)
    {
        fill(dfn + 1, dfn + 1 + n, 0);
        fill(low + 1, low + 1 + n, 0);
        fill(dis + 1, dis + 1 + n, 1e9);
        fill(g + 1, g + 1 + n, 0);
        for (int i = 1; i <= m; i++)
        {
            int u = es[i].u, v = es[i].v, w = es[i].w;
            if (w < dis[v] && u != v)
            {
                dis[v] = w, from[v] = u;
            }
        }
        epos = npos = gpos = dis[r] = 0, from[r] = r;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == 1e9)
            {
                cout << -1 << endl;
                return 0;
            }
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        if (gpos == n)
        {
            cout << ans << endl;
            return 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u = g[es[i].u], v = g[es[i].v], w = es[i].w;
            if (u != v)
            {
                es[++epos] = Edge{u, v, w - dis[es[i].v]};
            }
        }
        n = gpos, r = g[r], m = epos;
    }
    return 0;
}