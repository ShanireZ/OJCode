#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 1400000
int a[MX], ans[MX], g[MX], t[MX * 10];
struct Node
{
    int l, r, ver, id;
};
Node ns[MX];
struct Edit
{
    int p, v, pre;
};
Edit es[MX];
bool cmp(Node x, Node y)
{
    if (g[x.l] == g[y.l])
    {
        if (g[x.r] == g[y.r])
        {
            return x.ver < y.ver;
        }
        return x.r < y.r;
    }
    return x.l < y.l;
}
bool add(int x)
{
    t[x]++;
    return (t[x] == 1);
}
bool del(int x)
{
    t[x]--;
    return (t[x] == 0);
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
int main()
{
    int n = read(), m = read();
    int sz = pow(n, 2.0 / 3.0), npos = 0, epos = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        char opt = getchar();
        while (opt != 'Q' && opt != 'R')
        {
            opt = getchar();
        }
        int x = read(), y = read();
        if (opt == 'Q')
        {
            ns[++npos] = Node{x, y, epos, npos};
        }
        else
        {
            es[++epos] = Edit{x, y, a[x]};
            a[x] = y;
        }
    }
    sort(ns + 1, ns + npos + 1, cmp);
    int st = 1, ed = 0, res = 0;
    for (int i = 1; i <= npos; i++)
    {
        while (epos < ns[i].ver)
        {
            epos++;
            if (es[epos].p >= st && es[epos].p <= ed)
            {
                res -= del(es[epos].pre);
                res += add(es[epos].v);
            }
            a[es[epos].p] = es[epos].v;
        }
        while (epos > ns[i].ver)
        {
            if (es[epos].p >= st && es[epos].p <= ed)
            {
                res -= del(es[epos].v);
                res += add(es[epos].pre);
            }
            a[es[epos].p] = es[epos].pre;
            epos--;
        }
        while (ed < ns[i].r)
        {
            ed++;
            res += add(a[ed]);
        }
        while (ed > ns[i].r)
        {
            res -= del(a[ed]);
            ed--;
        }
        while (st < ns[i].l)
        {
            res -= del(a[st]);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            res += add(a[st]);
        }
        ans[ns[i].id] = res;
    }
    for (int i = 1; i <= npos; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}