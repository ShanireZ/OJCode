#include <cstdio>
#include <algorithm>
using namespace std;
int read();
struct Node
{
    int v, fa, lc, rc, dis;
};
Node ns[100005];
int n, m;
int dfn(int x)
{
    return (ns[x].fa == x) ? x : ns[x].fa = dfn(ns[x].fa);
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
    ns[ns[x].rc].fa = x;
    if (ns[ns[x].lc].dis < ns[ns[x].rc].dis)
    {
        swap(ns[x].lc, ns[x].rc);
    }
    ns[x].dis = ns[ns[x].rc].dis + 1;
    return x;
}
void pop(int x)
{
    ns[ns[x].lc].fa = ns[x].lc;
    ns[ns[x].rc].fa = ns[x].rc;
    ns[x].v = ns[x].dis = -1;
    ns[x].fa = merge(ns[x].lc, ns[x].rc);
}
int main()
{
    n = read(), m = read();
    ns[0].dis = -1;
    for (int i = 1; i <= n; i++)
    {
        ns[i].v = read();
        ns[i].fa = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int t = read();
        if (t == 1) // merge
        {
            int x = read(), y = read();
            int gx = dfn(x), gy = dfn(y);
            if (ns[x].v == -1 || ns[y].v == -1 || gx == gy)
            {
                continue;
            }
            ns[gx].fa = ns[gy].fa = merge(dfn(x), dfn(y));
        }
        else //del & query
        {
            int x = read();
            if (ns[x].v == -1)
            {
                printf("-1\n");
            }
            else
            {
                x = dfn(x);
                printf("%d\n", ns[x].v);
                pop(x);
            }
        }
    }
    return 0;
}
int read()
{
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    int t = 1, ans = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}