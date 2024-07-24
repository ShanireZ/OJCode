#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int anc[500005][20], dep[500005], n, m, s, maxs, epos;
int last[500005], pre[1000005], to[1000005];
void dfs(int now)
{
    for (int j = 1; j <= maxs; j++)
    {
        anc[now][j] = anc[anc[now][j - 1]][j - 1];
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt == anc[now][0])
        {
            continue;
        }
        anc[nxt][0] = now, dep[nxt] = dep[now] + 1;
        dfs(nxt);
    }
}
int lca(int u, int v)
{
    if (dep[v] > dep[u])
    {
        swap(u, v);
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (dep[anc[u][i]] >= dep[v])
        {
            u = anc[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (anc[u][i] == anc[v][i])
        {
            continue;
        }
        u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}
void addEdge(int u, int v)
{
    epos++;
    to[epos] = v, pre[epos] = last[u];
    last[u] = epos;
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    maxs = log2(n), dep[s] = 1;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v), addEdge(v, u);
    }
    dfs(s);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}