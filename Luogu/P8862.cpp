#include <cstring>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int lc, rc;
    long long v, tag;
};
Node ns[MX * 4];
struct Quest
{
    int op, l, r;
    long long x;
};
Quest qst[MX];
long long read(), a[MX], b[MX];
int n, q, root, cnt;
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        ns[now].v = b[l], ns[now].tag = 0;
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    ns[now].v = min(ns[ns[now].lc].v, ns[ns[now].rc].v), ns[now].tag = 0;
}
void pushdown(int now)
{
    if (ns[now].tag)
    {
        int lc = ns[now].lc, rc = ns[now].rc;
        long long tag = ns[now].tag;
        ns[lc].v += tag, ns[lc].tag += tag, ns[rc].v += tag, ns[rc].tag += tag;
        ns[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int y, long long ex)
{
    if (x <= l && y >= r)
    {
        ns[now].v += ex, ns[now].tag += ex;
        return;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, ex);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, ex);
    }
    ns[now].v = min(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    long long ans = 1e18;
    if (x <= mid)
    {
        ans = min(ans, query(ns[now].lc, l, mid, x, y));
    }
    if (y > mid)
    {
        ans = min(ans, query(ns[now].rc, mid + 1, r, x, y));
    }
    return ans;
}
int main()
{
    int T = read();
    while (T--)
    {
        n = read(), q = read(), cnt = 0, root = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }
        for (int i = 1; i <= q; i++)
        {
            qst[i].op = read(), qst[i].l = read(), qst[i].r = read();
            if (qst[i].op == 1)
            {
                qst[i].x = read();
            }
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = read();
        }
        init(root, 1, n);
        for (int i = q; i >= 1; i--)
        {
            if (qst[i].op == 1)
            {
                edit(root, 1, n, qst[i].l, qst[i].r, -qst[i].x);
            }
            else
            {
                qst[i].x = query(root, 1, n, qst[i].l, qst[i].r);
            }
        }
        for (int i = 1; i <= q; i++)
        {
            if (qst[i].op == 2)
            {
                printf("%lld ", qst[i].x);
            }
        }
        printf("\n");
    }
    return 0;
}
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