#include <iostream>
#include <vector>
using namespace std;
int n, m, root, mod, pos, cnt, id[100005], segroot;
struct Node //!树
{
    int fa, zson, sz, dp, head, dfn;
    long long v;
    vector<int> son;
};
Node ns[100005];
struct SegNode //!线段树
{
    int lc, rc;
    long long sum, tag;
};
SegNode seg[400005];
void dfs1(int now, int deep)
{
    ns[now].dp = deep;
    ns[now].sz = 1;
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int s = ns[now].son[i];
        if (s == ns[now].fa)
        {
            continue;
        }
        ns[s].fa = now;
        dfs1(s, deep + 1);
        if (ns[ns[now].zson].sz < ns[s].sz)
        {
            ns[now].zson = s;
        }
        ns[now].sz += ns[s].sz;
    }
}
void dfs2(int now, int top)
{
    ns[now].head = top;
    ns[now].dfn = ++pos;
    id[pos] = now;
    if (ns[now].zson)
    {
        dfs2(ns[now].zson, top);
    }
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int s = ns[now].son[i];
        if (s == ns[now].fa || s == ns[now].zson)
        {
            continue;
        }
        dfs2(s, s);
    }
}
void pushdown(int now, int l, int r)
{
    int lc = seg[now].lc, rc = seg[now].rc, tag = seg[now].tag % mod;
    int mid = (l + r) / 2;
    seg[lc].sum = (seg[lc].sum + (mid - l + 1) * tag % mod) % mod;
    seg[rc].sum = (seg[rc].sum + (r - mid) * tag % mod) % mod;
    seg[now].tag = 0;
    seg[lc].tag = (seg[lc].tag + tag) % mod, seg[rc].tag = (seg[rc].tag + tag) % mod;
}
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        seg[now].sum = ns[id[l]].v % mod;
        return;
    }
    int mid = (l + r) / 2;
    init(seg[now].lc, l, mid);
    init(seg[now].rc, mid + 1, r);
    seg[now].sum = (seg[seg[now].lc].sum + seg[seg[now].rc].sum) % mod;
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        seg[now].sum = (seg[now].sum + (r - l + 1) * k % mod) % mod;
        seg[now].tag = (seg[now].tag + k) % mod;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(seg[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(seg[now].rc, mid + 1, r, x, y, k);
    }
    seg[now].sum = (seg[seg[now].lc].sum + seg[seg[now].rc].sum) % mod;
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return seg[now].sum % mod;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    long long ans = 0;
    if (x <= mid)
    {
        ans = (ans + query(seg[now].lc, l, mid, x, y) % mod) % mod;
    }
    if (y > mid)
    {
        ans = (ans + query(seg[now].rc, mid + 1, r, x, y) % mod) % mod;
    }
    return ans % mod;
}
void lca_edit(int x, int y, long long k)
{
    while (ns[x].head != ns[y].head)
    {
        if (ns[ns[x].head].dp < ns[ns[y].head].dp)
        {
            swap(x, y);
        }
        edit(segroot, 1, n, ns[ns[x].head].dfn, ns[x].dfn, k);
        x = ns[ns[x].head].fa;
    }
    if (ns[x].dp < ns[y].dp)
    {
        swap(x, y);
    }
    edit(segroot, 1, n, ns[y].dfn, ns[x].dfn, k);
}
long long lca_query(int x, int y)
{
    long long ans = 0;
    while (ns[x].head != ns[y].head)
    {
        if (ns[ns[x].head].dp < ns[ns[y].head].dp)
        {
            swap(x, y);
        }
        ans = (ans + query(segroot, 1, n, ns[ns[x].head].dfn, ns[x].dfn) % mod) % mod;
        x = ns[ns[x].head].fa;
    }
    if (ns[x].dp < ns[y].dp)
    {
        swap(x, y);
    }
    ans = (ans + query(segroot, 1, n, ns[y].dfn, ns[x].dfn) % mod) % mod;
    return ans % mod;
}
int main()
{
    cin >> n >> m >> root >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
        ns[i].v %= mod;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ns[x].son.push_back(y);
        ns[y].son.push_back(x);
    }
    dfs1(root, 1);
    dfs2(root, root);
    init(segroot, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        long long z;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> z;
            z = z % mod;
            lca_edit(x, y, z);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << lca_query(x, y) << endl;
        }
        else if (op == 3)
        {
            cin >> x >> z;
            z = z % mod;
            edit(segroot, 1, n, ns[x].dfn, ns[x].sz + ns[x].dfn - 1, z);
        }
        else
        {
            cin >> x;
            cout << query(segroot, 1, n, ns[x].dfn, ns[x].sz + ns[x].dfn - 1) << endl;
        }
    }
    return 0;
}