#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MX 1000005
int g[MX], dis[MX], last[MX], to[MX * 4], pre[MX * 4], vis[MX * 4], read();
queue<int> q;
void addEdge(int u, int v, int eid)
{
    pre[eid] = last[u], to[eid] = v;
    last[u] = eid;
}
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    ios::sync_with_stdio(false);
    int n = read(), m = read(), k = read(), pos = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        addEdge(u, v, ++pos);
        addEdge(v, u, ++pos);
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i, dis[i] = 0x3f3f3f3f;
    }
    for (int i = 1; i <= k; i++)
    {
        int x = read();
        dis[x] = 0, q.push(x);
    }
    int ans = 0x3f3f3f3f;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int x = (i % 2 == 0) ? i - 1 : i + 1;
            if (vis[x]) // 每条边只走一遍
            {
                continue;
            }
            vis[i] = 1;
            int nxt = to[i];
            if (dis[nxt] > dis[now] + 1)
            {
                dis[nxt] = dis[now] + 1, q.push(nxt);
            }
            int gnow = dfn(now), gnxt = dfn(nxt);
            if (gnow != gnxt)
            {
                g[gnxt] = gnow;
            }
            else
            {
                ans = min(ans, dis[nxt]); // 首次出换并不一定是答案,因为同点的出边没有先后
            }
        }
    }
    if (ans == 0 || ans == 0x3f3f3f3f)
    {
        cout << "Poor D!\n";
    }
    else
    {
        cout << ans << "\n";
    }
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