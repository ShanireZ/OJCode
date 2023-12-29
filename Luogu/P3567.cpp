#include <algorithm>
#include <iostream>
using namespace std;
#define MX 500005
struct Node
{
    int v, lc, rc;
};
Node ns[20 * MX];
int root[MX], pos, n, m, num;
void edit(int &now, int old, int l, int r, int x)
{
    now = ++pos;
    ns[now] = ns[old], ns[now].v++;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, ns[old].lc, l, mid, x);
    }
    else
    {
        edit(ns[now].rc, ns[old].rc, mid + 1, r, x);
    }
}
int query(int now, int old, int l, int r, int t)
{
    if (l == r)
    {
        return (ns[now].v - ns[old].v >= t ? l : 0);
    }
    int mid = (l + r) / 2, ans = 0;
    if (ns[ns[now].lc].v - ns[ns[old].lc].v >= t)
    {
        ans = query(ns[now].lc, ns[old].lc, l, mid, t);
    }
    else if (ns[ns[now].rc].v - ns[ns[old].rc].v >= t)
    {
        ans = query(ns[now].rc, ns[old].rc, mid + 1, r, t);
    }
    return ans;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        edit(root[i], root[i - 1], 1, n, num);
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(root[r], root[l - 1], 1, n, (r - l + 1) / 2 + 1));
    }
    return 0;
}
// TAG: 可持久化线段树 树上差分