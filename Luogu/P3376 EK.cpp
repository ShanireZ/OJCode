#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, m, s, t;
int last[10005], vis[205], flag[205][205], his[205];
long long flow[205];
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
long long bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    flow[s] = 1e15;
    while (q.size())
    {
        int from = q.front();
        q.pop();
        for (int i = last[from]; i != 0; i = es[i].pre)
        {
            int to = es[i].to;
            long long cap = es[i].cap;
            if (vis[to] == 1 || cap == 0)
            {
                continue;
            }
            flow[to] = min(flow[from], cap);
            q.push(to);
            vis[to] = 1;
            his[to] = from;
            if (to == t)
            {
                return flow[t];
            }
        }
    }
    return 0;
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
    long long add = bfs();
    while (add)
    {
        ans += add;
        int to = t;
        int from = his[to];
        while (to != s)
        {
            int i = flag[from][to], j = flag[to][from];
            es[i].cap -= add;
            es[j].cap += add;
            to = from;
            from = his[to];
        }
        add = bfs();
    }
    cout << ans << endl;
    return 0;
}