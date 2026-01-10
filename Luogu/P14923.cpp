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
long long n, m, ct, hl, ans, c[100005], dc[100005], dm[100005], vis[100005];
void bfs(int op)
{
    op == 1 ? fill(dc + 1, dc + n + 1, 1e18) : fill(dm + 1, dm + n + 1, 1e18);
    op == 1 ? dc[ct] = 0 : dm[hl] = 0;
    q.push(Edge{op == 1 ? ct : hl, 0});
    while (q.size())
    {
        long long now = q.top().v, w = q.top().w;
        q.pop();
        if (vis[now] == 1)
        {
            continue;
        }
        vis[now] = 1;
        for (Edge e : es[now])
        {
            long long nxt = e.v, dis = e.w;
            if (op == 1 && dc[nxt] > w + dis)
            {
                dc[nxt] = w + dis, q.push(Edge{nxt, dc[nxt]});
            }
            else if (op == 2 && dm[nxt] > w + dis)
            {
                dm[nxt] = w + dis, q.push(Edge{nxt, dm[nxt]});
            }
        }
    }
    fill(vis + 1, vis + n + 1, 0);
}
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
    bfs(1), bfs(2);
    for (int i = 1; i <= n; i++)
    {
        if (dc[hl] > dm[i])
        {
            ans += c[i];
        }
    }
    cout << ans << endl;
    return 0;
}