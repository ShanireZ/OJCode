#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    long long v, w, c;
};
Edge es[100005];
vector<int> to[5005];
queue<int> q;
long long dis[5005], vis[5005], st[5005], n, m, s, t, maxf, minc;
int bfs()
{
    memset(dis, 0x3f, sizeof(dis)), memset(vis, 0, sizeof(vis)), memset(st, 0, sizeof(st));
    queue<int> sp;
    swap(sp, q), q.push(s), vis[s] = 1, dis[s] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (int eid : to[now])
        {
            long long nxt = es[eid].v, cap = es[eid].w, c = es[eid].c;
            if (cap == 0 || dis[nxt] <= dis[now] + c)
            {
                continue;
            }
            dis[nxt] = dis[now] + c;
            if (vis[nxt] == 0)
            {
                q.push(nxt), vis[nxt] = 1;
            }
        }
    }
    return (dis[t] != 0x3f3f3f3f3f3f3f3f);
}
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    vis[now] = 1;
    long long tot = 0;
    for (int i = st[now]; i < (int)to[now].size(); i++)
    {
        st[now] = i;
        int eid = to[now][i];
        long long nxt = es[eid].v, cap = es[eid].w, c = es[eid].c;
        if (cap == 0 || vis[nxt] == 1 || dis[nxt] != dis[now] + c)
        {
            continue;
        }
        long long add = dfs(nxt, min(flow, cap));
        tot += add, minc += add * c, flow -= add, es[eid].w -= add;
        (eid <= m) ? es[eid + m].w += add : es[eid - m].w += add;
    }
    return tot;
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        long long u, v, w, c;
        cin >> u >> v >> w >> c;
        es[i] = Edge{v, w, c}, es[i + m] = Edge{u, 0, -c};
        to[u].push_back(i), to[v].push_back(i + m);
    }
    while (bfs())
    {
        maxf += dfs(s, 1e12);
    }
    cout << maxf << " " << minc << "\n";
    return 0;
}