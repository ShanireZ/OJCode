#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    long long to, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> g[3005];
priority_queue<Edge> pq;
queue<int> q;
long long h[3005], dis[3005], len[3005], vis[3005], n, m;
bool SPFA()
{
    memset(h, 0x3f, sizeof(h));
    q.emplace(n + 1), vis[n + 1] = 1, h[n + 1] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (Edge e : g[now])
        {
            int nxt = e.to, w = e.w;
            if (h[now] + w < h[nxt])
            {
                h[nxt] = h[now] + w, len[nxt] = len[now] + 1;
                if (len[nxt] > n)
                {
                    return 0;
                }
                if (vis[nxt] == 0)
                {
                    q.emplace(nxt), vis[nxt] = 1;
                }
            }
        }
    }
    return 1;
}
void dijkstra(int s)
{
    fill(dis + 1, dis + 1 + n, 1e9);
    dis[s] = 0, pq.emplace(Edge{s, 0});
    while (pq.size())
    {
        int now = pq.top().to, w = pq.top().w;
        pq.pop();
        if (dis[now] == w)
        {
            for (Edge e : g[now])
            {
                int nxt = e.to, d = e.w;
                if (dis[nxt] > dis[now] + d)
                {
                    dis[nxt] = dis[now] + d;
                    pq.emplace(Edge{nxt, dis[nxt]});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(Edge{v, w});
    }
    for (int i = 1; i <= n; i++)
    {
        g[n + 1].emplace_back(Edge{i, 0});
    }
    if (SPFA() == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)g[i].size(); j++)
        {
            int nxt = g[i][j].to, w = g[i][j].w;
            g[i][j].w = w + h[i] - h[nxt];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        long long ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] == 1e9)
            {
                ans += j * 1e9;
            }
            else
            {
                ans += j * (dis[j] - h[i] + h[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}