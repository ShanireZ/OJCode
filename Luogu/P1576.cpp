#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v;
    double w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
vector<Edge> es[2005];
priority_queue<Edge> q;
int n, m, s, t;
double dis[2005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].emplace_back(Edge{v, 1 - w / 100.0});
        es[v].emplace_back(Edge{u, 1 - w / 100.0});
    }
    cin >> s >> t;
    q.emplace(Edge{s, 1});
    while (q.size())
    {
        int now = q.top().v;
        double d = q.top().w;
        q.pop();
        if (dis[now] != 0)
        {
            continue;
        }
        dis[now] = d;
        for (Edge e : es[now])
        {
            if (dis[e.v] < dis[now] * e.w)
            {
                q.emplace(Edge{e.v, dis[now] * e.w});
            }
        }
    }
    cout << fixed << setprecision(8) << 100 / dis[t] << endl;
    return 0;
}