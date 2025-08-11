#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long lc, rc, v, t1, t2; //! t1推平 t2修改
};
Node ns[2000005];
long long n, q, root, pos, a[1000005];
void maketree(long long &now, int l, int r)
{
    now = ++pos;
    ns[now].t1 = 1e18;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void pushdown(int now, int l, int r)
{
    if (ns[now].t1 != 1e18)
    {
        ns[ns[now].lc].t1 = ns[ns[now].lc].v = ns[now].t1;
        ns[ns[now].rc].t1 = ns[ns[now].rc].v = ns[now].t1;
        ns[ns[now].lc].t2 = ns[ns[now].rc].t2 = 0;
        ns[now].t1 = 1e18;
    }
    else if (ns[now].t2 != 0)
    {
        if (ns[ns[now].lc].t1 != 1e18)
        {
            ns[ns[now].lc].t1 += ns[now].t2;
        }
        else
        {
            ns[ns[now].lc].t2 += ns[now].t2;
        }
        ns[ns[now].lc].v += ns[now].t2;
        if (ns[ns[now].rc].t1 != 1e18)
        {
            ns[ns[now].rc].t1 += ns[now].t2;
        }
        else
        {
            ns[ns[now].rc].t2 += ns[now].t2;
        }
        ns[ns[now].rc].v += ns[now].t2;
        ns[now].t2 = 0;
    }
}
void edit1(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        ns[now].v = ns[now].t1 = k;
        ns[now].t2 = 0;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(now, l, r);
    if (x <= mid)
    {
        edit1(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit1(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void edit2(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        ns[now].v += k;
        if (ns[now].t1 != 1e18)
        {
            ns[now].t1 += k;
        }
        else
        {
            ns[now].t2 += k;
        }
        return;
    }
    int mid = (l + r) / 2;
    pushdown(now, l, r);
    if (x <= mid)
    {
        edit2(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit2(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    long long res = -1e18;
    if (x <= mid)
    {
        res = max(res, query(ns[now].lc, l, mid, x, y));
    }
    if (y > mid)
    {
        res = max(res, query(ns[now].rc, mid + 1, r, x, y));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    maketree(root, 1, n);
    for (int i = 1; i <= q; i++)
    {
        long long opt, l, r, x;
        cin >> opt >> l >> r;
        if (opt == 1)
        {
            cin >> x;
            edit1(root, 1, n, l, r, x);
        }
        else if (opt == 2)
        {
            cin >> x;
            edit2(root, 1, n, l, r, x);
        }
        else
        {
            cout << query(root, 1, n, l, r) << "\n";
        }
    }
    return 0;
}