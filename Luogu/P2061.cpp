#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc;
    long long val;
};
Node ns[320005];
struct OPT
{
    int a, b;
    long long h;
};
OPT opt[40005];
long long all[80005];
int read(), pos, root;
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
}
void edit(int now, int l, int r, int x, int y, long long val)
{
    if (ns[now].val >= val)
    {
        return;
    }
    if (x <= l && y >= r)
    {
        ns[now].val = val;
        return;
    }
    int lc = ns[now].lc, rc = ns[now].rc, mid = (l + r) / 2;
    ns[lc].val = max(ns[now].val, ns[lc].val), ns[rc].val = max(ns[now].val, ns[rc].val);
    if (x <= mid)
    {
        edit(lc, l, mid, x, y, val);
    }
    if (y > mid)
    {
        edit(rc, mid + 1, r, x, y, val);
    }
}
long long count(int now, int l, int r)
{
    if (l == r)
    {
        return ns[now].val * (all[l + 1] - all[l]);
    }
    int lc = ns[now].lc, rc = ns[now].rc, mid = (l + r) / 2;
    ns[lc].val = max(ns[now].val, ns[lc].val), ns[rc].val = max(ns[now].val, ns[rc].val);
    return count(lc, l, mid) + count(rc, mid + 1, r);
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        opt[i].a = read(), opt[i].b = read(), opt[i].h = read();
        all[i * 2 - 1] = opt[i].a, all[i * 2] = opt[i].b;
    }
    sort(all + 1, all + n * 2 + 1);
    int sz = unique(all + 1, all + n * 2 + 1) - (all + 1);
    init(root, 1, sz);
    for (int i = 1; i <= n; i++)
    {
        int x = lower_bound(all + 1, all + sz + 1, opt[i].a) - all;
        int y = lower_bound(all + 1, all + sz + 1, opt[i].b) - all - 1;
        edit(root, 1, sz, x, y, opt[i].h);
    }
    printf("%lld\n", count(root, 1, sz));
    return 0;
}
int read()
{
    int ans = 0;
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
// TAG: USACO 07OPEN Silver 离散化 线段树 区间修改 区间查询