#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, b, c;
};
Edge es[10005], tes[10005];
int T, n, m, cs, epos, gpos, npos, tot, dfn[65], low[65], g[65], dis[65], from[65];
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
        while (now != pth.back())
        {
            g[pth.back()] = gpos, tot += dis[pth.back()];
            pth.pop_back();
        }
        g[pth.back()] = gpos, tot += dis[pth.back()];
        pth.pop_back();
    }
}
bool check(int lmt)
{
    int tn = n, tm = m, r = 1;
    tot = 0;
    for (int i = 1; i <= tm; i++)
    {
        tes[i] = es[i];
    }
    while (true)
    {
        fill(g + 1, g + 1 + tn, 0);
        fill(dfn + 1, dfn + 1 + tn, 0);
        fill(low + 1, low + 1 + tn, 0);
        fill(dis + 1, dis + 1 + tn, 1e9);
        for (int i = 1; i <= tm; i++)
        {
            int u = tes[i].u, v = tes[i].v, b = tes[i].b, c = tes[i].c;
            if (u != v && dis[v] > c && b >= lmt)
            {
                dis[v] = c, from[v] = u;
            }
        }
        from[r] = 1, gpos = npos = epos = dis[r] = 0;
        for (int i = 1; i <= tn; i++)
        {
            if (dis[i] == 1e9)
            {
                return false;
            }
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        if (gpos == tn)
        {
            break;
        }
        for (int i = 1; i <= tm; i++)
        {
            int u = g[tes[i].u], v = g[tes[i].v], b = tes[i].b, c = tes[i].c;
            if (u != v && b >= lmt)
            {
                tes[++epos] = Edge{u, v, b, c - dis[tes[i].v]};
            }
        }
        tn = gpos, tm = epos, r = g[r];
    }
    return tot <= cs;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> cs;
        for (int i = 1; i <= m; i++)
        {
            cin >> es[i].u >> es[i].v >> es[i].b >> es[i].c;
            es[i].u++, es[i].v++;
        }
        int l = 1, r = 1000000;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            check(mid) ? l = mid + 1 : r = mid - 1;
        }
        if (r == 0)
        {
            cout << "streaming not possible." << endl;
        }
        else
        {
            cout << r << " kbps" << endl;
        }
    }
    return 0;
}