#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    long long v, v2, tag;
    int lc, rc;
};
Node ns[400005];
int a[100005], n, m, root, pos;
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l], ns[now].v2 = a[l] * a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].v2 = ns[ns[now].lc].v2 + ns[ns[now].rc].v2;
}
void pushdown(int now, int l, int r)
{
    int mid = (l + r) / 2;
    long long t = ns[now].tag;
    ns[ns[now].lc].v2 += t * t * (mid - l + 1) + 2 * t * ns[ns[now].lc].v;
    ns[ns[now].rc].v2 += t * t * (r - mid) + 2 * t * ns[ns[now].rc].v;
    ns[ns[now].lc].v += t * (mid - l + 1), ns[ns[now].rc].v += t * (r - mid);
    ns[ns[now].lc].tag += t, ns[ns[now].rc].tag += t;
    ns[now].tag = 0;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].v2 += k * k * (r - l + 1) + 2 * k * ns[now].v;
        ns[now].v += k * (r - l + 1);
        ns[now].tag += k;
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
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    ns[now].v2 = ns[ns[now].lc].v2 + ns[ns[now].rc].v2;
}
pair<long long, long long> query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return make_pair(ns[now].v, ns[now].v2);
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    pair<long long, long long> ans = make_pair(0, 0);
    if (x <= mid)
    {
        pair<long long, long long> t = query(ns[now].lc, l, mid, x, y);
        ans.first += t.first, ans.second += t.second;
    }
    if (y > mid)
    {
        pair<long long, long long> t = query(ns[now].rc, mid + 1, r, x, y);
        ans.first += t.first, ans.second += t.second;
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, k;
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            edit(root, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            long long up = query(root, 1, n, x, y).first, down = y - x + 1;
            if (up == 0)
            {
                cout << "0/1" << endl;
            }
            else
            {
                long long gcd = __gcd(up, down);
                cout << up / gcd << "/" << down / gcd << endl;
            }
        }
        else
        {
            pair<long long, long long> p = query(root, 1, n, x, y);
            long long len = y - x + 1;
            long long up = p.second * len + p.first * p.first - 2 * p.first * p.first, down = len * len;
            if (up == 0)
            {
                cout << "0/1" << endl;
            }
            else
            {
                long long gcd = __gcd(up, down);
                cout << up / gcd << "/" << down / gcd << endl;
            }
        }
    }
    return 0;
}
// TAG: 线段树 方差 平均数