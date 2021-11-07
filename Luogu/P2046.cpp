#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int read();
struct Edge
{
    int to, w, pre;
};
Edge es[2000005];
struct Path
{
    int to, w;
    Path(int TO, int W)
    {
        to = TO, w = W;
    }
    bool operator<(const Path ano) const
    {
        return w > ano.w;
    }
};
priority_queue<Path> q;
int last[300005], dis[300005], vis[300005], d[4][300005];
int n, cnt, s = 300003, t = 300004;
void addEdge(int u, int v, int w)
{
    es[++cnt].pre = last[u];
    es[cnt].to = v, es[cnt].w = w;
    last[u] = cnt;
}
int dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(Path(s, 0));
    while (q.size())
    {
        int from = q.top().to;
        q.pop();
        if (vis[from])
        {
            continue;
        }
        vis[from] = 1;
        for (int i = last[from]; i != 0; i = es[i].pre)
        {
            int to = es[i].to, w = es[i].w;
            if (vis[to] || dis[from] + w >= dis[to])
            {
                continue;
            }
            dis[to] = dis[from] + w;
            q.push(Path(to, dis[to]));
        }
    }
    return dis[t];
}
int main()
{
    n = read();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= n * (n + 1); j++)
        {
            d[i][j] = read();
        }
    }
    int uid = 1, vid = 1, pos = 1;
    for (int j = 1; j <= n; j++)
    {
        addEdge(uid, t, d[0][pos]);
        addEdge(t, uid, d[2][pos]);
        uid++, pos++;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            addEdge(uid, vid, d[0][pos]);
            addEdge(vid, uid, d[2][pos]);
            uid++, vid++, pos++;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        addEdge(s, vid, d[0][pos]);
        addEdge(vid, s, d[2][pos]);
        vid++, pos++;
    }
    uid = vid = pos = 1;
    for (int i = 1; i <= n; i++)
    {
        addEdge(s, vid, d[1][pos]);
        addEdge(vid, s, d[3][pos]);
        vid++, pos++;
        for (int j = 2; j <= n; j++)
        {
            addEdge(uid, vid, d[1][pos]);
            addEdge(vid, uid, d[3][pos]);
            uid++, vid++, pos++;
        }
        addEdge(uid, t, d[1][pos]);
        addEdge(t, uid, d[3][pos]);
        uid++, pos++;
    }
    printf("%d\n", dijkstra());
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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