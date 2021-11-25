#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
struct Edge
{
    int to, l, pre;
};
Edge es[2000005];
int dis[1005][1005], last[1005], n, p, k, pos;
void addEdge(int u, int v, int w)
{
    es[++pos].pre = last[u];
    es[pos].to = v, es[pos].l = w;
    last[u] = pos;
}
struct Path
{
    int id, w, times;
    Path(int Id, int W, int Times)
    {
        id = Id, w = W, times = Times;
    }
    bool operator<(const Path oth) const
    {
        return w > oth.w;
    }
};
priority_queue<Path> q;
void dijkstra(int st)
{
    memset(dis, -1, sizeof(dis));
    q.push(Path(st, 0, 0));
    while (q.size())
    {
        int from = q.top().id, dfrom = q.top().w, times = q.top().times;
        q.pop();
        if (dis[from][times] != -1)
        {
            continue;
        }
        dis[from][times] = dfrom;
        for (int i = last[from]; i != 0; i = es[i].pre)
        {
            int to = es[i].to, dto = es[i].l;
            //使用免费机会
            if (times < k && dis[to][times + 1] == -1)
            {
                q.push(Path(to, dfrom, times + 1));
            }
            //不使用免费机会
            if (dis[to][times] == -1)
            {
                q.push(Path(to, max(dfrom, dto), times));
            }
        }
    }
}
int main()
{
    n = read(), p = read(), k = read();
    for (int i = 1; i <= p; i++)
    {
        int a = read(), b = read(), l = read();
        addEdge(a, b, l);
        addEdge(b, a, l);
    }
    dijkstra(1);
    printf("%d\n", dis[n][k]);
    return 0;
}