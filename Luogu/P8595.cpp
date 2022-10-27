#include <iostream>
using namespace std;
#define MX 2000005
int n, m, epos, dp[MX][3], chs[MX], vis[MX], last[MX], pre[MX * 2], to[MX * 2];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void dfs(int now)
{
    vis[now] = 1;
    int fst = 0, sec = 0;
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (vis[nxt])
        {
            continue;
        }
        dfs(nxt);
        int x = dp[nxt][0] - dp[nxt][1];
        if (x > fst)
        {
            sec = fst, fst = x;
        }
        else if (x > sec)
        {
            sec = x;
        }
        dp[now][0] += min(dp[nxt][0] - 1, dp[nxt][2]);
        dp[now][1] += dp[nxt][0];
    }
    dp[now][0] += chs[now] + 1;
    dp[now][1] -= fst;
    dp[now][2] = dp[now][1] - sec;
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
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        addEdge(u, v, ++epos), addEdge(v, u, ++epos);
        chs[u]++, chs[v]++;
    }
    int ans = n - 1 - m;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            ans += min(dp[i][0], dp[i][2]);
        }
    }
    printf("%d\n", ans);
    return 0;
}