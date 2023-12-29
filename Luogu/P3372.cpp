#include <iostream>
#include <string>
using namespace std;
int n, m, pos, root;
long long a[100005];
struct Node
{
    int lc, rc;
    long long tag, v; // tag表示以当前节点为根的子树中，后辈节点的待更新值
};
Node ns[400005];
void pushdown(int now, int l, int r)
{
    int mid = (l + r) / 2;
    ns[ns[now].lc].v += (mid - l + 1) * ns[now].tag;
    ns[ns[now].rc].v += (r - mid) * ns[now].tag;
    ns[ns[now].lc].tag += ns[now].tag, ns[ns[now].rc].tag += ns[now].tag;
    ns[now].tag = 0;
}
void init(int &now, int l, int r) // now当前节点编号 l左边界 r右边界
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        ns[now].v += (r - l + 1) * k, ns[now].tag += k;
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
}
long long querry(int now, int l, int r, int x, int y)
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
        ans += querry(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += querry(ns[now].rc, mid + 1, r, x, y);
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
        long long opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 1) // todo 修改
        {
            cin >> k;
            edit(root, 1, n, x, y, k);
        }
        else // todo 查询
        {
            cout << querry(root, 1, n, x, y) << endl;
        }
    }
    return 0;
}