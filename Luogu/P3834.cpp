#include <algorithm>
#include <iostream>
using namespace std;
#define MX 200005
struct Node
{
    int lc, rc, v;
};
Node ns[MX * 40];
int read(), n, m, sz, cnt, a[MX], ls[MX], root[MX];
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
}
void edit(int &now, int old, int l, int r, int pos)
{
    now = ++cnt;
    ns[now] = ns[old];
    if (l == r)
    {
        ns[now].v++;
        return;
    }
    int mid = (l + r) / 2;
    (pos <= mid) ? edit(ns[now].lc, ns[old].lc, l, mid, pos) : edit(ns[now].rc, ns[old].rc, mid + 1, r, pos);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int now, int old, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2, tot = ns[ns[now].lc].v - ns[ns[old].lc].v;
    return (tot >= k) ? query(ns[now].lc, ns[old].lc, l, mid, k) : query(ns[now].rc, ns[old].rc, mid + 1, r, k - tot);
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        ls[i] = a[i] = read();
    }
    sort(ls + 1, ls + 1 + n);
    sz = unique(ls + 1, ls + 1 + n) - (ls + 1);
    init(root[0], 1, sz);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(ls + 1, ls + 1 + sz, a[i]) - ls;
        edit(root[i], root[i - 1], 1, sz, pos);
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read(), k = read();
        printf("%d\n", ls[query(root[r], root[l - 1], 1, sz, k)]);
    }
    return 0;
}
int read()
{
    int ans = 0, f = 1;
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