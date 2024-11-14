#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int lc, rc, v;
};
Node ns[MX * 6];
int root, pos, lspos, rpos;
int ls[MX * 3], ts[MX * 3], ed[MX * 3], h[MX], l[MX], r[MX], res[MX * 4];
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
}
void pushdown(int now, int l, int r)
{
    if (ns[now].v)
    {
        ns[ns[now].lc].v = max(ns[ns[now].lc].v, ns[now].v);
        ns[ns[now].rc].v = max(ns[ns[now].rc].v, ns[now].v);
        ns[now].v = 0;
    }
}
void edit(int now, int l, int r, int x, int y, int z)
{
    if (x <= l && y >= r)
    {
        ns[now].v = max(ns[now].v, z);
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, z);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, z);
    }
}
int query(int now, int l, int r, int p)
{
    if (l == r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1;
    return p <= mid ? query(ns[now].lc, l, mid, p) : query(ns[now].rc, mid + 1, r, p);
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
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
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        h[i] = read(), l[i] = read(), r[i] = read();
        ls[++lspos] = l[i], ls[++lspos] = r[i], ls[++lspos] = r[i] + 1;
    }
    sort(ls + 1, ls + lspos + 1);
    lspos = unique(ls + 1, ls + lspos + 1) - ls - 1;
    init(root, 1, lspos);
    for (int i = 1; i <= n; i++)
    {
        int pl = lower_bound(ls + 1, ls + lspos + 1, l[i]) - ls;
        int pr = lower_bound(ls + 1, ls + lspos + 1, r[i]) - ls;
        edit(root, 1, lspos, pl, pr, h[i]);
        ts[pl]++, ts[pr + 1]--, ed[pr] = 1;
    }
    int pre = 0;
    for (int i = 1; i <= lspos; i++)
    {
        int h = query(root, 1, lspos, i);
        if (h != pre)
        {
            res[++rpos] = (h > pre ? ls[i] : ls[i - 1]),
            res[++rpos] = pre, res[++rpos] = h;
            pre = h;
        }
        ts[i] += ts[i - 1];
        if (ed[i] && ts[i] == 1)
        {
            res[++rpos] = ls[i], res[++rpos] = pre, res[++rpos] = 0;
            pre = 0;
        }
    }
    printf("%d\n", rpos / 3 * 2);
    for (int i = 1; i <= rpos; i += 3)
    {
        printf("%d %d\n", res[i], res[i + 1]);
        printf("%d %d\n", res[i], res[i + 2]);
    }
    return 0;
}