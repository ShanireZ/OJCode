#include <cstdio>
#include <algorithm>
using namespace std;
long long read();
struct Node
{
    int lc, rc;
    long long v, add, mul;
};
Node ns[400005];
int pos, root;
long long a[100005], mod;
void update(int now)
{
    int lc = ns[now].lc, rc = ns[now].rc;
    ns[now].v = (ns[lc].v + ns[rc].v) % mod;
}
void pushdown(int now, int l, int r)
{
    int lc = ns[now].lc, rc = ns[now].rc, mid = (l + r) / 2;
    ns[lc].v = (ns[lc].v * ns[now].mul % mod + ns[now].add * (mid - l + 1) % mod) % mod;
    ns[rc].v = (ns[rc].v * ns[now].mul % mod + ns[now].add * (r - mid) % mod) % mod;
    ns[lc].add = (ns[lc].add * ns[now].mul % mod + ns[now].add) % mod;
    ns[rc].add = (ns[rc].add * ns[now].mul % mod + ns[now].add) % mod;
    ns[lc].mul = ns[lc].mul * ns[now].mul % mod;
    ns[rc].mul = ns[rc].mul * ns[now].mul % mod;
    ns[now].mul = 1, ns[now].add = 0;
}
void newTree(int &now, int l, int r)
{
    now = ++pos;
    ns[now].mul = 1;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    newTree(ns[now].lc, l, mid);
    newTree(ns[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int a, int b, long long k, int t)
{
    if (a <= l && r <= b)
    {
        if (t == 1)
        {
            ns[now].v = ns[now].v * k % mod;
            ns[now].add = ns[now].add * k % mod;
            ns[now].mul = ns[now].mul * k % mod;
        }
        else
        {
            ns[now].v = (ns[now].v + (r - l + 1) * k % mod) % mod;
            ns[now].add = (ns[now].add + k) % mod;
        }
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (a <= mid)
    {
        edit(ns[now].lc, l, mid, a, b, k, t);
    }
    if (b > mid)
    {
        edit(ns[now].rc, mid + 1, r, a, b, k, t);
    }
    update(now);
}
long long query(int now, int l, int r, int a, int b)
{
    if (a <= l && r <= b)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    long long ans = 0;
    if (a <= mid)
    {
        ans = (ans + query(ns[now].lc, l, mid, a, b)) % mod;
    }
    if (b > mid)
    {
        ans = (ans + query(ns[now].rc, mid + 1, r, a, b)) % mod;
    }
    return ans;
}
int main()
{
    int n = read(), m = read();
    mod = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read() % mod;
    }
    newTree(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read(), y = read();
        if (opt == 1 || opt == 2) //mul = 1 add = 2
        {
            long long k = read() % mod;
            edit(root, 1, n, x, y, k, opt);
        }
        else //query
        {
            printf("%lld\n", query(root, 1, n, x, y));
        }
    }
    return 0;
}
long long read()
{
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    long long ans = 0, t = 1;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}