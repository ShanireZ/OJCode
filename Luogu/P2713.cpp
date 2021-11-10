#include <cstdio>
#include <algorithm>
using namespace std;
struct Node
{
    int v, lc, rc, fa, dis;
};
Node ns[1000005];
int n, m;
int read();
void write(int x);
int merge(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return x + y;
    }
    if (ns[x].v > ns[y].v)
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
void del(int x)
{
    ns[ns[x].lc].fa = ns[x].lc;
    ns[ns[x].rc].fa = ns[x].rc;
    ns[x].fa = merge(ns[x].lc, ns[x].rc);
    ns[x].v = ns[x].dis = -1;
}
int dfn(int x)
{
    if (x != ns[x].fa)
    {
        ns[x].fa = dfn(ns[x].fa);
    }
    return ns[x].fa;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].v = read();
        ns[i].fa = i;
    }
    ns[0].dis = -1;
    m = read();
    for (int i = 1; i <= m; i++)
    {
        char op = getchar();
        while (op != 'M' && op != 'K')
        {
            op = getchar();
        }
        if (op == 'M')
        {
            int x = read(), y = read();
            int gx = dfn(x), gy = dfn(y);
            if (ns[x].v == -1 || ns[y].v == -1 || gx == gy)
            {
                continue;
            }
            ns[gx].fa = ns[gy].fa = merge(gx, gy);
        }
        else
        {
            int x = read(), ans = 0;
            int gx = dfn(x);
            if (ns[x].v != -1)
            {
                ans = ns[gx].v;
                del(gx);
            }
            write(ans);
            putchar('\n');
        }
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
void write(int x)
{
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}