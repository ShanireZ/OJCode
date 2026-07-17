#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int x, y, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
Edge es[50005];
vector<int> nes[20005];
int n, m, q, g[20005], val[20005], dp[20005], anc[20005][20];
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
void dfs(int now)
{
    for (int nxt : nes[now])
    {
        dp[nxt] = dp[now] + 1;
        dfs(nxt);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int j = 14; j >= 0; j--)
    {
        if (dp[anc[x][j]] >= dp[y])
        {
            x = anc[x][j];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int j = 14; j >= 0; j--)
    {
        if (anc[x][j] != anc[y][j])
        {
            x = anc[x][j], y = anc[y][j];
        }
    }
    return anc[x][0];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].x >> es[i].y >> es[i].w;
    }
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x = es[i].x, y = es[i].y, z = es[i].w;
        int gx = dfn(x), gy = dfn(y);
        if (gx != gy)
        {
            val[++n] = z;
            g[gx] = g[gy] = g[n] = n;
            nes[n].push_back(gx), nes[n].push_back(gy);
            anc[gx][0] = anc[gy][0] = n;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
        {
            dp[i] = 1, dfs(i);
        }
    }
    for (int j = 1; j <= 14; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int gx = dfn(x), gy = dfn(y);
        cout << (gx != gy ? -1 : val[lca(x, y)]) << endl;
    }
    return 0;
}