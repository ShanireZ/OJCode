#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
Edge es[100005];
int vis[100005], g[100005], n, k;
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].w;
    }
    sort(es + 1, es + n);
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        int gx = dfn(es[i].u), gy = dfn(es[i].v);
        if (vis[gx] && vis[gy])
        {
            ans += es[i].w;
        }
        else
        {
            g[gx] = gy, vis[gy] |= vis[gx];
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 并查集 贪心