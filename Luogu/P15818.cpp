#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    long long id, dis;
    bool operator<(const Node &oth) const
    {
        return dis < oth.dis;
    }
};
Node ns[100005];
struct Edge
{
    long long v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[100005];
priority_queue<Edge> q;
long long ans = 1e18, sum, n, m, c, vis[100005];
int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
        sum += w;
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].id = i, ns[i].dis = 1e18;
    }
    q.push(Edge{1, 0});
    while (q.size())
    {
        long long now = q.top().v, w = q.top().w;
        q.pop();
        if (ns[now].dis == 1e18)
        {
            ns[now].dis = w;
            for (Edge e : es[now])
            {
                long long nxt = e.v, dis = e.w + ns[now].dis;
                if (dis < ns[nxt].dis)
                {
                    q.push(Edge{nxt, dis});
                }
            }
        }
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int now = ns[i].id;
        vis[now] = 1;
        for (Edge e : es[now])
        {
            if (vis[e.v])
            {
                sum -= e.w;
            }
        }
        ans = min(ans, c * ns[i].dis + sum);
    }
    cout << ans << endl;
    return 0;
}