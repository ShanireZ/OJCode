#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct A
{
    int v, id;
    bool operator<(const A na) const
    {
        return v < na.v;
    }
};
A a[300005];
struct Quest
{
    int l, r, id;
    bool operator<(const Quest nq) const
    {
        return r < nq.r;
    }
};
Quest q[300005];
struct PD
{
    int x, y;
    bool operator<(const PD np) const
    {
        return y < np.y;
    }
};
PD pd[600005];
int n, m, pos, tree[300005];
int lowbit(int now)
{
    return now & -now;
}
void edit(int now, int x)
{
    while (now <= n)
    {
        tree[now] += x;
        now += lowbit(now);
    }
}
int query(int now)
{
    int ans = 0;
    while (now)
    {
        ans += tree[now];
        now -= lowbit(now);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    a[0].v = -2e9 - 5, a[n + 1].v = 2e9 + 5;
    for (int i = 1; i <= n; i++)
    {
        int l = abs(a[i].v - a[i - 1].v), r = abs(a[i].v - a[i + 1].v);
        int x = a[i].id;
        int y = (l < r) ? a[i - 1].id : a[i + 1].id;
        pd[++pos].x = x;
        pd[pos].y = y;
        if (x > y)
        {
            swap(pd[pos].x, pd[pos].y);
        }
        if (l == r)
        {
            y = a[i - 1].id;
            pd[++pos].x = x;
            pd[pos].y = y;
            if (x > y)
            {
                swap(pd[pos].x, pd[pos].y);
            }
        }
    }
    sort(pd + 1, pd + 1 + pos);
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    int p = 1;
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        while (p <= pos && pd[p].y <= q[i].r)
        {
            edit(pd[p].x, 1);
            p++;
        }
        ans += 1ll * (query(q[i].r) - query(q[i].l - 1)) * q[i].id;
    }
    cout << ans << endl;
    return 0;
}