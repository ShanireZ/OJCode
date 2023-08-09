#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    long long to, w;
};
Edge es[10005];
int flag[205][205], vis[205], n, m, s, t;
vector<int> to[205];
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    vis[now] = 1;
    for (int eid : to[now])
    {
        long long nxt = es[eid].to, cap = es[eid].w;
        if (vis[nxt] == 1 || cap == 0)
        {
            continue;
        }
        long long add = dfs(nxt, min(flow, cap));
        if (add)
        {
            es[eid].w -= add;
            (eid <= m) ? (es[eid + m].w += add) : (es[eid - m].w += add);
            return add;
        }
    }
    return 0;
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
    long long ans = 0, add = dfs(s, 1e10);
    while (add)
    {
        ans += add;
        memset(vis, 0, sizeof(vis));
        add = dfs(s, 1e10);
    }
    cout << ans << "\n";
    return 0;
}