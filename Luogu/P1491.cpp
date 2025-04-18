#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int x, y;
};
Node ns[205];
struct Edge
{
    int u, v;
    double w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
Edge es[10005];
priority_queue<Edge> q;
vector<int> g[205], way;
int n, m, rec[205];
double dis[205], ans = 1e15;
double dijkstra(int lmt)
{
    fill(dis + 1, dis + 1 + n, 1e15);
    dis[1] = 0, q.emplace(Edge{1, 0, 0});
    while (q.size())
    {
        int now = q.top().u;
        double w = q.top().w;
        q.pop();
        if (w == dis[now])
        {
            for (int eid : g[now])
            {
                if (eid == lmt)
                {
                    continue;
                }
                int nxt = es[eid].u + es[eid].v - now;
                double d = es[eid].w;
                if (dis[nxt] > dis[now] + d)
                {
                    dis[nxt] = dis[now] + d, rec[nxt] = eid;
                    q.emplace(Edge{nxt, 0, dis[nxt]});
                }
            }
        }
    }
    return dis[n];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &ns[i].x, &ns[i].y);
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].emplace_back(i), g[b].emplace_back(i);
        double c = sqrt((ns[a].x - ns[b].x) * (ns[a].x - ns[b].x) + (ns[a].y - ns[b].y) * (ns[a].y - ns[b].y));
        es[i] = Edge{a, b, c};
    }
    dijkstra(0);
    int p = n;
    while (p != 1)
    {
        way.emplace_back(rec[p]);
        p = es[rec[p]].u + es[rec[p]].v - p;
    }
    for (int lmt : way)
    {
        ans = min(ans, dijkstra(lmt));
    }
    printf("%.2lf\n", ans == 1e15 ? -1 : ans);
    return 0;
}