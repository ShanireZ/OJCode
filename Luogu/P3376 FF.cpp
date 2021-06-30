#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int vis[205], last[205], flag[205][205];
int n, m, s, t;
struct Edge
{
    int to, pre;
    long long cap;
    Edge(int u = 0, int v = 0, long long w = 0)
    {
        to = v, cap = w;
        pre = last[u];
    }
};
Edge es[10005];
void addEdge(int eid, int u, int v, long long w)
{
    flag[u][v] = eid;
    es[eid] = Edge(u, v, w);
    last[u] = eid;
}
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    vis[now] = 1;
    long long add = 0;
    for (int i = last[now]; i != 0; i = es[i].pre)
    {
        int to = es[i].to;
        long long cap = es[i].cap;
        if (vis[to] == 1 || cap == 0)
        {
            continue;
        }
        add = dfs(to, min(flow, cap));
        if (add == 0)
        {
            continue;
        }
        es[i].cap -= add;
        if (i > m)
        {
            es[i - m].cap += add;
        }
        else
        {
            es[i + m].cap += add;
        }
        break;
    }
    return add;
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        if (flag[u][v] == 0)
        {
            addEdge(i, u, v, w);
            addEdge(i + m, v, u, 0);
        }
        else
        {
            int id = flag[u][v];
            es[id].cap += w;
        }
    }
    long long ans = 0;
    long long cur = dfs(s, 1e15);
    while (cur)
    {
        ans += cur;
        memset(vis, 0, sizeof(vis));
        cur = dfs(s, 1e15);
    }
    cout << ans << endl;
    return 0;
}