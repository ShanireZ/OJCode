#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
vector<int> to[MX];
int n, m, h[MX], anc[MX][20];
void dfs(int now, int from)
{
    h[now] = h[from] + 1;
    anc[now][0] = from;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
    }
}
int lca(int x, int y)
{
    if (h[x] < h[y])
    {
        swap(x, y);
    }
    for (int i = 18; i >= 0; i--)
    {
        if (h[anc[x][i]] >= h[y])
        {
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = 18; i >= 0; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}
int dis(int x, int y)
{
    return h[x] + h[y] - 2 * h[lca(x, y)];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    for (int j = 1; j <= 18; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x = lca(a, b), y = lca(b, c), z = lca(a, c);
        x = x ^ y ^ z;
        cout << x << " " << dis(a, x) + dis(b, x) + dis(c, x) << "\n";
    }
    return 0;
}