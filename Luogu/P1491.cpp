#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
int read();
struct Edge
{
    int u, v;
    double w;
    Edge(int U = 0, int V = 0, double W = 0)
    {
        u = U, v = V, w = W;
    }
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
struct Node
{
    int x, y, pre; //pre表示最短路的来源
    double d;
    vector<Edge> es;
};
Node ns[205];
double cntdis(int a, int b)
{
    double ans = (ns[a].x - ns[b].x) * (ns[a].x - ns[b].x) + (ns[a].y - ns[b].y) * (ns[a].y - ns[b].y);
    return sqrt(ans);
}
priority_queue<Edge> q;
double dijk(int st, int n, int banf, int bant) //除去指定边的最短路
{
    for (int i = 1; i <= n; i++)
    {
        ns[i].d = 1e15;
    }
    ns[st].d = 0;
    for (int i = 0; i < ns[st].es.size(); i++)
    {
        q.push(ns[st].es[i]);
    }
    while (q.size())
    {
        Edge e = q.top();
        q.pop();
        if (banf == e.u && bant == e.v || ns[e.v].d != 1e15)
        {
            continue;
        }
        int now = e.v;
        double w = e.w;
        ns[now].d = w, ns[now].pre = e.u;
        for (int i = 0; i < ns[now].es.size(); i++)
        {
            e = ns[now].es[i];
            int nxt = e.v;
            q.push(Edge(now, nxt, w + e.w));
        }
    }
    return ns[n].d;
}
vector<pair<int, int>> way; //最短路所有边
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].x = read(), ns[i].y = read();
    }
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        double w = cntdis(u, v);
        ns[u].es.push_back(Edge(u, v, w));
        ns[v].es.push_back(Edge(v, u, w));
    }
    dijk(1, n, 0, 0); //找到无限制的最短路
    int t = n, f = ns[n].pre;
    while (t != 1) //找到最短路的所有边
    {
        way.push_back(make_pair(f, t));
        t = f, f = ns[t].pre;
    }
    double ans = 1e16;
    for (int i = 0; i < way.size(); i++) //每次去掉一条最短路边，再跑最短路
    {
        ans = min(ans, dijk(1, n, way[i].first, way[i].second));
    }
    if (ans == 1e16)
    {
        printf("-1");
    }
    else
    {
        printf("%.2f", ans);
    }
    return 0;
}
int read()
{
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    int t = 1, ans = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}