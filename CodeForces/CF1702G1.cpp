#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int anc[200005][20], dep[200005], a[200005], n, q, maxs;
vector<int> to[200005];
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
int lca(int x, int y)
{
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (int i = maxs; i >= 0; i--)
    {
        if (dep[anc[x][i]] >= dep[y])
        {
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = maxs; i >= 0; i--)
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
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    dep[1] = 1, maxs = log2(n), dfs(1);
    cin >> q;
    while (q--)
    {
        int k, p1 = 0, p2 = 0, ok = 1;
        cin >> k;
        for (int i = 1; i <= k; i++) //  找到深度最大的点p1
        {
            cin >> a[i];
            if (dep[p1] < dep[a[i]])
            {
                p1 = a[i];
            }
        }
        for (int i = 1; i <= k; i++) //  找到深度次大的点p2,且p2不是p1的祖先
        {
            if (lca(a[i], p1) != a[i] && dep[p2] < dep[a[i]])
            {
                p2 = a[i];
            }
        }
        if (p2 == 0) // 链状
        {
            cout << "YES\n";
            continue;
        }
        int l = lca(p1, p2);
        for (int i = 1; i <= k; i++) // 检查p1到p2路径是否包含每个点
        {
            int l1 = lca(a[i], p1), l2 = lca(a[i], p2);
            if (dep[l1] < dep[l] || dep[l2] < dep[l] || (l1 != a[i] && l2 != a[i])) // a[i]与p1或p2的lca等于a[i] 且 高度不能超过lca(p1,p2)
            {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}