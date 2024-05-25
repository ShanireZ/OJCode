#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc;
    bitset<35> v, tag;
};
Node ns[400005];
int n, t, m, pos, root;
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v[1] = 1;
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
    ns[now].v = ns[ns[now].lc].v | ns[ns[now].rc].v;
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag != 0)
    {
        ns[ns[now].lc].v = ns[now].tag;
        ns[ns[now].rc].v = ns[now].tag;
        ns[ns[now].lc].tag = ns[now].tag;
        ns[ns[now].rc].tag = ns[now].tag;
        ns[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int y, bitset<35> k)
{
    if (x <= l && y >= r)
    {
        ns[now].v = k, ns[now].tag = k;
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
    ns[now].v = ns[ns[now].lc].v | ns[ns[now].rc].v;
}
bitset<35> query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    bitset<35> res = 0;
    if (x <= mid)
    {
        res |= query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        res |= query(ns[now].rc, mid + 1, r, x, y);
    }
    return res;
}
int main()
{
    cin >> n >> t >> m;
    maketree(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        char op;
        int a, b, c;
        cin >> op >> a >> b;
        if (a > b) // 不保证前小后大
        {
            swap(a, b);
        }
        if (op == 'C')
        {
            cin >> c;
            bitset<35> k = 0;
            k[c] = 1;
            edit(root, 1, n, a, b, k);
        }
        else
        {
            cout << query(root, 1, n, a, b).count() << endl;
        }
    }
    return 0;
}