#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int v;
    __int128 w;
    bool operator<(const Path &oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> pq;
vector<pair<int, int>> es[100005];
int n, m, s, t, g, q, vis[100005];
__int128 dis[100005], h[100005], lmt[100005];
int main()
{
    cin >> n >> m >> s >> t >> g >> q;
    for (int i = 1; i <= n; i++)
    {
        int hi, li;
        cin >> hi >> li;
        h[i] = hi, lmt[i] = li;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back({v, w}), es[v].push_back({u, w});
    }
    fill(dis, dis + 1 + n, 1e30);
    lmt[s] = lmt[t] = 1e30, h[s] = h[t] = 0;
    pq.push(Path{s, 0}), dis[s] = 0;
    while (pq.size())
    {
        int now = pq.top().v;
        pq.pop();
        if (vis[now])
        {
            continue;
        }
        vis[now] = 1;
        for (auto e : es[now])
        {
            int nxt = e.first, w = e.second;
            if (dis[nxt] <= dis[now] + w || (lmt[nxt] - h[nxt] < q * (dis[now] + w)))
            {
                continue;
            }
            dis[nxt] = dis[now] + w;
            pq.push(Path{nxt, dis[nxt]});
        }
    }
    if (dis[t] <= g)
    {
        cout << (int)dis[t] << endl;
    }
    else
    {
        cout << "wtnap wa kotori no oyatsu desu!" << endl;
    }
    return 0;
}