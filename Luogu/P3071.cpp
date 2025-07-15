#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, v, lv, rv, tag;
};
Node ns[1000005];
int root, pos, n, m, ans;
void update(int now, int l, int r)
{
    int mid = (l + r) / 2;
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
    ns[now].v = max(ns[now].v, ns[ns[now].lc].rv + ns[ns[now].rc].lv);
    ns[now].lv = ns[ns[now].lc].lv;
    if (ns[ns[now].lc].lv == mid - l + 1)
    {
        ns[now].lv += ns[ns[now].rc].lv;
    }
    ns[now].rv = ns[ns[now].rc].rv;
    if (ns[ns[now].rc].rv == r - mid)
    {
        ns[now].rv += ns[ns[now].lc].rv;
    }
}
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = ns[now].lv = ns[now].rv = 1;
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
    update(now, l, r);
}
void pushdown(int now, int l, int r)
{
    int mid = (l + r) / 2;
    if (ns[now].tag == 1)
    {
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = 1;
        ns[ns[now].lc].v = ns[ns[now].lc].lv = ns[ns[now].lc].rv = 0;
        ns[ns[now].rc].v = ns[ns[now].rc].lv = ns[ns[now].rc].rv = 0;
    }
    else if (ns[now].tag == -1)
    {
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = -1;
        ns[ns[now].lc].v = ns[ns[now].lc].lv = ns[ns[now].lc].rv = mid - l + 1;
        ns[ns[now].rc].v = ns[ns[now].rc].lv = ns[ns[now].rc].rv = r - mid;
    }
    ns[now].tag = 0;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].tag = k;
        if (k == 1)
        {
            ns[now].v = ns[now].lv = ns[now].rv = 0;
        }
        else
        {
            ns[now].v = ns[now].lv = ns[now].rv = r - l + 1;
        }
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    update(now, l, r);
}
int query(int now, int l, int r, int x)
{
    if (ns[now].lv >= x)
    {
        return l;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (ns[ns[now].lc].v >= x)
    {
        return query(ns[now].lc, l, mid, x);
    }
    else if (ns[ns[now].lc].rv + ns[ns[now].rc].lv >= x)
    {
        return mid - ns[ns[now].lc].rv + 1;
    }
    else
    {
        return query(ns[now].rc, mid + 1, r, x);
    }
}
int main()
{
    cin >> n >> m;
    maketree(root, 1, n);
    while (m--)
    {
        char opt;
        int a, b;
        cin >> opt >> a;
        if (opt == 'A')
        {
            if (ns[root].v < a)
            {
                ans++;
                continue;
            }
            int p = query(root, 1, n, a);
            edit(root, 1, n, p, p + a - 1, 1);
        }
        else
        {
            cin >> b;
            edit(root, 1, n, a, b, -1);
        }
    }
    cout << ans << endl;
    return 0;
}