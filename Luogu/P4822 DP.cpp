#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int read();
struct Edge
{
    int u, v, w, times;
    Edge(int U = 0, int V = 0, int W = 0, int T = 0)
    {
        u = U, v = V, w = W, times = T;
    }
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[55];
priority_queue<Edge> q;
int dis[55][55];
void dijk(int st, int n, int k)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[st][0] = 0;
    for (int i = 0; i < es[st].size(); i++)
    {
        int to = es[st][i].v, w = es[st][i].w;
        q.push(Edge(st, to, w, 0));
        q.push(Edge(st, to, w / 2, 1));
    }
    while (q.size())
    {
        Edge e = q.top();
        q.pop();
        int now = e.v, w = e.w, times = e.times;
        if (dis[now][times] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now][times] = w;
        for (int i = 0; i < es[now].size(); i++)
        {
            e = es[now][i];
            int to = e.v, tw = e.w;
            //走折半路线
            if (times < k && dis[to][times + 1] == 0x3f3f3f3f)
            {
                q.push(Edge(now, to, w + tw / 2, times + 1));
            }
            //不走折半路线
            if (dis[to][times] == 0x3f3f3f3f)
            {
                q.push(Edge(now, to, w + tw, times));
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
        es[a].push_back(Edge(a, b, w, 0));
        es[b].push_back(Edge(b, a, w, 0));
    }
    dijk(1, n, k);
    int ans = 1e9;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dis[n][i]);
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