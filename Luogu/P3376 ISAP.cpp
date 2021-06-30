#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
long long read() //快读
{
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    long long t = 1, n = 0;
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
int n, m, s, t;
int g[205], dep[205], last[205], nlast[205], flag[205][205];
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
int bfs()
{
    queue<int> q;
    dep[t] = 1;
    g[1]++;
    q.push(t);
    while (q.size())
    {
        int from = q.front();
        q.pop();
        for (int i = last[from]; i != 0; i = es[i].pre)
        {
            int to = es[i].to;
            if (dep[to] != 0)
            {
                continue;
            }
            dep[to] = dep[from] + 1;
            g[dep[to]]++;
            q.push(to);
        }
    }
    return dep[s];
}
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    long long add = 0;
    for (int i = nlast[now]; i != 0; i = es[i].pre)
    {
        nlast[now] = i;
        int to = es[i].to;
        long long cap = es[i].cap;
        if (cap == 0 || dep[to] + 1 != dep[now])
        {
            continue;
        }
        long long cur = dfs(to, min(flow, cap));
        flow -= cur;
        add += cur;
        es[i].cap -= cur;
        if (i > m)
        {
            es[i - m].cap += cur;
        }
        else
        {
            es[i + m].cap += cur;
        }
        if (flow == 0)
        {
            return add;
        }
    }
    //? 至此说明仍有剩余流量
    g[dep[now]]--;
    if (g[dep[now]] == 0)
    {
        dep[s] = n + 1;
    }
    dep[now]++;
    g[dep[now]]++;
    return add;
}
int main()
{
    n = read(), m = read(), s = read(), t = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        long long w = read();
        if (flag[u][v] == 0)
        {
            addEdge(i, u, v, w);
            addEdge(i + m, v, u, 0);
        }
        else
        {
            int eid = flag[u][v];
            es[eid].cap += w;
        }
    }
    long long ans = 0;
    if (bfs())
    {
        memcpy(nlast, last, sizeof(last));
        ans += dfs(s, 1e15);
        while (dep[s] <= n)
        {
            memcpy(nlast, last, sizeof(last));
            ans += dfs(s, 1e15);
        }
    }
    printf("%lld\n", ans);
    return 0;
}