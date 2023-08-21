#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 200005
vector<int> to[MX];
int npos, w[MX], g[MX], sz[MX], anc[MX][20];
int dfn(int x)
{
    return (x == g[x] ? x : g[x] = dfn(g[x]));
}
void dfs(int now)
{
    for (int i = 1; i <= 17; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        dfs(nxt);
        sz[now] += sz[nxt];
    }
}
int query(int x, int y, int lim)
{
    for (int i = 17; i >= 0; i--)
    {
        x = (w[anc[x][i]] > lim ? x : anc[x][i]);
        y = (w[anc[y][i]] > lim ? y : anc[y][i]);
    }
    return sz[x] + sz[y] * (x != y);
}
int main()
{
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i, sz[i] = 1;
    }
    npos = n, w[0] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = dfn(a), b = dfn(b);
        if (a != b)
        {
            ++npos;
            g[a] = g[b] = g[npos] = npos, w[npos] = i, anc[a][0] = anc[b][0] = npos;
            to[npos].push_back(a), to[npos].push_back(b);
        }
    }
    dfs(npos);
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int l = 1, r = m;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (query(a, b, mid) < c)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
    return 0;
}
// TAG: kruskal重构树 二分