#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v;
    long long w;
};
Edge es[10005];
int flag[105][105], st[105], dp[105], s, t, n, m;
vector<int> to[105];
queue<int> q;
int bfs()
{
    memset(st, 0, sizeof(st)), memset(dp, 0, sizeof(dp));
    q.push(s), dp[s] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int eid : to[now])
        {
            int nxt = es[eid].v;
            long long cap = es[eid].w;
            if (cap && dp[nxt] == 0)
            {
                dp[nxt] = dp[now] + 1, q.push(nxt);
            }
        }
    }
    return dp[t];
}
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    long long ans = 0;
    for (int i = st[now]; i < (int)to[now].size(); i++)
    {
        st[now] = i;
        int eid = to[now][i];
        int nxt = es[eid].v;
        long long cap = es[eid].w;
        if (dp[nxt] == dp[now] + 1 && cap)
        {
            long long add = dfs(nxt, min(flow, cap));
            ans += add, flow -= add, es[eid].w -= add;
            eid <= m ? es[eid + m].w += add : es[eid - m].w += add;
        }
    }
    if (ans == 0)
    {
        dp[now] = 0;
    }
    return ans;
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (flag[u][v])
        {
            es[flag[u][v]].w += w;
        }
        else
        {
            es[i] = Edge{v, w}, es[i + m] = Edge{u, 0};
            flag[u][v] = i, flag[v][u] = i + m, to[u].push_back(i), to[v].push_back(i + m);
        }
    }
    long long ans = 0;
    while (bfs())
    {
        ans += dfs(s, 1e15);
    }
    cout << ans << endl;
    return 0;
}
// TAG: 网络流 最大流 最小割 Dinic