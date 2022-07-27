#include <iostream>
#include <set>
using namespace std;
#define MX 4000005
struct Node
{
    int lc, rc, v;
};
Node ns[MX * 10];
int root[MX], nums[MX], pos;
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = nums[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
}
void edit(int &now, int old, int l, int r, int p, int v)
{
    now = ++pos;
    ns[now] = ns[old];
    if (l == r)
    {
        ns[now].v = v;
        return;
    }
    int mid = (l + r) / 2;
    p <= mid ? edit(ns[now].lc, ns[old].lc, l, mid, p, v) : edit(ns[now].rc, ns[old].rc, mid + 1, r, p, v);
}
int query(int now, int l, int r, int p)
{
    if (l == r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2;
    return p <= mid ? query(ns[now].lc, l, mid, p) : query(ns[now].rc, mid + 1, r, p);
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    init(root[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int old, opt, loc, v;
        cin >> old >> opt >> loc;
        if (opt == 1)
        {
            cin >> v;
            edit(root[i], root[old], 1, n, loc, v);
        }
        else
        {
            root[i] = root[old];
            cout << query(root[i], 1, n, loc) << endl;
        }
    }
    return 0;
}