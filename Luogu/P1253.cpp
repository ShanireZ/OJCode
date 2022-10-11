#include <iostream>
using namespace std;
#define MX 1000005
#define MAX 1e18 + 5
struct Node
{
    int lc, rc;
    long long v, tag1, tag2;
};
Node ns[MX * 4];
int n, q, pos, root;
long long a[MX];
long long read()
{
    long long ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}
void update(int now)
{
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void init(int l, int r, int &now)
{
    now = ++pos;
    ns[now].tag1 = MAX;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(l, mid, ns[now].lc);
    init(mid + 1, r, ns[now].rc);
    update(now);
}
void pushdown(int l, int r, int now)
{
    int lc = ns[now].lc, rc = ns[now].rc;
    if (ns[now].tag1 != MAX)
    {
        ns[lc].tag1 = ns[rc].tag1 = ns[lc].v = ns[rc].v = ns[now].tag1;
        ns[lc].tag2 = ns[rc].tag2 = 0;
        ns[now].tag1 = MAX;
    }
    else
    {
        ns[lc].v += ns[now].tag2, ns[rc].v += ns[now].tag2;
        (ns[lc].tag1 != MAX) ? (ns[lc].tag1 += ns[now].tag2) : (ns[lc].tag2 += ns[now].tag2);
        (ns[rc].tag1 != MAX) ? (ns[rc].tag1 += ns[now].tag2) : (ns[rc].tag2 += ns[now].tag2);
        ns[now].tag2 = 0;
    }
}
void edit(int l, int r, int x, int y, int now, int op, long long ex)
{
    if (x <= l && y >= r)
    {
        if (op == 1)
        {
            ns[now].v = ns[now].tag1 = ex, ns[now].tag2 = 0;
        }
        else
        {
            ns[now].v += ex;
            (ns[now].tag1 != MAX) ? (ns[now].tag1 += ex) : (ns[now].tag2 += ex);
        }
        return;
    }
    pushdown(l, r, now);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(l, mid, x, y, ns[now].lc, op, ex);
    }
    if (y > mid)
    {
        edit(mid + 1, r, x, y, ns[now].rc, op, ex);
    }
    update(now);
}
long long query(int l, int r, int x, int y, int now)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(l, r, now);
    int mid = (l + r) / 2;
    long long ans = -MAX;
    if (x <= mid)
    {
        ans = max(ans, query(l, mid, x, y, ns[now].lc));
    }
    if (y > mid)
    {
        ans = max(ans, query(mid + 1, r, x, y, ns[now].rc));
    }
    update(now);
    return ans;
}
int main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    init(1, n, root);
    for (int i = 1; i <= q; i++)
    {
        int op = read(), l = read(), r = read();
        if (op <= 2) // 区间赋值/修改
        {
            long long x = read();
            edit(1, n, l, r, root, op, x);
        }
        else // 区间最值
        {
            printf("%lld\n", query(1, n, l, r, root));
        }
    }
    return 0;
}