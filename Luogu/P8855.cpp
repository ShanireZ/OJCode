#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int anc[30005][20], dep[30005], n, m, maxs;
vector<int> to[30005];
void dfs(int now)
{
    for (int i = 1; i <= maxs; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        if (nxt == anc[now][0])
        {
            continue;
        }
        dep[nxt] = dep[now] + 1, anc[nxt][0] = now;
        dfs(nxt);
    }
}
int lca(int u, int v)
{
    int res = 0;
    if (dep[u] < dep[v])
    {
        swap(u, v);
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (dep[anc[u][i]] >= dep[v])
        {
            u = anc[u][i], res += (1 << i);
        }
    }
    if (u == v)
    {
        return res;
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (anc[u][i] != anc[v][i])
        {
            u = anc[u][i], v = anc[v][i], res += (1 << i) * 2;
        }
    }
    return res + 2;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    dep[1] = 1, maxs = log2(n), dfs(1);
    int cur = 1, ans = 0;
    cin >> m;
    while (m--)
    {
        int v;
        cin >> v;
        ans += lca(cur, v);
        cur = v;
    }
    cout << ans << endl;
    return 0;
}