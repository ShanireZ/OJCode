#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge
{
    int to, w;
    Edge(int To, int W)
    {
        to = To, w = W;
    }
    bool operator<(const Edge ano) const
    {
        return w > ano.w;
    }
};
vector<Edge> es[3005];
int n, m, vis[3005], t[3005];
long long dis[3005], d0[3005]; //最短路
int read();
bool spfa(int st)
{
    queue<int> q;
    memset(d0, 0x3f, sizeof(d0));
    q.push(st);
    vis[st] = 1; //st已在队列中
    d0[st] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0; //u不在队列中
        for (int i = 0; i < es[u].size(); i++)
        {
            int v = es[u][i].to, w = es[u][i].w;
            if (d0[u] + w < d0[v])
            {
                d0[v] = d0[u] + w;
                if (vis[v] == 0)
                {
                    q.push(v);
                    vis[v] = 1;
                    t[v]++;
                    if (t[v] > n)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void dijkstra(int st)
{
    priority_queue<Edge> q;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
    }
    dis[st] = 0;
    memset(vis, 0, sizeof(vis));
    q.push(Edge(st, 0));
    while (q.size())
    {
        int u = q.top().to;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (int i = 0; i < es[u].size(); i++)
        {
            int v = es[u][i].to, w = es[u][i].w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push(Edge(v, dis[v]));
            }
        }
    }
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        es[u].push_back(Edge(v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        es[0].push_back(Edge(i, 0));
    }
    if (spfa(0) == false) //SPFA判断负环
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < es[i].size(); j++)
        {
            es[i][j].w += d0[i] - d0[es[i][j].to];
        }
    }
    for (int i = 1; i <= n; i++) //n轮单源最短路
    {
        long long ans = 0;
        dijkstra(i);
        for (int j = 1; j <= n; j++) //统计答案
        {
            if (dis[j] == 1e9)
            {
                ans += j * dis[j];
            }
            else
            {
                ans += j * (dis[j] - d0[i] + d0[j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}