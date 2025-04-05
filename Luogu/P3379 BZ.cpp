#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tr[500005];
int n, m, root, anc[500005][20], dp[500005];
void dfs(int now, int from)
{
    for (int nxt : tr[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dp[nxt] = dp[now] + 1;
        anc[nxt][0] = now;
        dfs(nxt, now);
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
int main()
{
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tr[u].emplace_back(v), tr[v].emplace_back(u);
    }
    dp[root] = 1, dfs(root, 0);
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}