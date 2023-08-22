#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
Edge es[20005];
int g[1005];
int dfn(int x)
{
    return (x == g[x] ? x : g[x] = dfn(g[x]));
}
int main()
{
    int n, m, ans = 0, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w;
    }
    sort(es + 1, es + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u = dfn(es[i].u), v = dfn(es[i].v);
        if (u != v)
        {
            g[u] = v, ans += es[i].w, cnt++;
        }
    }
    if (cnt != n - 1)
    {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}
// TAG: Kruskal 生成树