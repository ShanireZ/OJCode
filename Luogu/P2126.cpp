#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &oth) const
    {
        return w < oth.w;
    }
};
Edge es[400005];
int n, m, ans, g[2500];
int find(int x)
{
    return (g[x] != x ? g[x] = find(g[x]) : x);
}
int main()
{
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
        int u = find(es[i].u), v = find(es[i].v);
        if (u != v)
        {
            ans += es[i].w;
            g[u] = v;
        }
    }
    cout << ans << endl;
    return 0;
}