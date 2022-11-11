#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;
struct Node
{
    int lc, rc, v;
};
Node ns[1200005];
struct Area
{
    int l, r, k, id;
    bool operator<(const Area oth) const
    {
        return r < oth.r;
    }
};
Area as[50005];
int a[300005], ls[300005], ans[50005], cnt, n, m, root;
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
}
void edit(int now, int l, int r, int p, int ex)
{
    if (l == r)
    {
        ns[now].v += ex;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid)
    {
        edit(ns[now].lc, l, mid, p, ex);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, p, ex);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int now, int l, int r, int ex)
{
    if (l == r)
    {
        return ls[l];
    }
    int mid = (l + r) / 2;
    if (ex <= ns[ns[now].lc].v)
    {
        return query(ns[now].lc, l, mid, ex);
    }
    else
    {
        return query(ns[now].rc, mid + 1, r, ex - ns[ns[now].lc].v);
    }
}
int read();
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        ls[i] = a[i];
    }
    sort(ls + 1, ls + 1 + n);
    int sz = unique(ls + 1, ls + 1 + n) - (ls + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + 1 + sz, a[i]) - ls;
    }
    for (int i = 1; i <= m; i++)
    {
        as[i].l = read(), as[i].r = read(), as[i].k = read(), as[i].id = i;
    }
    sort(as + 1, as + 1 + m);
    init(root, 1, sz);
    int nl = as[1].l, nr = as[1].l - 1;
    for (int i = 1; i <= m; i++)
    {
        while (nl < as[i].l)
        {
            edit(root, 1, sz, a[nl], -1);
            nl++;
        }
        while (nr < as[i].r)
        {
            nr++;
            edit(root, 1, sz, a[nr], 1);
        }
        ans[as[i].id] = query(root, 1, sz, as[i].k);
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
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