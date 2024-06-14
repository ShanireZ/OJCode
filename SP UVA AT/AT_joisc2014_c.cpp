#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int l, r, id;
};
Node ns[MX];
long long a[MX], ls[MX], g[MX], ans[MX], t[MX];
bool cmp(Node x, Node y)
{
    return g[x.l] == g[y.l] ? x.r < y.r : x.l < y.l;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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
    int sz = max(1, int(n / sqrt(m)));
    for (int i = 1; i <= n; i++)
    {
        a[i] = ls[i] = read();
        g[i] = (i - 1) / sz + 1;
    }
    sort(ls + 1, ls + 1 + n);
    int len = unique(ls + 1, ls + 1 + n) - ls;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + len, a[i]) - ls;
    }
    for (int i = 1; i <= m; i++)
    {
        ns[i].l = read(), ns[i].r = read(), ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + m, cmp);
    int p = 1;
    while (p <= m)
    {
        long long res = 0;
        if (g[ns[p].l] == g[ns[p].r])
        {
            for (int i = ns[p].l; i <= ns[p].r; i++)
            {
                t[a[i]]++;
                res = max(res, t[a[i]] * ls[a[i]]);
            }
            ans[ns[p].id] = res;
            for (int i = ns[p].l; i <= ns[p].r; i++)
            {
                t[a[i]]--;
            }
            p++;
        }
        else
        {
            int st = g[ns[p].l] * sz + 1, ed = g[ns[p].l] * sz;
            do
            {
                while (ed < ns[p].r)
                {
                    ed++;
                    t[a[ed]]++;
                    res = max(res, t[a[ed]] * ls[a[ed]]);
                }
                long long now = res;
                while (st > ns[p].l)
                {
                    st--;
                    t[a[st]]++;
                    now = max(now, t[a[st]] * ls[a[st]]);
                }
                ans[ns[p].id] = now;
                while (st < g[ns[p].l] * sz + 1)
                {
                    t[a[st]]--;
                    st++;
                }
                p++;
            } while (p <= m && g[ns[p].l] == g[ns[p - 1].l]);
            for (int i = ns[p - 1].r; i > g[ns[p - 1].l] * sz; i--)
            {
                t[a[i]]--;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}