#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    long long v, cap, cost;
};
Edge es[30005];
int n, m, st[405], vis[405], read();
long long maxf, minc, dis[405];
deque<int> q;
vector<int> to[405];
bool bfs()
{
    for (int i = 2; i <= n; i++)
    {
        vis[i] = st[i] = 0, dis[i] = 0x3f3f3f3f3f3f3f3f;
    }
    vis[1] = 1, dis[1] = st[1] = 0, q.push_back(1);
    long long tot = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop_front(), vis[now] = 0, tot -= dis[now];
        for (int eid : to[now])
        {
            long long nxt = es[eid].v, cap = es[eid].cap, cost = es[eid].cost;
            if (cap && dis[nxt] > dis[now] + cost)
            {
                dis[nxt] = dis[now] + cost;
                if (vis[nxt] == 0)
                {
                    vis[nxt] = 1;
                    if (q.size() && (dis[nxt] < dis[q.front()] || tot > dis[nxt] * (int)q.size()))
                    {
                        q.push_front(nxt);
                    }
                    else
                    {
                        q.push_back(nxt);
                    }
                }
            }
        }
    }
    return (dis[n] != 0x3f3f3f3f3f3f3f3f);
}
long long dfs(int now, long long flow)
{
    if (now == n)
    {
        return flow;
    }
    long long ans = 0;
    vis[now] = 1;
    for (int i = st[now]; i < (int)to[now].size(); i++)
    {
        st[now] = i;
        int eid = to[now][i];
        long long nxt = es[eid].v, cap = es[eid].cap, cost = es[eid].cost;
        if (cap && vis[nxt] == 0 && dis[nxt] == dis[now] + cost)
        {
            long long add = dfs(nxt, min(flow, cap));
            minc += cost * add, ans += add, flow -= add, es[eid].cap -= add;
            (eid <= m) ? es[eid + m].cap += add : es[eid - m].cap += add;
        }
    }
    if (ans == 0)
    {
        dis[now] = -1;
    }
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        long long s = read(), t = read(), cap = read(), cost = read();
        es[i] = Edge{t, cap, cost}, es[i + m] = Edge{s, 0, -cost};
        to[s].push_back(i), to[t].push_back(i + m);
    }
    while (bfs())
    {
        maxf += dfs(1, 1e15);
    }
    printf("%lld %lld\n", maxf, minc);
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
// TAG: 费用流 网络流 SPFA优化 Dinic