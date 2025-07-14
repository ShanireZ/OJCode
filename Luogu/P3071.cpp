#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, v, lv, rv, tag;
};
Node ns[1000005];
int n, m, root, pos, cnt;
void update(int now, int l, int r)
{
    int mid = (l + r) / 2;
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
    ns[now].v = max(ns[ns[now].lc].rv + ns[ns[now].rc].lv, ns[now].v);
    ns[now].lv = ns[ns[now].lc].lv, ns[now].rv = ns[ns[now].rc].rv;
    if (ns[ns[now].lc].lv == mid - l + 1)
    {
        ns[now].lv += ns[ns[now].rc].lv;
    }
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
    if (ns[now].tag == -1)
    {
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = -1;
        ns[ns[now].lc].v = ns[ns[now].lc].lv = ns[ns[now].lc].rv = mid - l + 1;
        ns[ns[now].rc].v = ns[ns[now].rc].lv = ns[ns[now].rc].rv = r - mid;
    }
    else if (ns[now].tag == 1)
    {
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = 1;
        ns[ns[now].lc].v = ns[ns[now].lc].lv = ns[ns[now].lc].rv = 0;
        ns[ns[now].rc].v = ns[ns[now].rc].lv = ns[ns[now].rc].rv = 0;
    }
    ns[now].tag = 0;
}
void cl(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        ns[now].tag = -1;
        ns[now].v = ns[now].lv = ns[now].rv = r - l + 1;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        cl(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        cl(ns[now].rc, mid + 1, r, x, y);
    }
    update(now, l, r);
}
void editsuf(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        ns[now].tag = 1;
        ns[now].v = ns[now].lv = ns[now].rv = 0;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        editsuf(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        editsuf(ns[now].rc, mid + 1, r, x, y);
    }
    update(now, l, r);
}
void edit(int now, int l, int r, int ex)
{
    if (r - l + 1 == ex && ns[now].lv == ex)
    {
        ns[now].tag = 1;
        ns[now].v = ns[now].lv = ns[now].rv = 0;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (ns[ns[now].lc].v >= ex)
    {
        edit(ns[now].lc, l, mid, ex);
    }
    else if (ns[ns[now].lc].rv && ns[ns[now].lc].rv + ns[ns[now].rc].lv >= ex)
    {
        int x = ns[ns[now].lc].rv;
        editsuf(ns[now].lc, l, mid, mid - x + 1, mid);
        edit(ns[now].rc, mid + 1, r, ex - x);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, ex);
    }
    update(now, l, r);
}
int main()
{
    cin >> n >> m;
    maketree(root, 1, n);
    while (m--)
    {
        char opt;
        int x, y;
        cin >> opt >> x;
        if (opt == 'A')
        {
            if (ns[root].v < x)
            {
                cnt++;
                continue;
            }
            edit(root, 1, n, x);
        }
        else
        {
            cin >> y;
            cl(root, 1, n, x, y);
        }
    }
    cout << cnt << endl;
    return 0;
}