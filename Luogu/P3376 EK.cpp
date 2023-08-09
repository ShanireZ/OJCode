#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    long long to, w;
};
Edge es[10005];
int flag[205][205], vis[205], from[205], n, m, s, t;
long long flow[205];
vector<int> to[205];
queue<int> q;
long long bfs()
{
    memset(vis, 0, sizeof(vis)), memset(flow, 0, sizeof(flow)); // flow[t] = 0
    queue<int> tmp;
    swap(tmp, q);
    q.push(s), vis[s] = 1, flow[s] = 1e10;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int eid : to[now])
        {
            long long nxt = es[eid].to, cap = es[eid].w;
            if (vis[nxt] || cap == 0)
            {
                continue;
            }
            q.push(nxt), vis[nxt] = 1, flow[nxt] = min(flow[now], cap), from[nxt] = now;
            if (nxt == t)
            {
                goto pos;
            }
        }
    }
pos:
    int now = from[t], nxt = t;
    while (now && flow[t])
    {
        int eid = flag[now][nxt];
        es[eid].w -= flow[t];
        (eid <= m) ? (es[eid + m].w += flow[t]) : (es[eid - m].w += flow[t]);
        nxt = now, now = from[now];
    }
    return flow[t];
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        if (flag[u][v] == 0)
        {
            flag[u][v] = i, to[u].push_back(i), es[i].to = v;
            flag[v][u] = i + m, to[v].push_back(i + m), es[i + m].to = u;
        }
        es[flag[u][v]].w += w;
    }
    long long ans = 0, add = bfs();
    while (add)
    {
        ans += add;
        add = bfs();
    }
    cout << ans << "\n";
    return 0;
}