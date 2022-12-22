#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Edge
{
    int to;
    long long w;
};
vector<Edge> es[MX];
int fa[MX], vis[MX], n, m, q;
long long read(), val[MX];
void dfs(int now)
{
    vis[now] = 1;
    for (int i = 0; i < int(es[now].size()); i++)
    {
        int nxt = es[now][i].to;
        if (nxt != fa[now] && vis[nxt] == 0)
        {
            fa[nxt] = now, val[nxt] = val[now] ^ es[now][i].w;
            dfs(nxt);
        }
    }
}
int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        long long w = read();
        es[x].push_back(Edge{y, w}), es[y].push_back(Edge{x, w});
    }
    dfs(1);
    for (int i = 1; i <= q; i++)
    {
        int x = read(), y = read();
        printf("%lld\n", val[x] ^ val[y]);
    }
    return 0;
}
long long read()
{
    long long ans = 0;
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