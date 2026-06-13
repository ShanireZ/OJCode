#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 300005
vector<int> to[MX];
int n, a[MX], h[MX], t[MX], anc[MX][20];
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
void dfs2(int now, int from)
{
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs2(nxt, now);
    }
    t[from] += t[now];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
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
    for (int i = 1; i < n; i++)
    {
        int p = lca(a[i], a[i + 1]);
        t[a[i]]++, t[a[i + 1]]++;
        t[p]--, t[anc[p][0]]--;
    }
    dfs2(1, 0);
    t[a[1]]++;
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] - 1 << '\n';
    }
    return 0;
}