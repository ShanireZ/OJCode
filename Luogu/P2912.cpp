#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v, w;
};
vector<Edge> es[1005];
int anc[1005][15], dis[1005][15], dep[1005], n, q, maxs;
void dfs(int now)
{
    for (int j = 1; j <= maxs; j++)
    {
        anc[now][j] = anc[anc[now][j - 1]][j - 1];
        dis[now][j] = dis[now][j - 1] + dis[anc[now][j - 1]][j - 1];
    }
    for (Edge e : es[now])
    {
        if (e.v == anc[now][0])
        {
            continue;
        }
        anc[e.v][0] = now, dis[e.v][0] = e.w, dep[e.v] = dep[now] + 1;
        dfs(e.v);
    }
}
int lca(int u, int v)
{
    int ans = 0;
    if (dep[u] < dep[v])
    {
        swap(u, v);
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (dep[anc[u][i]] >= dep[v])
        {
            ans += dis[u][i];
            u = anc[u][i];
        }
    }
    if (u == v)
    {
        return ans;
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (anc[u][i] != anc[v][i])
        {
            ans += dis[u][i] + dis[v][i];
            u = anc[u][i], v = anc[v][i];
        }
    }
    return ans + dis[u][0] + dis[v][0];
}
int main()
{
    cin >> n >> q;
    maxs = log2(n), dep[1] = 1;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].emplace_back(Edge{v, w}), es[v].emplace_back(Edge{u, w});
    }
    dfs(1);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}