#include <algorithm>
#include <iostream>
using namespace std;
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
    int lc, rc, v1, v0, max1, lmax1, rmax1, max0, lmax0, rmax0, rvs, tag = -1;
};
Node ns[400005];
int a[100005], lx[100005], npos, pos, root, n, m;
void update(int now)
{
    ns[now].v1 = ns[LC].v1 + ns[RC].v1, ns[now].v0 = ns[LC].v0 + ns[RC].v0;
    ns[now].max1 = max(ns[LC].max1, ns[RC].max1);
    ns[now].max1 = max(ns[now].max1, ns[LC].rmax1 + ns[RC].lmax1);
    ns[now].max0 = max(ns[LC].max0, ns[RC].max0);
    ns[now].max0 = max(ns[now].max0, ns[LC].rmax0 + ns[RC].lmax0);
    ns[now].lmax1 = ns[LC].lmax1 + ns[RC].lmax1 * (ns[LC].v0 == 0);
    ns[now].rmax1 = ns[RC].rmax1 + ns[LC].rmax1 * (ns[RC].v0 == 0);
    ns[now].lmax0 = ns[LC].lmax0 + ns[RC].lmax0 * (ns[LC].v1 == 0);
    ns[now].rmax0 = ns[RC].rmax0 + ns[LC].rmax0 * (ns[RC].v1 == 0);
}
void init(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        if (a[l] == 1)
        {
            ns[now].v1 = ns[now].lmax1 = ns[now].rmax1 = ns[now].max1 = 1;
        }
        else
        {
            ns[now].v0 = ns[now].lmax0 = ns[now].rmax0 = ns[now].max0 = 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    init(LC, l, mid), init(RC, mid + 1, r);
    update(now);
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag != -1)
    {
        int mid = (l + r) / 2;
        ns[LC].tag = ns[RC].tag = ns[now].tag, ns[LC].rvs = ns[RC].rvs = 0;
        if (ns[now].tag == 0)
        {
            ns[LC].v1 = ns[LC].lmax1 = ns[LC].rmax1 = ns[LC].max1 = 0;
            ns[LC].v0 = ns[LC].lmax0 = ns[LC].rmax0 = ns[LC].max0 = mid - l + 1;
            ns[RC].v1 = ns[RC].lmax1 = ns[RC].rmax1 = ns[RC].max1 = 0;
            ns[RC].v0 = ns[RC].lmax0 = ns[RC].rmax0 = ns[RC].max0 = r - mid;
        }
        else
        {
            ns[LC].v1 = ns[LC].lmax1 = ns[LC].rmax1 = ns[LC].max1 = mid - l + 1;
            ns[LC].v0 = ns[LC].lmax0 = ns[LC].rmax0 = ns[LC].max0 = 0;
            ns[RC].v1 = ns[RC].lmax1 = ns[RC].rmax1 = ns[RC].max1 = r - mid;
            ns[RC].v0 = ns[RC].lmax0 = ns[RC].rmax0 = ns[RC].max0 = 0;
        }
        ns[now].tag = -1;
    }
    if (ns[now].rvs)
    {
        swap(ns[LC].v1, ns[LC].v0), swap(ns[LC].max1, ns[LC].max0);
        swap(ns[LC].lmax1, ns[LC].lmax0), swap(ns[LC].rmax1, ns[LC].rmax0);
        swap(ns[RC].v1, ns[RC].v0), swap(ns[RC].max1, ns[RC].max0);
        swap(ns[RC].lmax1, ns[RC].lmax0), swap(ns[RC].rmax1, ns[RC].rmax0);
        if (ns[LC].tag != -1)
        {
            ns[LC].tag ^= 1;
        }
        else
        {
            ns[LC].rvs ^= 1;
        }
        if (ns[RC].tag != -1)
        {
            ns[RC].tag ^= 1;
        }
        else
        {
            ns[RC].rvs ^= 1;
        }
        ns[now].rvs = 0;
    }
}
void edit(int now, int l, int r, int x, int y, int opt)
{
    if (x <= l && y >= r)
    {
        if (opt == 0)
        {
            ns[now].v1 = ns[now].lmax1 = ns[now].rmax1 = ns[now].max1 = 0;
            ns[now].v0 = ns[now].lmax0 = ns[now].rmax0 = ns[now].max0 = r - l + 1;
            ns[now].tag = 0, ns[now].rvs = 0;
        }
        else if (opt == 1)
        {
            ns[now].v1 = ns[now].lmax1 = ns[now].rmax1 = ns[now].max1 = r - l + 1;
            ns[now].v0 = ns[now].lmax0 = ns[now].rmax0 = ns[now].max0 = 0;
            ns[now].tag = 1, ns[now].rvs = 0;
        }
        else
        {
            swap(ns[now].v1, ns[now].v0), swap(ns[now].max1, ns[now].max0);
            swap(ns[now].lmax1, ns[now].lmax0), swap(ns[now].rmax1, ns[now].rmax0);
            if (ns[now].tag != -1)
            {
                ns[now].tag ^= 1;
            }
            else
            {
                ns[now].rvs ^= 1;
            }
        }
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, opt);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, opt);
    }
    update(now);
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v1;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
    {
        ans += query(LC, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += query(RC, mid + 1, r, x, y);
    }
    return ans;
}
void queryL(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        lx[++pos] = now;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        queryL(LC, l, mid, x, y);
    }
    if (y > mid)
    {
        queryL(RC, mid + 1, r, x, y);
    }
}
int findAns()
{
    int ans = 0, pre = 0;
    for (int i = 1; i <= pos; i++)
    {
        int now = lx[i];
        ans = max(ans, ns[now].max1);
        ans = max(ans, pre + ns[now].lmax1);
        if (ns[now].v0 == 0)
        {
            pre += ns[now].rmax1;
        }
        else
        {
            pre = ns[now].rmax1;
        }
        ans = max(ans, pre);
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
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        x++, y++;
        if (opt == 0) // 变0
        {
            edit(root, 1, n, x, y, 0);
        }
        else if (opt == 1) // 变1
        {
            edit(root, 1, n, x, y, 1);
        }
        else if (opt == 2) // 取反
        {
            edit(root, 1, n, x, y, 2);
        }
        else if (opt == 3) // 查v
        {
            cout << query(root, 1, n, x, y) << endl;
        }
        else // 查maxv
        {
            pos = 0;
            queryL(root, 1, n, x, y);
            cout << findAns() << endl;
        }
    }
    return 0;
}
// TAG: 线段树 区间合并 连续子区间