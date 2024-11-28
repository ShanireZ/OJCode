#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, q, dpos, npos, root, dfn[100005], ed[100005], ids[100005];
struct Node
{
    int lc, rc, v, tag;
};
Node ns[400005];
void init(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].v = 1;
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
}
void pushdown(int now, int l, int r)
{
    ns[ns[now].lc].tag = max(ns[ns[now].lc].tag, ns[now].tag);
    ns[ns[now].rc].tag = max(ns[ns[now].rc].tag, ns[now].tag);
    ns[ns[now].lc].v = max(ns[ns[now].lc].v, ns[now].tag);
    ns[ns[now].rc].v = max(ns[ns[now].rc].v, ns[now].tag);
    ns[now].tag = 0;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].tag = max(ns[now].tag, k);
        ns[now].v = max(ns[now].v, k);
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
}
int query(int now, int l, int r, int p)
{
    if (l == r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        return query(ns[now].lc, l, mid, p);
    }
    else
    {
        return query(ns[now].rc, mid + 1, r, p);
    }
}
void dfs(int now, int from)
{
    dfn[now] = ed[now] = ++dpos;
    ids[dpos] = now;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        ed[now] = max(ed[now], ed[nxt]);
    }
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
    }
    dfs(1, 0);
    init(root, 1, n);
    while (q--)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'C')
        {
            edit(root, 1, n, dfn[x], ed[x], dfn[x]);
        }
        else
        {
            cout << ids[query(root, 1, n, dfn[x])] << endl;
        }
    }
    return 0;
}