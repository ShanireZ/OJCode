#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int read();
struct Edge
{
    int u, v, w;
    Edge(int U = 0, int V = 0, int W = 0)
    {
        u = U, v = V, w = W;
    }
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[3000];
priority_queue<Edge> q;
int dis[3000];
void dijk(int st, int n)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = 0; i < es[st].size(); i++)
    {
        q.push(es[st][i]);
    }
    while (q.size())
    {
        Edge e = q.top();
        q.pop();
        if (dis[e.v] != 0x3f3f3f3f)
        {
            continue;
        }
        int now = e.v, w = e.w;
        dis[now] = w;
        for (int i = 0; i < es[now].size(); i++)
        {
            e = es[now][i];
            int to = e.v, tw = e.w;
            if (dis[to] == 0x3f3f3f3f)
            {
                q.push(Edge(now, to, w + tw));
            }
        }
    }
}
int main()
{
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), w = read();
        for (int t = 0; t < k; t++)
        {
            es[a + t * n].push_back(Edge(a + t * n, b + t * n, w));
            es[b + t * n].push_back(Edge(b + t * n, a + t * n, w));
            es[a + t * n].push_back(Edge(a + t * n, b + (t + 1) * n, w / 2));
            es[b + t * n].push_back(Edge(b + t * n, a + (t + 1) * n, w / 2));
        }
        es[a + k * n].push_back(Edge(a + k * n, b + k * n, w));
        es[b + k * n].push_back(Edge(b + k * n, a + k * n, w));
    }
    dijk(1, n);
    int ans = 1e9;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dis[n + i * n]);
    }
    printf("%d", ans);
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