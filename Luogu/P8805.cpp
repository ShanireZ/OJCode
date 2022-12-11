#include <iostream>
using namespace std;
#define MX 100005
int read(), anc[MX][20], last[MX], pre[MX * 2], to[MX * 2], dp[MX], deg[MX], epos;
long long dl[MX][20];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id, deg[u]++;
}
void dfs(int now, int deep)
{
    dp[now] = deep, dl[now][0] = deg[anc[now][0]] + deg[now];
    for (int i = 1; i <= 18; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
        dl[now][i] = dl[anc[now][i - 1]][i - 1] + dl[now][i - 1] - deg[anc[now][i - 1]];
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt == anc[now][0])
        {
            continue;
        }
        anc[nxt][0] = now;
        dfs(nxt, deep + 1);
    }
}
long long query(int x, int y)
{
    long long ans = deg[x] + deg[y];
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 18; i >= 0; i--)
    {
        if (dp[anc[x][i]] >= dp[y])
        {
            ans += dl[x][i] - deg[x];
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return ans - deg[y];
    }
    for (int i = 18; i >= 0; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            ans += dl[x][i] - deg[x] + dl[y][i] - deg[y];
            x = anc[x][i], y = anc[y][i];
        }
    }
    return ans + deg[anc[x][0]];
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int a = read(), b = read();
        addEdge(a, b, ++epos), addEdge(b, a, ++epos);
    }
    dfs(1, 1);
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read();
        printf("%lld\n", query(a, b));
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