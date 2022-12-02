#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 200005
int read(), n, q, K, epos, last[MX], pre[MX * 2], to[MX * 2], dp[MX], anc[MX][20];
long long a[MX], mn[MX], dis[MX][20][5][5]; // dis[起点][2^x步][起始中转][结束中转]
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v, last[u] = id;
}
void dfs(int now, int deep)
{
    dp[now] = deep;
    for (int i = 1; i < 20; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    if (K >= 2) // 可中转1次 dis[now][0][1][1]没有意义
    {
        dis[now][0][1][0] = a[anc[now][0]], dis[now][0][0][1] = 0;
    }
    if (K == 3) // 可中转2次 dis[now][0][2][1]没有意义
    {
        dis[now][0][2][0] = a[anc[now][0]], dis[now][0][1][2] = 0, dis[now][0][2][2] = mn[now];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int st = 0; st < K; st++)
        {
            for (int mid = 0; mid < K; mid++)
            {
                for (int ed = 0; ed < K; ed++)
                {
                    dis[now][i][st][ed] = min(dis[now][i][st][ed], dis[now][i - 1][st][mid] + dis[anc[now][i - 1]][i - 1][mid][ed]);
                }
            }
        }
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt != anc[now][0])
        {
            anc[nxt][0] = now, dis[nxt][0][0][0] = a[now];
            dfs(nxt, deep + 1);
        }
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 19; i >= 0; i--)
    {
        if (dp[anc[x][i]] >= dp[y])
        {
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i], y = anc[y][i];
        }
    }
    return anc[x][0];
}
vector<long long> path(int x, int z) // 统计x->z路径中转0/1/2次的最短距离
{
    vector<long long> ans(3, a[x]);
    for (int i = 19; i >= 0; i--)
    {
        if (dp[anc[x][i]] >= dp[z])
        {
            vector<long long> now(3, 0x3f3f3f3f3f3f3f3f);
            for (int s = 0; s < K; s++)
            {
                for (int t = 0; t < K; t++)
                {
                    now[t] = min(now[t], ans[s] + dis[x][i][s][t]);
                }
            }
            ans = now, x = anc[x][i];
        }
    }
    return ans;
}
int main()
{
    n = read(), q = read(), K = read();
    for (int i = 1; i <= n; i++)
    {
        mn[i] = a[i] = read();
    }
    for (int i = 1; i < n; i++)
    {
        int x = read(), y = read();
        addEdge(x, y, ++epos), addEdge(y, x, ++epos);
        mn[x] = min(mn[x], a[y]), mn[y] = min(mn[y], a[x]);
    }
    memset(dis, 0x3f, sizeof(dis));
    dfs(1, 1);
    for (int i = 1; i <= q; i++)
    {
        int x = read(), y = read();
        int z = lca(x, y);
        vector<long long> vx = path(x, z), vy = path(y, z);
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int s = 0; s < K; s++)
        {
            for (int t = 0; t < K; t++)
            {
                ans = min(ans, vx[s] + vy[t] + (s + t > K) * mn[z]); // 如果次数超出需要额外中转
            }
        }
        ans = min(ans, vx[0] + vy[0] - a[z]); // lca多次累加需刨除一次
        printf("%lld\n", ans);
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