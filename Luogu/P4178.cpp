#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[40005];
int n, k, ans, core, rpos, dpos, zson[40005], sz[40005], d[40005], vis[40005], rec[5000005];
void findcore(int now, int fa, int sum)
{
    sz[now] = 1, zson[now] = 0;
    for (Edge e : es[now])
    {
        if (e.v == fa || vis[e.v])
        {
            continue;
        }
        findcore(e.v, now, sum);
        sz[now] += sz[e.v];
        zson[now] = max(zson[now], sz[e.v]);
    }
    zson[now] = max(zson[now], sum - sz[now]);
    if (zson[now] < zson[core])
    {
        core = now;
    }
}
void dfs(int now, int fa, int dis)
{
    if (dis > k)
    {
        return;
    }
    ans++, d[++dpos] = dis;
    for (Edge e : es[now])
    {
        if (e.v == fa || vis[e.v])
        {
            continue;
        }
        dfs(e.v, now, dis + e.w);
    }
}
void solve(int root)
{
    rpos = 0, vis[root] = 1;
    for (Edge e : es[root])
    {
        if (vis[e.v])
        {
            continue;
        }
        dpos = 0, dfs(e.v, root, e.w);
        for (int i = 1; i <= rpos; i++)
        {
            for (int j = 1; j <= dpos; j++)
            {
                ans += (rec[i] + d[j] <= k);
            }
        }
        for (int j = 1; j <= dpos; j++)
        {
            rec[++rpos] = d[j];
        }
    }
    for (Edge e : es[root])
    {
        if (vis[e.v])
        {
            continue;
        }
        core = 0, findcore(e.v, 0, sz[e.v]);
        solve(core);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(Edge{v, w});
        es[v].push_back(Edge{u, w});
    }
    cin >> k;
    zson[0] = 1e9, findcore(1, 0, n);
    solve(core);
    cout << ans << endl;
    return 0;
}