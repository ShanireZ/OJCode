#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n, m, s, t, ind[10005], times[10005], ok[10005], vis[10005], dis[10005];
int last[10005], to[200005], pre[200005], read();
queue<int> q;
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id, ind[v]++;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        addEdge(v, u, i); // 建立反图
    }
    s = read(), t = read();
    q.push(t), vis[t] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i];
            ok[nxt] = (++times[nxt] == ind[nxt]); // 该点满足题意
            if (vis[nxt] == 0)
            {
                q.push(nxt), vis[nxt] = 1;
            }
        }
    }
    memset(vis, 0, sizeof(vis)), memset(dis, 0x3f, sizeof(dis));
    q.push(t), dis[t] = 0, vis[t] = 1;
    while (q.size()) // SPFA
    {
        int now = q.front();
        q.pop(), vis[now] = 0;
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i];
            if (ok[nxt] && dis[now] + 1 < dis[nxt])
            {
                dis[nxt] = dis[now] + 1;
                if (vis[nxt] == 0)
                {
                    q.push(nxt), vis[nxt] = 1;
                }
            }
        }
    }
    printf("%d\n", (dis[s] == 0x3f3f3f3f) ? -1 : dis[s]);
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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