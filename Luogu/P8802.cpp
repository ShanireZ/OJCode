#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int to, w;
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> g[1005];
priority_queue<Edge> q;
int n, m, wt[1005], dis[1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(Edge{v, c + wt[v]});
        g[v].push_back(Edge{u, c + wt[u]});
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push(Edge{1, 0});
    while (q.size())
    {
        int now = q.top().to, dnow = q.top().w;
        q.pop();
        if (dis[now] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now] = dnow;
        for (int i = 0; i < int(g[now].size()); i++)
        {
            int nxt = g[now][i].to, d = g[now][i].w;
            if (dis[nxt] > dis[now] + d)
            {
                q.push(Edge{nxt, dis[now] + d});
            }
        }
    }
    cout << dis[n] - wt[n] << "\n";
    return 0;
}