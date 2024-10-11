#include <algorithm>
#include <iostream>
using namespace std;
#define MX 10000000
int a[100005], prim[MX + 5], vis[MX + 5], n, m, ppos, npos, root;
struct Node
{
    int lc, rc, v, sum, tag;
};
Node ns[200005];
void init(int &now, int l, int r)
{
    now = ++npos;
    ns[now].tag = -1;
    if (l == r)
    {
        ns[now].v = a[l];
        ns[now].sum = (a[l] <= MX && !vis[a[l]]);
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    ns[now].sum = ns[ns[now].lc].sum + ns[ns[now].rc].sum;
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag != -1)
    {
        int mid = (l + r) >> 1;
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = ns[now].tag;
        ns[ns[now].lc].v = ns[ns[now].rc].v = ns[now].tag;
        ns[ns[now].lc].sum = (ns[now].tag <= MX && !vis[ns[now].tag]) * (mid - l + 1);
        ns[ns[now].rc].sum = (ns[now].tag <= MX && !vis[ns[now].tag]) * (r - mid);
        ns[now].tag = -1;
    }
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].tag = ns[now].v = k;
        ns[now].sum = (k <= MX && !vis[k]) * (r - l + 1);
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].sum = ns[ns[now].lc].sum + ns[ns[now].rc].sum;
}
void edit2(int now, int l, int r, int x, int k)
{
    if (l == r)
    {
        ns[now].v += k;
        ns[now].sum = (ns[now].v <= MX && !vis[ns[now].v]);
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit2(ns[now].lc, l, mid, x, k);
    }
    else
    {
        edit2(ns[now].rc, mid + 1, r, x, k);
    }
    ns[now].sum = ns[ns[now].lc].sum + ns[ns[now].rc].sum;
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].sum;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid)
    {
        res += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        res += query(ns[now].rc, mid + 1, r, x, y);
    }
    return res;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= MX; i++)
    {
        if (vis[i] == 0)
        {
            prim[++ppos] = i;
        }
        for (int j = 1; j <= ppos && prim[j] * i <= MX; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init(root, 1, n);
    while (m--)
    {
        char opt;
        int a, b, c;
        cin >> opt >> a >> b;
        if (opt == 'A')
        {
            edit2(root, 1, n, b, a);
        }
        else if (opt == 'R')
        {
            cin >> c;
            edit(root, 1, n, b, c, a);
        }
        else
        {
            cout << query(root, 1, n, a, b) << '\n';
        }
    }
    return 0;
}