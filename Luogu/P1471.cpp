#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define maxsz 100005
struct Node
{
    double v, sq, tag;
    int lc, rc;
};
Node ns[4 * maxsz];
int cnt, root;
double w[maxsz];
void update(int now)
{
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].sq = ns[ns[now].lc].sq + ns[ns[now].rc].sq;
}
void pushdown(int now, int l, int r)
{
    int lc = ns[now].lc, rc = ns[now].rc, mid = (l + r) / 2;
    ns[lc].sq += (mid - l + 1) * ns[now].tag * ns[now].tag + 2 * ns[now].tag * ns[lc].v;
    ns[rc].sq += (r - mid) * ns[now].tag * ns[now].tag + 2 * ns[now].tag * ns[rc].v;
    ns[lc].v += ns[now].tag * (mid - l + 1);
    ns[rc].v += ns[now].tag * (r - mid);
    ns[lc].tag += ns[now].tag, ns[rc].tag += ns[now].tag, ns[now].tag = 0;
}
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        ns[now].v = w[l];
        ns[now].sq = w[l] * w[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int x, int y, double k)
{
    if (x <= l && y >= r)
    {
        ns[now].tag += k;
        ns[now].sq += (r - l + 1) * k * k + 2 * k * ns[now].v;
        ns[now].v += (r - l + 1) * k;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    update(now);
}
double queryv(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    double ans = 0;
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        ans += queryv(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += queryv(ns[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
double querysq(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].sq;
    }
    pushdown(now, l, r);
    double ans = 0;
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        ans += querysq(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += querysq(ns[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            double k;
            cin >> k;
            edit(root, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            cnt = y - x + 1;
            printf("%.4lf\n", queryv(root, 1, n, x, y) / cnt);
        }
        else
        {
            cnt = y - x + 1;
            double avg = queryv(root, 1, n, x, y) / cnt;
            double sq = querysq(root, 1, n, x, y);
            printf("%.4lf\n", sq / cnt - avg * avg);
        }
    }
    return 0;
}