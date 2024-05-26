#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
#define mid (l + r) / 2
struct Node
{
    long long lc, rc, v, tag;
};
Node ns[MX * 4];
long long n, m, root, pos, a[MX];
void maketree(long long &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag)
    {
        ns[ns[now].lc].v += (mid - l + 1) * ns[now].tag;
        ns[ns[now].rc].v += (r - mid) * ns[now].tag;
        ns[ns[now].lc].tag += ns[now].tag;
        ns[ns[now].rc].tag += ns[now].tag;
        ns[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        ns[now].v += (r - l + 1) * k;
        ns[now].tag += k;
        return;
    }
    pushdown(now, l, r);
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
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
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    maketree(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        long long opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            cin >> k;
            edit(root, 1, n, x, y, k);
        }
        else
        {
            cout << query(root, 1, n, x, y) << endl;
        }
    }
    return 0;
}