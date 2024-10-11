#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, dis, lc, rc;
};
Node ns[100005];
int g[100005], n, m;
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
int merge(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return x + y;
    }
    if (ns[x].v > ns[y].v || (ns[x].v == ns[y].v && x > y))
    {
        swap(x, y);
    }
    ns[x].rc = merge(ns[x].rc, y);
    g[ns[x].rc] = x;
    ns[x].dis = ns[ns[x].rc].dis + 1;
    if (ns[ns[x].lc].dis < ns[ns[x].rc].dis)
    {
        swap(ns[x].lc, ns[x].rc);
    }
    return x;
}
void del(int x)
{
    ns[x].v = -1;
    g[ns[x].lc] = ns[x].lc, g[ns[x].rc] = ns[x].rc;
    g[x] = merge(ns[x].lc, ns[x].rc);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        cin >> opt >> x;
        if (opt == 1)
        {
            cin >> y;
            int gx = dfn(x), gy = dfn(y);
            if (gx == gy || ns[x].v == -1 || ns[y].v == -1)
            {
                continue;
            }
            merge(gx, gy);
        }
        else
        {
            if (ns[x].v == -1)
            {
                cout << -1 << '\n';
                continue;
            }
            int gx = dfn(x);
            cout << ns[gx].v << '\n';
            del(gx);
        }
    }
    return 0;
}