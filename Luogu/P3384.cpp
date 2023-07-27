#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
#define LC seg[now].lc
#define RC seg[now].rc
struct Seg
{
    int lc, rc;
    long long tag, v;
};
Seg seg[MX * 4];
struct Node
{
    int hd, dfn, dp, zson, sz, fa, inv;
};
Node ns[MX];
vector<int> to[MX];
int n, m, root, pos, segroot, ids[MX];
long long mod;
void dfs1(int now)
{
    ns[now].sz = 1;
    for (int ch : to[now])
    {
        if (ch == ns[now].fa)
        {
            continue;
        }
        ns[ch].fa = now, ns[ch].dp = ns[now].dp + 1;
        dfs1(ch);
        ns[now].sz += ns[ch].sz;
        if (ns[ch].sz > ns[ns[now].zson].sz)
        {
            ns[now].zson = ch;
        }
    }
}
void dfs2(int now, int head)
{
    ns[now].hd = head, ns[now].dfn = ++pos;
    ids[pos] = now;
    if (ns[now].zson)
    {
        dfs2(ns[now].zson, head);
    }
    for (int ch : to[now])
    {
        if (ch == ns[now].fa || ch == ns[now].zson)
        {
            continue;
        }
        dfs2(ch, ch);
    }
}
void maketree(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        seg[now].v = ns[ids[l]].inv;
        return;
    }
    int mid = (l + r) / 2;
    maketree(LC, l, mid), maketree(RC, mid + 1, r);
    seg[now].v = (seg[LC].v + seg[RC].v) % mod;
}
void pushdown(int now, int l, int r)
{
    if (seg[now].tag)
    {
        int mid = (l + r) / 2;
        seg[LC].tag = (seg[LC].tag + seg[now].tag) % mod;
        seg[RC].tag = (seg[RC].tag + seg[now].tag) % mod;
        seg[LC].v = (seg[LC].v + (mid - l + 1) * seg[now].tag % mod) % mod;
        seg[RC].v = (seg[RC].v + (r - mid) * seg[now].tag % mod) % mod;
        seg[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        seg[now].tag = (seg[now].tag + k) % mod;
        seg[now].v = (seg[now].v + (r - l + 1) * k % mod) % mod;
        return;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, k);
    }
    seg[now].v = (seg[LC].v + seg[RC].v) % mod;
}
long long query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return seg[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2;
    long long ans = 0;
    if (x <= mid)
    {
        ans = (ans + query(LC, l, mid, x, y)) % mod;
    }
    if (y > mid)
    {
        ans = (ans + query(RC, mid + 1, r, x, y)) % mod;
    }
    return ans;
}
void lcaedit(int x, int y, long long k)
{
    while (ns[x].hd != ns[y].hd)
    {
        if (ns[ns[x].hd].dp < ns[ns[y].hd].dp)
        {
            swap(x, y);
        }
        edit(segroot, 1, n, ns[ns[x].hd].dfn, ns[x].dfn, k);
        x = ns[ns[x].hd].fa;
    }
    if (ns[x].dp > ns[y].dp)
    {
        swap(x, y);
    }
    edit(segroot, 1, n, ns[x].dfn, ns[y].dfn, k);
}
long long lcaquery(int x, int y)
{
    long long ans = 0;
    while (ns[x].hd != ns[y].hd)
    {
        if (ns[ns[x].hd].dp < ns[ns[y].hd].dp)
        {
            swap(x, y);
        }
        ans = (ans + query(segroot, 1, n, ns[ns[x].hd].dfn, ns[x].dfn)) % mod;
        x = ns[ns[x].hd].fa;
    }
    if (ns[x].dp > ns[y].dp)
    {
        swap(x, y);
    }
    ans = (ans + query(segroot, 1, n, ns[x].dfn, ns[y].dfn)) % mod;
    return ans;
}
int main()
{
    cin >> n >> m >> root >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].inv;
        ns[i].inv %= mod;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs1(root);
    dfs2(root, root);
    pos = 0;
    maketree(segroot, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        long long z;
        cin >> opt >> x;
        if (opt == 1)
        {
            cin >> y >> z;
            lcaedit(x, y, z % mod);
        }
        else if (opt == 2)
        {
            cin >> y;
            cout << lcaquery(x, y) << "\n";
        }
        else if (opt == 3)
        {
            cin >> z;
            edit(segroot, 1, n, ns[x].dfn, ns[x].dfn + ns[x].sz - 1, z % mod);
        }
        else
        {
            cout << query(segroot, 1, n, ns[x].dfn, ns[x].dfn + ns[x].sz - 1) << "\n";
        }
    }
    return 0;
}