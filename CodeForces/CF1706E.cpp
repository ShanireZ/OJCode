#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 200005
int npos, g[MX], w[MX], dp[MX], anc[MX][20], st[MX][20];
vector<int> to[MX];
int dfn(int x)
{
    return (g[x] == x ? x : g[x] = dfn(g[x]));
}
void dfs(int now)
{
    for (int i = 1; i <= 17; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        dp[nxt] = dp[now] + 1, dfs(nxt);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int i = 17; i >= 0; i--)
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
    for (int i = 17; i >= 0; i--)
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++)
        {
            g[i] = i, w[i] = 0, to[i].clear();
        }
        npos = n;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            a = dfn(a), b = dfn(b);
            if (a != b)
            {
                ++npos;
                to[npos].clear(), to[npos].push_back(a), to[npos].push_back(b);
                g[npos] = g[a] = g[b] = npos, w[npos] = i, anc[a][0] = anc[b][0] = npos;
            }
        }
        dp[npos] = 1, dfs(npos);
        for (int i = 1; i < n; i++)
        {
            st[i][0] = w[lca(i, i + 1)];
        }
        for (int j = 1; j <= 17; j++)
        {
            for (int i = 1; i < n; i++)
            {
                int len = (1 << (j - 1));
                st[i][j] = max(st[i][j - 1], st[i + len][j - 1]);
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            if (l == r)
            {
                cout << "0 ";
            }
            else
            {
                r--;
                int ex = log2(r - l + 1);
                int len = (1 << ex);
                cout << max(st[l][ex], st[r - len + 1][ex]) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// TAG: Kruskal重构树 LCA ST表 区间查询