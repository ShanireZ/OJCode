#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Edge> q;
vector<Edge> g[1005][2];
int dis[1005][2], vis[1005][2], n, m, s, ans;
void dijkstra(int opt)
{
    q.push(Edge{s, 0}), dis[s][opt] = 0;
    while (q.size())
    {
        int now = q.top().v;
        q.pop();
        if (vis[now][opt])
        {
            continue;
        }
        vis[now][opt] = 1;
        for (Edge e : g[now][opt])
        {
            int nxt = e.v, w = e.w;
            if (dis[nxt][opt] > dis[now][opt] + w)
            {
                dis[nxt][opt] = dis[now][opt] + w;
                q.push(Edge{nxt, dis[now][opt] + w});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][0].push_back(Edge{v, w});
        g[v][1].push_back(Edge{u, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    dijkstra(0);
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dis[i][0] + dis[i][1]);
    }
    cout << ans << endl;
    return 0;
}