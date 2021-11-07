#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int read();
struct Edge
{
    int to, w, pre;
} es[7000008];
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
int last[2000008], vis[2000008], dis[2000008];
int n, m, cnt, s = 2000003, t = 2000004;
void addEdge(int u, int v, int w)
{
    es[++cnt].to = v;
    es[cnt].w = w;
    es[cnt].pre = last[u];
    last[u] = cnt;
}
void dijkstra()
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
        for (int i = last[from]; i; i = es[i].pre)
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
}
int main()
{
    n = read(), m = read();
    int uid = 1, vid = 2, d;
    for (int j = 1; j < m; j++)
    {
        d = read();
        addEdge(t, vid, d);
        addEdge(vid, t, d);
        vid += 2;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            d = read();
            addEdge(uid, vid, d);
            addEdge(vid, uid, d);
            uid += 2, vid += 2;
        }
    }
    for (int j = 1; j < m; j++)
    {
        d = read();
        addEdge(uid, s, d);
        addEdge(s, uid, d);
        uid += 2;
    }
    uid = 2, vid = 1;
    for (int i = 1; i < n; i++)
    {
        d = read();
        addEdge(s, vid, d);
        addEdge(vid, s, d);
        vid += 2;
        for (int j = 2; j < m; j++)
        {
            d = read();
            addEdge(uid, vid, d);
            addEdge(vid, uid, d);
            uid += 2, vid += 2;
        }
        d = read();
        addEdge(uid, t, d);
        addEdge(t, uid, d);
        uid += 2;
    }
    uid = 1, vid = 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int d = read();
            addEdge(uid, vid, d);
            addEdge(vid, uid, d);
            uid += 2, vid += 2;
        }
    }
    dijkstra();
    printf("%d\n", dis[t]);
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