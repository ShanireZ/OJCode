#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
    int v, lc, rc, dis, fa;
};
Node ns[100005];
int merge(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return x + y;
    }
    if (ns[x].v < ns[y].v)
    {
        swap(x, y);
    }
    ns[x].rc = merge(ns[x].rc, y);
    ns[ns[x].rc].fa = x;
    if (ns[ns[x].lc].dis < ns[ns[x].rc].dis)
    {
        swap(ns[x].lc, ns[x].rc);
    }
    ns[x].dis = ns[ns[x].rc].dis + 1;
    return x;
}
int dfn(int x)
{
    if (x != ns[x].fa)
    {
        ns[x].fa = dfn(ns[x].fa);
    }
    return ns[x].fa;
}
int fight(int x)//先将x删除修改完再并入 并查集与堆无关
{
    ns[x].v /= 2;
    int root = ns[ns[x].lc].fa = ns[ns[x].rc].fa = merge(ns[x].lc, ns[x].rc);
    ns[x].lc = ns[x].rc = ns[x].dis = 0;
    return merge(root, x);
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n)
    {
        memset(ns, 0, sizeof(ns));
        ns[0].dis = ns[0].v = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].v;
            ns[i].fa = i;
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int x, y, ans = -1;
            cin >> x >> y;
            int gx = dfn(x), gy = dfn(y);
            if (gx != gy)
            {
                int pos = merge(fight(gx), fight(gy));
                ans = ns[pos].v;
            }
            cout << ans << endl;
        }
    }
    return 0;
}