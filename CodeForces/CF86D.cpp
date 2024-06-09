#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, id;
};
Node ns[200005];
int a[200005], g[200005];
long long ans[200005], t[1000005], res;
bool cmp(Node a, Node b)
{
    if (g[a.l] == g[b.l])
    {
        return a.r < b.r;
    }
    return a.l < b.l;
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
    int n = read(), q = read();
    int sz = sqrt(n), cnt = 0, gpos = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (cnt == sz)
        {
            cnt = 0, gpos++;
        }
        g[i] = gpos, cnt++;
    }
    for (int i = 1; i <= q; i++)
    {
        ns[i].l = read(), ns[i].r = read(), ns[i].id = i;
    }
    sort(ns + 1, ns + q + 1, cmp);
    int st = 1, ed = 0;
    for (int i = 1; i <= q; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            res += (t[a[ed]] * 2 + 1) * a[ed];
            t[a[ed]]++;
        }
        while (ed > ns[i].r)
        {
            res -= (t[a[ed]] * 2 - 1) * a[ed];
            t[a[ed]]--;
            ed--;
        }
        while (st < ns[i].l)
        {
            res -= (t[a[st]] * 2 - 1) * a[st];
            t[a[st]]--;
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            res += (t[a[st]] * 2 + 1) * a[st];
            t[a[st]]++;
        }
        ans[ns[i].id] = res;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}