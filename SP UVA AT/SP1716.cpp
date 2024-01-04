#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc = 0, rc = 0;
    long long v = -1e9, lmax = -1e9, rmax = -1e9, maxv = -1e9;
};
Node ns[200005];
int n, m, root, pos, a[50005];
void update(Node a, Node b, Node &t)
{
    t.v = a.v + b.v;
    t.lmax = max(a.lmax, a.v + b.lmax), t.rmax = max(b.rmax, b.v + a.rmax);
    t.maxv = max(max(a.maxv, b.maxv), a.rmax + b.lmax);
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = ns[now].lmax = ns[now].rmax = ns[now].maxv = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    update(ns[ns[now].lc], ns[ns[now].rc], ns[now]);
}
Node query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now];
    }
    int mid = (l + r) / 2;
    Node ans1, ans2, ans;
    if (x <= mid)
    {
        ans1 = query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans2 = query(ns[now].rc, mid + 1, r, x, y);
    }
    update(ans1, ans2, ans);
    return ans;
}
void edit(int now, int l, int r, int p, int k)
{
    if (l == r)
    {
        ns[now].v = ns[now].lmax = ns[now].rmax = ns[now].maxv = k;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid)
    {
        edit(ns[now].lc, l, mid, p, k);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, p, k);
    }
    update(ns[ns[now].lc], ns[ns[now].rc], ns[now]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init(root, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cout << query(root, 1, n, l, r).maxv << endl;
        }
        else
        {
            edit(root, 1, n, l, r);
        }
    }
    return 0;
}
// TAG: 区间合并线段树 单点修改