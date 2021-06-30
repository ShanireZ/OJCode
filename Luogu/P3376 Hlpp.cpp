#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
long long read()
{
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    long long n = 0;
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n;
}
int n, m, s, t;
int last[205], dep[205], g[205], flag[205][205], inq[205];
long long val[205];
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
    es[eid] = Edge(u, v, w);
    flag[u][v] = last[u] = eid;
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
            int eid = flag[to][from];
            if (es[eid].cap == 0 || dep[to] != 0)
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
struct cmp
{
    bool operator()(const int a, const int b) const
    {
        return dep[a] < dep[b];
    }
};
priority_queue<int, vector<int>, cmp> yx;
void pushFlow(int now)
{
    for (int i = last[now]; i != 0; i = es[i].pre)
    {
        int to = es[i].to;
        long long cap = es[i].cap;
        if (cap == 0 || dep[to] + 1 != dep[now])
        {
            continue;
        }
        long long flow = min(cap, val[now]);
        val[now] -= flow;
        val[to] += flow;
        es[i].cap -= flow;
        if (i > m)
        {
            es[i - m].cap += flow;
        }
        else
        {
            es[i + m].cap += flow;
        }
        if (inq[to] == 0 && to != s && to != t)
        {
            inq[to] = 1;
            yx.push(to);
        }
        if (val[now] == 0)
        {
            break;
        }
    }
}
void reDep(int now)
{
    dep[now] = 500;
    for (int i = last[now]; i != 0; i = es[i].pre)
    {
        int to = es[i].to;
        long long cap = es[i].cap;
        if (cap != 0)
        {
            dep[now] = min(dep[now], dep[to] + 1);
        }
    }
}
long long hlpp()
{
    if (bfs() == 0)
    {
        return 0;
    }
    g[dep[s]]--;
    g[n]++;
    dep[s] = n;
    for (int i = last[s]; i != 0; i = es[i].pre)
    {
        int to = es[i].to;
        long long cap = es[i].cap;
        if (cap == 0)
        {
            continue;
        }
        val[s] -= cap;
        val[to] += cap;
        es[i].cap -= cap;
        if (i > m)
        {
            es[i - m].cap += cap;
        }
        else
        {
            es[i + m].cap += cap;
        }
        if (to != s && to != t && inq[to] == 0)
        {
            yx.push(to);
            inq[to] = 1;
        }
    }
    while (yx.size())
    {
        int from = yx.top();
        yx.pop();
        inq[from] = 0;
        pushFlow(from);
        if (val[from] == 0)
        {
            continue;
        }
        g[dep[from]]--;
        if (g[dep[from]] == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dep[i] > dep[from] && i != s && i != t)
                {
                    dep[i] = n + 1;
                }
            }
        }
        reDep(from);
        g[dep[from]]++;
        yx.push(from);
        inq[from] = 1;
    }
    return val[t];
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
    printf("%lld\n", hlpp());
    return 0;
}