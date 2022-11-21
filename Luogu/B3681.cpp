#include <iostream>
using namespace std;
#define MX 1000005
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
int n, cnt, last[MX], pre[MX], to[MX];
long long sz[MX];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void dfs(int now)
{
    for (int i = last[now]; i; i = pre[i])
    {
        dfs(to[i]);
        sz[now] += sz[to[i]];
    }
}
int main()
{
    n = read();
    for (int i = 2; i <= n; i++)
    {
        int x = read();
        addEdge(x, i, ++cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        sz[i] = read();
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", sz[i]);
    }
    return 0;
}