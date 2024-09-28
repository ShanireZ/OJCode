#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int res, lv, rv, lres, rres, lc, rc;
};
Node ns[800005];
int n, pos, q, root;
void update(int now, int l, int r)
{
    ns[now].lv = ns[ns[now].lc].lv, ns[now].rv = ns[ns[now].rc].rv;
    ns[now].res = max(ns[ns[now].lc].res, ns[ns[now].rc].res);
    ns[now].lres = ns[ns[now].lc].lres, ns[now].rres = ns[ns[now].rc].rres;
    if (ns[ns[now].lc].rv != ns[ns[now].rc].lv)
    {
        ns[now].res = max(ns[now].res, ns[ns[now].lc].rres + ns[ns[now].rc].lres);
        int mid = (l + r) >> 1;
        if (ns[now].lres == mid - l + 1)
        {
            ns[now].lres += ns[ns[now].rc].lres;
        }
        if (ns[now].rres == r - mid)
        {
            ns[now].rres += ns[ns[now].lc].rres;
        }
    }
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].res = ns[now].lres = ns[now].rres = 1;
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
    update(now, l, r);
}
void edit(int now, int l, int r, int x)
{
    if (l == r)
    {
        ns[now].lv = 1 - ns[now].rv;
        ns[now].rv = ns[now].lv;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x);
    }
    update(now, l, r);
}
int main()
{
    cin >> n >> q;
    init(root, 1, n); // L:0  R:1
    while (q--)
    {
        int x;
        cin >> x;
        edit(root, 1, n, x);
        cout << ns[root].res << '\n';
    }
    return 0;
}
// TAG: 区间合并线段树