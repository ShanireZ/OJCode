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
    Edge(int U, int V, int W)
    {
        u = U, v = V, w = W;
    }
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[5005];
priority_queue<Edge> q;
int dis[5005][2];
void dijk(int st, int n)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[st][0] = 0;
    for (int i = 0; i < es[st].size(); i++)
    {
        q.push(es[st][i]);
    }
    while (q.size())
    {
        Edge e = q.top();
        q.pop();
        if (dis[e.v][1] != 0x3f3f3f3f)
        {
            continue;
        }
        int from = e.u, now = e.v, w = e.w;
        (dis[now][0] == 0x3f3f3f3f) ? dis[now][0] = w : dis[now][1] = w;
        for (int i = 0; i < es[now].size(); i++)
        {
            e = es[now][i];
            int to = e.v, tw = e.w;
            if (dis[to][1] == 0x3f3f3f3f)
            {
                q.push(Edge(now, to, w + tw));
            }
        }
    }
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        es[u].push_back(Edge(u, v, w));
        es[v].push_back(Edge(v, u, w));
    }
    dijk(1, n);
    printf("%lld\n", dis[n][1]);
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