#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, v;
};
Node ns[1000005];
int n, root, pos, a[500005], ys[500005];
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
}
void edit(int now, int l, int r, int x)
{
    if (l == r)
    {
        ns[now].v++;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2, sum = 0;
    if (x <= mid)
    {
        sum += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        sum += query(ns[now].rc, mid + 1, r, x, y);
    }
    return sum;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ys[i] = a[i];
    }
    maketree(root, 1, n);
    sort(ys + 1, ys + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ys + 1, ys + 1 + n, a[i]) - ys;
        ans += query(root, 1, n, a[i] + 1, n);
        edit(root, 1, n, a[i]);
    }
    cout << ans << endl;
    return 0;
}