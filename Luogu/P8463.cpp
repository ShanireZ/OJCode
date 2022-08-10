#include <algorithm>
#include <cstdio>
using namespace std;
int mod = 998244353, ans, pos, npos, root, n, m;
struct Seg
{
    int l, r, h, cnt;
    bool operator<(const Seg oth) const
    {
        return h < oth.h;
    }
};
Seg seg[500005];
struct Node
{
    int lc, rc, v, tag;
};
Node ns[400005];
void update(int now)
{
    ns[now].v = (ns[ns[now].lc].v == ns[ns[now].rc].v) ? ns[ns[now].lc].v : 0;
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = 1;
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
    update(now);
}
void pushdown(int now)
{
    if (ns[now].tag == 0)
    {
        return;
    }
    ns[ns[now].lc].v = ns[ns[now].lc].tag = ns[ns[now].rc].v = ns[ns[now].rc].tag = ns[now].tag;
    ns[now].tag = 0;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].v = ns[now].tag = k;
        return;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    update(now);
}
int query(int now, int l, int r, int x)
{
    if (x >= l && x <= r && ns[now].v)
    {
        return ns[now].v;
    }
    pushdown(now);
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
    {
        ans = query(ns[now].lc, l, mid, x);
    }
    else
    {
        ans = query(ns[now].rc, mid + 1, r, x);
    }
    update(now);
    return ans;
}
void init()
{
    sort(seg + 1, seg + 1 + m);
    init(root, 1, 100000);
    for (int i = 1; i <= m; i++)
    {
        int l = seg[i].l, r = seg[i].r;
        int now = (query(root, 1, 100000, l) + query(root, 1, 100000, r)) % mod;
        edit(root, 1, 100000, l, r, now);
    }
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        seg[i].l = read(), seg[i].r = read(), seg[i].h = read();
    }
    init();
    for (int i = 1; i <= n; i++)
    {
        pos = read();
        ans = (ans + query(root, 1, 100000, pos)) % mod;
    }
    printf("%d\n", ans);
    return 0;
}