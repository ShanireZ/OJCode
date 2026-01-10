#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
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
long long n, m, ct, hl, ans, c[100005], d[100005], vis[100005];
int main()
{
    cin >> n >> m >> ct >> hl;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w}), es[v].push_back(Edge{u, w});
    }
    fill(d + 1, d + 1 + n, 1e18);
    d[hl] = 0, q.push(Edge{hl, 0});
    while (q.size())
    {
        long long now = q.top().v, w = q.top().w;
        q.pop();
        if (vis[now] == 0)
        {
            vis[now] = 1;
            for (Edge e : es[now])
            {
                long long nxt = e.v, dis = e.w;
                if (d[nxt] > w + dis)
                {
                    d[nxt] = w + dis, q.push(Edge{nxt, d[nxt]});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += c[i] * (d[ct] > d[i]);
    }
    cout << ans << endl;
    return 0;
}