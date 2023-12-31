#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long v, maxv;
    int lc, rc;
};
Node ns[400005];
int n, m, pos, root, a[100005];
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = ns[now].maxv = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].maxv = max(ns[ns[now].lc].maxv, ns[ns[now].rc].maxv);
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2;
    long long ans = 0;
    if (x <= mid)
    {
        ans += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += query(ns[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
void edit(int now, int l, int r, int x, long long k)
{
    if (l == r)
    {
        ns[now].v = ns[now].maxv = k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, k);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x, k);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].maxv = max(ns[ns[now].lc].maxv, ns[ns[now].rc].maxv);
}
void mod(int now, int l, int r, int x, int y, long long k)
{
    if (ns[now].maxv < k)
    {
        return;
    }
    if (l == r)
    {
        ns[now].v = ns[now].maxv = ns[now].v % k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        mod(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        mod(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].maxv = max(ns[ns[now].lc].maxv, ns[ns[now].rc].maxv);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        long long op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cout << query(root, 1, n, l, r) << endl;
        }
        else if (op == 2)
        {
            cin >> x;
            mod(root, 1, n, l, r, x);
        }
        else
        {
            edit(root, 1, n, l, r);
        }
    }
    return 0;
}
// TAG: 线段树 取余