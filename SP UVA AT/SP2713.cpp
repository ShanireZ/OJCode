#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, tag;
    long long v;
};
Node ns[400005];
long long a[100005];
int n, m, pos, root, id;
void update(int now, int l, int r)
{
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].tag = (ns[now].v == r - l + 1);
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l];
        ns[now].tag = (ns[now].v == 1);
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    update(now, l, r);
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
        ans += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += query(ns[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
void edit(int now, int l, int r, int x, int y)
{
    if (ns[now].tag == 1)
    {
        return;
    }
    if (l == r)
    {
        ns[now].v = sqrt(ns[now].v);
        ns[now].tag = (ns[now].v == 1);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y);
    }
    update(now, l, r);
}
int main()
{
    while ((scanf("%d", &n)) != EOF)
    {
        printf("Case #%d:\n", ++id);
        root = pos = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        init(root, 1, n);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            long long op, x, y;
            scanf("%lld%lld%lld", &op, &x, &y);
            if (x > y)
            {
                swap(x, y);
            }
            if (op == 0)
            {
                edit(root, 1, n, x, y);
            }
            else
            {
                printf("%lld\n", query(root, 1, n, x, y));
            }
        }
        printf("\n");
    }
    return 0;
}
// TAG: 线段树 开根号