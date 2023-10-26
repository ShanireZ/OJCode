#include <algorithm>
#include <iostream>
using namespace std;
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
    int lc, rc;
    long long v, tag;
};
Node ns[200005];
int a[100005], root, pos;
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(LC, l, mid), init(RC, mid + 1, r);
    ns[now].v = ns[LC].v + ns[RC].v;
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag)
    {
        int mid = (l + r) / 2;
        ns[LC].tag += ns[now].tag, ns[RC].tag += ns[now].tag;
        ns[LC].v += ns[now].tag * (mid - l + 1), ns[RC].v += ns[now].tag * (r - mid);
        ns[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        ns[now].tag += k, ns[now].v += k * (r - l + 1);
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, k);
    }
    ns[now].v = ns[LC].v + ns[RC].v;
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
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
int main()
{
    int n, m, pre = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int now;
        cin >> now;
        a[i] = now - pre, pre = now;
    }
    a[++n] = -pre;
    init(root, 1, n); // 对差分数组建线段树
    for (int i = 1; i <= m; i++)
    {
        int opt, l, r, k, d;
        cin >> opt >> l;
        if (opt == 1)
        {
            cin >> r >> k >> d;
            edit(root, 1, n, l, l, k);
            edit(root, 1, n, l + 1, r, d);
            edit(root, 1, n, r + 1, r + 1, -(k + (r - l) * d));
        }
        else
        {
            cout << query(root, 1, n, 1, l) << "\n";
        }
    }
    return 0;
}
// TAG: 线段树 差分 前缀和