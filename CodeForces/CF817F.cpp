#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#define MX 100005
#define LC ns[now].lc
#define RC ns[now].rc
struct Area
{
    long long l, r, opt;
};
Area as[MX];
struct Node
{
    int lc, rc;
    long long v, len, tag; // 1铺满 2清空 3反转
};
Node ns[MX * 8];
long long ls[MX * 2];
int pos, npos, n, root;
void update(int now)
{
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void init(int &now, long long l, long long r)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].len = ls[l + 1] - ls[l];
        return;
    }
    long long mid = (l + r) / 2;
    init(LC, l, mid), init(RC, mid + 1, r);
    ns[now].len = ns[LC].len + ns[RC].len;
}
void pushdown(int now)
{
    if (ns[now].tag == 1)
    {
        ns[LC].tag = ns[RC].tag = 1;
        ns[LC].v = ns[LC].len, ns[RC].v = ns[RC].len;
    }
    else if (ns[now].tag == 2)
    {
        ns[LC].tag = ns[RC].tag = 2;
        ns[LC].v = ns[RC].v = 0;
    }
    else if (ns[now].tag == 3)
    {
        ns[LC].tag = 3 - ns[LC].tag, ns[RC].tag = 3 - ns[RC].tag;
        ns[LC].v = ns[LC].len - ns[LC].v, ns[RC].v = ns[RC].len - ns[RC].v;
    }
    ns[now].tag = 0;
}
void edit(int now, long long l, long long r, long long x, long long y, int opt)
{
    pushdown(now); // 对于第三种操作，需要先下传再反转
    if (x <= l && y >= r)
    {
        if (opt == 1)
        {
            ns[now].v = ns[now].len;
        }
        else if (opt == 2)
        {
            ns[now].v = 0;
        }
        else
        {
            ns[now].v = ns[now].len - ns[now].v;
        }
        ns[now].tag = opt;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, opt);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, opt);
    }
    update(now);
}
long long query(int now, long long l, long long r)
{
    if (l == r)
    {
        return ls[l];
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (ns[LC].v != ns[LC].len)
    {
        return query(LC, l, mid);
    }
    else
    {
        return query(RC, mid + 1, r);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> as[i].opt >> as[i].l >> as[i].r;
        as[i].r++;
        ls[++pos] = as[i].l;
        ls[++pos] = as[i].r;
    }
    ls[++pos] = 1;
    ls[++pos] = 1000000000000000002ll;
    sort(ls + 1, ls + 1 + pos);
    pos = unique(ls + 1, ls + 1 + pos) - ls - 1;
    init(root, 1, pos - 1);
    for (int i = 1; i <= n; i++)
    {
        as[i].l = lower_bound(ls + 1, ls + 1 + pos, as[i].l) - ls;
        as[i].r = lower_bound(ls + 1, ls + 1 + pos, as[i].r) - ls - 1;
        edit(root, 1, pos - 1, as[i].l, as[i].r, as[i].opt);
        cout << query(root, 1, pos - 1) << "\n";
    }
    return 0;
}
// TAG: 线段树 离散化 区间映射