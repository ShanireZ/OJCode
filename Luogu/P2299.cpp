#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int t, w;
    bool operator<(const Path &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
struct Edge
{
    int v, w;
};
vector<Edge> es[2505];
int n, m, dis[2505];
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w}), es[v].push_back(Edge{u, w});
    }
    q.push(Path{1, 0});
    while (q.size())
    {
        int now = q.top().t, w = q.top().w;
        q.pop();
        if (dis[now] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now] = w;
        for (Edge e : es[now])
        {
            int nxt = e.v, w = e.w;
            if (w + dis[now] < dis[nxt])
            {
                q.push(Path{nxt, w + dis[now]});
            }
        }
    }
    cout << dis[n] << endl;
    return 0;
}