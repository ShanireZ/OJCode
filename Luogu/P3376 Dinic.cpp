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
int flag[205][205], deep[205], st[205], n, m, s, t;
vector<int> to[205];
queue<int> q;
int bfs()
{
    memset(st, 0, sizeof(st)), memset(deep, 0, sizeof(deep));
    queue<int> tmp;
    swap(tmp, q);
    q.push(s), deep[s] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int eid : to[now])
        {
            int nxt = es[eid].to;
            if (deep[nxt] || es[eid].w == 0)
            {
                continue;
            }
            q.push(nxt), deep[nxt] = deep[now] + 1;
            if (nxt == t)
            {
                return deep[t];
            }
        }
    }
    return 0;
}
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    long long tot = 0;
    for (int i = st[now]; i < (int)to[now].size(); st[now] = ++i)
    {
        int eid = to[now][i];
        long long nxt = es[eid].to, cap = es[eid].w;
        if (deep[nxt] != deep[now] + 1 || cap == 0)
        {
            continue;
        }
        long long add = dfs(nxt, min(flow, cap));
        es[eid].w -= add, tot += add, flow -= add;
        (eid <= m) ? es[eid + m].w += add : es[eid - m].w += add;
    }
    if (tot == 0)
    {
        deep[now] = -1;
    }
    return tot;
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
    long long ans = 0;
    while (bfs())
    {
        ans += dfs(s, 1e10);
    }
    cout << ans << "\n";
    return 0;
}