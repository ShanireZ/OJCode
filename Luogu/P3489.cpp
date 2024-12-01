#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w, sta; // 终点 距离 可消灭怪物状态
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Edge> pq;
vector<Edge> es[205]; // 终点 距离 路上怪物状态
int n, m, p, k, bsm[205], vis[205][(1 << 14)], dis[205][(1 << 14)];
int main()
{
    cin >> n >> m >> p >> k;
    for (int i = 1; i <= k; i++)
    {
        int w, q, r;
        cin >> w >> q;
        while (q--)
        {
            cin >> r;
            bsm[w] |= (1 << r);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, s, r;
        cin >> u >> v >> w >> s;
        es[u].push_back({v, w, 0}), es[v].push_back({u, w, 0});
        while (s--)
        {
            cin >> r;
            es[u].back().sta |= (1 << r), es[v].back().sta |= (1 << r);
        }
    }
    int res = 0xfffffff;
    memset(dis, 0x3f, sizeof(dis));
    pq.push({1, 0, bsm[1]}), dis[1][bsm[1]] = 0;
    while (pq.size())
    {
        int now = pq.top().v, sta = pq.top().sta;
        pq.pop();
        if (vis[now][sta])
        {
            continue;
        }
        vis[now][sta] = 1;
        if (now == n)
        {
            res = min(res, dis[now][sta]);
        }
        for (Edge e : es[now])
        {
            int nxt = e.v, esta = e.sta;
            if ((sta | esta) == sta && dis[nxt][(sta | bsm[nxt])] > dis[now][sta] + e.w)
            {
                dis[nxt][(sta | bsm[nxt])] = dis[now][sta] + e.w;
                pq.push({nxt, dis[nxt][(sta | bsm[nxt])], sta | bsm[nxt]});
            }
        }
    }
    cout << (res == 0xfffffff ? -1 : res) << endl;
    return 0;
}