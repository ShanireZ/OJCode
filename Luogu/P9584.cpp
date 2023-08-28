#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MOD 998244353
struct Node
{
    long long sz, v, tot, fa;
};
Node ns[200005];
struct Edge
{
    long long v, w;
};
vector<Edge> to[200005];
long long n, q, ans;
void dfs(int now)
{
    ns[now].sz = 1;
    for (Edge e : to[now])
    {
        long long nxt = e.v, w = e.w;
        if (nxt != ns[now].fa)
        {
            ns[nxt].fa = now, ns[nxt].v = w;
            dfs(nxt);
            ns[now].sz += ns[nxt].sz;
        }
    }
    ns[1].tot += ns[now].v * ns[now].sz;
}
void dfs2(int now)
{
    if (now != 1)
    {
        ns[now].tot = ns[ns[now].fa].tot + (n - ns[now].sz * 2) * ns[now].v;
    }
    for (Edge e : to[now])
    {
        long long nxt = e.v;
        if (nxt != ns[now].fa)
        {
            dfs2(nxt);
        }
    }
    ans = (ns[now].tot + ans) % MOD;
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        to[u].push_back(Edge{v, w}), to[v].push_back(Edge{u, w});
    }
    dfs(1), dfs2(1);
    while (q--)
    {
        long long k, w;
        cin >> k >> w;
        cout << (ans + (ns[k].tot + n * w) * 2) % MOD << endl;
    }
    return 0;
}
// TAG: 树的重心 树上DP 点权边权转换