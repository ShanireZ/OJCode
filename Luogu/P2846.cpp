#include <algorithm>
#include <iostream>
using namespace std;
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
    int lc, rc, v, tag;
};
Node ns[400005];
int root, n, m, cnt;
void update(int now)
{
    ns[now].v = ns[LC].v + ns[RC].v;
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag)
    {
        int mid = (l + r) / 2;
        ns[LC].tag ^= 1, ns[RC].tag ^= 1, ns[now].tag = 0;
        ns[LC].v = (mid - l + 1) - ns[LC].v, ns[RC].v = (r - mid) - ns[RC].v;
    }
}
void maketree(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    maketree(LC, l, mid), maketree(RC, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int x, int y)
{
    pushdown(now, l, r);
    if (x <= l && y >= r)
    {
        ns[now].tag ^= 1, ns[now].v = (r - l + 1) - ns[now].v;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y);
    }
    update(now);
}
int query(int now, int l, int r, int x, int y)
{
    pushdown(now, l, r);
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int ans = 0, mid = (l + r) / 2;
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
    cin >> n >> m;
    maketree(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt, a, b;
        cin >> opt >> a >> b;
        if (opt == 0)
        {
            edit(root, 1, n, a, b);
        }
        else
        {
            cout << query(root, 1, n, a, b) << "\n";
        }
    }
    return 0;
}