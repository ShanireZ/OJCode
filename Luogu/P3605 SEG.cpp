#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
int n, cnt, root, pos;
int p[MX], ls[MX], to[MX], pre[MX], last[MX], ans[MX];
struct Node
{
    int t, lc, rc;
};
Node ns[MX * 4];
void update(int now)
{
    ns[now].t = ns[ns[now].lc].t + ns[ns[now].rc].t;
}
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
    update(now);
}
void edit(int now, int l, int r, int x)
{
    if (l == r)
    {
        ns[now].t++;
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
    update(now);
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].t;
    }
    int mid = (l + r) / 2, tot = 0;
    if (x <= mid)
    {
        tot += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        tot += query(ns[now].rc, mid + 1, r, x, y);
    }
    return tot;
}
void dfs(int now)
{
    edit(root, 1, cnt, p[now]);
    ans[now] = query(root, 1, cnt, p[now] + 1, cnt);
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        dfs(t);
    }
    ans[now] = query(root, 1, cnt, p[now] + 1, cnt) - ans[now];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        ls[i] = p[i];
    }
    sort(ls + 1, ls + 1 + n);
    cnt = unique(ls + 1, ls + 1 + n) - (ls + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = lower_bound(ls + 1, ls + 1 + cnt, p[i]) - ls;
    }
    for (int i = 2; i <= n; i++)
    {
        int fa;
        cin >> fa;
        to[i] = i, pre[i] = last[fa];
        last[fa] = i;
    }
    maketree(root, 1, cnt);
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}