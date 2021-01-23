#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
mt19937 rnd(709);
struct Node
{
    int l, r, v, idx, size, tag;
};
Node ns[100005];
int pos, root;
int newnode(int v)
{
    ns[++pos].v = v;
    ns[pos].size = 1;
    ns[pos].idx = rnd();
    return pos;
}
void update(int now)
{
    ns[now].size = ns[ns[now].l].size + ns[ns[now].r].size + 1;
}
void pushdown(int now)
{
    if (ns[now].tag == 1)
    {
        swap(ns[now].l, ns[now].r);
        ns[now].tag = 0;
        ns[ns[now].l].tag ^= 1;
        ns[ns[now].r].tag ^= 1;
    }
}
void split(int now, int sz, int &x, int &y)
{
    if (now == 0)
    {
        x = y = 0;
        return;
    }
    pushdown(now);
    if (ns[ns[now].l].size + 1 <= sz)
    {
        x = now;
        split(ns[now].r, sz - ns[ns[now].l].size - 1, ns[x].r, y);
    }
    else
    {
        y = now;
        split(ns[now].l, sz, x, ns[y].l);
    }
    update(now);
}
int merge(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return x + y;
    }
    if (ns[x].idx < ns[y].idx)
    {
        pushdown(x);
        ns[x].r = merge(ns[x].r, y);
        update(x);
        return x;
    }
    else
    {
        pushdown(y);
        ns[y].l = merge(x, ns[y].l);
        update(y);
        return y;
    }
}
void rvs(int l, int r)
{
    int a, b, c;
    split(root, l - 1, a, b);
    split(b, r - l + 1, b, c);
    ns[b].tag ^= 1;
    root = merge(merge(a, b), c);
}
void dfsm(int now)
{
    if (now == 0)
    {
        return;
    }
    pushdown(now);
    dfsm(ns[now].l);
    cout << ns[now].v << " ";
    dfsm(ns[now].r);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        root = merge(root, newnode(i));
    }
    for(int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        rvs(l, r);
    }
    dfsm(root);
    return 0;
}