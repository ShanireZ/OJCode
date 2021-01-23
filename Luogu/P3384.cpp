#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, r, mod, pos, root;
struct Node
{
    int v, fa, dep, dfn, sz, zson, top;
    vector<int> ways;
};
Node ns[100005];
int dfn[100005];
struct Point
{
    int lc, rc, tag, v;
};
Point pts[400005];
void dfs1(int now, int fa)
{
    ns[now].fa = fa;
    ns[now].sz = 1;
    ns[now].dep = ns[fa].dep + 1;
    int maxsz = 0;
    for (int i = 0; i < ns[now].ways.size(); i++)
    {
        int to = ns[now].ways[i];
        if (to != fa)
        {
            dfs1(to, now);
            ns[now].sz += ns[to].sz;
            if (ns[to].sz > maxsz)
            {
                maxsz = ns[to].sz;
                ns[now].zson = to;
            }
        }
    }
}
void dfs2(int now, int top)
{
    ns[now].top = top;
    ns[now].dfn = ++pos;
    dfn[pos] = now;
    if (ns[now].sz > 1)
    {
        dfs2(ns[now].zson, top);
        for (int i = 0; i < ns[now].ways.size(); i++)
        {
            int to = ns[now].ways[i];
            if (to != ns[now].fa && to != ns[now].zson)
            {
                dfs2(to, to);
            }
        }
    }
}
void make_tree(int l, int r, int &now)
{
    now = ++pos;
    if (l == r)
    {
        pts[now].v = ns[dfn[l]].v % mod;
        return;
    }
    int mid = (l + r) / 2;
    make_tree(l, mid, pts[now].lc);
    make_tree(mid + 1, r, pts[now].rc);
    pts[now].v = (pts[pts[now].lc].v + pts[pts[now].rc].v) % mod;
}
void pushdown(int l, int r, int now)
{
    if (pts[now].tag)
    {
        pts[now].v = (pts[now].v + (r - l + 1) * pts[now].tag % mod) % mod;
        pts[pts[now].lc].tag = (pts[pts[now].lc].tag + pts[now].tag) % mod;
        pts[pts[now].rc].tag = (pts[pts[now].rc].tag + pts[now].tag) % mod;
        pts[now].tag = 0;
    }
}
void edit(int l, int r, int now, int x, int y, int k)
{
    if (l == x && y == r)
    {
        pts[now].tag = (pts[now].tag + k) % mod;
        pushdown(l, r, now);
        return;
    }
    pushdown(l, r, now);
    int mid = (l + r) / 2;
    if (x <= mid && y >= l)
    {
        edit(l, mid, pts[now].lc, max(l, x), min(y, mid), k);
        pts[now].v = (pts[now].v + k * (min(y, mid) - max(l, x) + 1) % mod) % mod;
    }
    if (x <= r && y >= mid + 1)
    {
        edit(mid + 1, r, pts[now].rc, max(mid + 1, x), min(y, r), k);
        pts[now].v = (pts[now].v + k * (min(y, r) - max(mid + 1, x) + 1) % mod) % mod;
    }
}
int search(int l, int r, int now, int x, int y)
{
    pushdown(l, r, now);
    if (l == x && y == r)
    {
        return pts[now].v % mod;
    }
    int mid = (l + r) / 2;
    int ans = 0;
    if (x <= mid && y >= l)
    {
        ans = (ans + search(l, mid, pts[now].lc, max(l, x), min(y, mid))) % mod;
    }
    if (x <= r && y >= mid + 1)
    {
        ans = (ans + search(mid + 1, r, pts[now].rc, max(mid + 1, x), min(y, r))) % mod;
    }
    return ans;
}
void path_edit(int x, int y, int k)
{
    while (ns[x].top != ns[y].top)
    {
        if (ns[ns[x].top].dep < ns[ns[y].top].dep)
        {
            swap(x, y);
        }
        edit(1, n, root, ns[ns[x].top].dfn, ns[x].dfn, k);
        x = ns[ns[x].top].fa;
    }
    if (ns[x].dep > ns[y].dep)
    {
        swap(x, y);
    }
    edit(1, n, root, ns[x].dfn, ns[y].dfn, k);
}
int path_search(int x, int y)
{
    int ans = 0;
    while (ns[x].top != ns[y].top)
    {
        if (ns[ns[x].top].dep < ns[ns[y].top].dep)
        {
            swap(x, y);
        }
        ans = (ans + search(1, n, root, ns[ns[x].top].dfn, ns[x].dfn)) % mod;
        x = ns[ns[x].top].fa;
    }
    if (ns[x].dep > ns[y].dep)
    {
        swap(x, y);
    }
    ans = (ans + search(1, n, root, ns[x].dfn, ns[y].dfn)) % mod;
    return ans;
}
int main()
{
    cin >> n >> m >> r >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ns[u].ways.push_back(v);
        ns[v].ways.push_back(u);
    }
    dfs1(r, r);
    dfs2(r, r);
    pos = 0;
    make_tree(1, n, root);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        int z;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> z;
            path_edit(x, y, z);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << path_search(x, y) << endl;
        }
        else if (op == 3)
        {
            cin >> x >> z;
            edit(1, n, root, ns[x].dfn, ns[x].dfn + ns[x].sz - 1, z);
        }
        else
        {
            cin >> x;
            cout << search(1, n, root, ns[x].dfn, ns[x].dfn + ns[x].sz - 1) << endl;
        }
    }
    return 0;
}