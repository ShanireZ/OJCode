#include <algorithm>
#include <iostream>
using namespace std;
#define LC ns[now].lc
#define RC ns[now].rc
#define MX 200005
struct Node
{
    int lc, rc;
    long long v;
};
Node ns[MX * 30];
int root[MX], npos, gpos = 1;
long long a[MX], read();
void update(int now)
{
    ns[now].v = ns[LC].v + ns[RC].v;
}
void maketree(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    maketree(LC, l, mid), maketree(RC, mid + 1, r);
    update(now);
}
void merge(int from, int &to, int l, int r)
{
    if (from == 0 || to == 0)
    {
        to = from + to;
        return;
    }
    if (l == r)
    {
        ns[to].v += ns[from].v;
        return;
    }
    int mid = (l + r) / 2;
    merge(ns[from].lc, ns[to].lc, l, mid);
    merge(ns[from].rc, ns[to].rc, mid + 1, r);
    update(to);
}
int query(int now, int l, int r, int x)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (x <= ns[LC].v)
    {
        return query(LC, l, mid, x);
    }
    else
    {
        return query(RC, mid + 1, r, x - ns[LC].v);
    }
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2;
    long long ans = 0;
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
void edit(int &now, int l, int r, long long x, int q)
{
    if (now == 0)
    {
        now = ++npos;
    }
    if (l == r)
    {
        ns[now].v += x;
        return;
    }
    int mid = (l + r) / 2;
    if (q <= mid)
    {
        edit(LC, l, mid, x, q);
    }
    else
    {
        edit(RC, mid + 1, r, x, q);
    }
    update(now);
}
void split(int &from, int &to, int l, int r, int x, int y)
{
    if (from == 0)
    {
        return;
    }
    if (x <= l && y >= r)
    {
        swap(from, to);
        return;
    }
    int mid = (l + r) / 2;
    to = ++npos;
    if (x <= mid)
    {
        split(ns[from].lc, ns[to].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        split(ns[from].rc, ns[to].rc, mid + 1, r, x, y);
    }
    update(from), update(to);
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    maketree(root[1], 1, n);
    while (m--)
    {
        int opt = read(), p = read(), x = read();
        if (opt == 0) // 将可重集 $p$ 中大于等于 $x$ 且小于等于 $y$ 的值移动到一个新的可重集中
        {
            int y = read();
            split(root[p], root[++gpos], 1, n, x, y);
        }
        else if (opt == 1) // 将可重集 $x$ 中的数放入可重集 $p$，且清空可重集 $x$
        {
            merge(root[x], root[p], 1, n);
        }
        else if (opt == 2) // 在 $p$ 这个可重集中加入 $x$ 个数字 $q$
        {
            long long q = read();
            edit(root[p], 1, n, x, q);
        }
        else if (opt == 3) // 查询可重集 $p$ 中大于等于 $x$ 且小于等于 $y$ 的值的个数
        {
            int y = read();
            printf("%lld\n", query(root[p], 1, n, x, y));
        }
        else // 查询在 $p$ 这个可重集中第 $x$ 小的数，不存在时输出 `-1`
        {
            int ans = (ns[root[p]].v < x ? -1 : query(root[p], 1, n, x));
            printf("%d\n", ans);
        }
    }
    return 0;
}
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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