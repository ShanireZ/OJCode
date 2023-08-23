#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MX 200005
#define LC sgs[now].lc
#define RC sgs[now].rc
struct Edge
{
    int u, v, w;
};
Edge es[MX];
vector<int> to[MX];
struct Node
{
    int fa, dp, hd, sz, zson, dfn, w;
};
Node ns[MX];
struct Seg
{
    int lc, rc, vz, vf, tag, maxv, minv;
};
Seg sgs[MX * 4];
int ids[MX], npos, n, m, segroot, root = 1;
void dfs1(int now, int dp)
{
    ns[now].dp = dp, ns[now].sz = 1;
    for (int i : to[now])
    {
        int nxt = es[i].u + es[i].v - now, w = es[i].w;
        if (nxt != ns[now].fa)
        {
            ns[nxt].fa = now, ns[nxt].w = w;
            dfs1(nxt, dp + 1);
            ns[now].sz += ns[nxt].sz;
            if (ns[nxt].sz > ns[ns[now].zson].sz)
            {
                ns[now].zson = nxt;
            }
        }
    }
}
void dfs2(int now, int hd)
{
    ns[now].hd = hd, ns[now].dfn = ++npos;
    ids[npos] = now;
    if (ns[now].zson)
    {
        dfs2(ns[now].zson, hd);
    }
    for (int i : to[now])
    {
        int nxt = es[i].u + es[i].v - now;
        if (nxt != ns[now].fa && nxt != ns[now].zson)
        {
            dfs2(nxt, nxt);
        }
    }
}
void update(int now)
{
    sgs[now].maxv = max(sgs[LC].maxv, sgs[RC].maxv);
    sgs[now].minv = min(sgs[LC].minv, sgs[RC].minv);
    sgs[now].vz = sgs[LC].vz + sgs[RC].vz, sgs[now].vf = sgs[LC].vf + sgs[RC].vf;
}
void initsg(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        if (ns[ids[l]].w >= 0)
        {
            sgs[now].vz = ns[ids[l]].w;
        }
        else
        {
            sgs[now].vf = ns[ids[l]].w;
        }
        sgs[now].maxv = sgs[now].minv = ns[ids[l]].w;
        return;
    }
    int mid = (l + r) / 2;
    initsg(LC, l, mid), initsg(RC, mid + 1, r);
    update(now);
}
void pushdown(int now)
{
    if (sgs[now].tag)
    {
        sgs[LC].tag = !sgs[LC].tag, sgs[RC].tag = !sgs[RC].tag;
        swap(sgs[LC].vz, sgs[LC].vf), swap(sgs[RC].vz, sgs[RC].vf);
        sgs[LC].vz *= -1, sgs[LC].vf *= -1, sgs[RC].vz *= -1, sgs[RC].vf *= -1;
        swap(sgs[LC].maxv, sgs[LC].minv), swap(sgs[RC].maxv, sgs[RC].minv);
        sgs[LC].maxv *= -1, sgs[LC].minv *= -1, sgs[RC].maxv *= -1, sgs[RC].minv *= -1;
        sgs[now].tag = 0;
    }
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        if (k == 0x3f3f3f3f)
        {
            sgs[now].tag = !sgs[now].tag;
            swap(sgs[now].vz, sgs[now].vf), swap(sgs[now].maxv, sgs[now].minv);
            sgs[now].vz *= -1, sgs[now].vf *= -1, sgs[now].maxv *= -1, sgs[now].minv *= -1;
        }
        else
        {
            if (k >= 0)
            {
                sgs[now].vz = k, sgs[now].vf = 0;
            }
            else
            {
                sgs[now].vz = 0, sgs[now].vf = k;
            }
            sgs[now].maxv = sgs[now].minv = k;
        }
        return;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, k);
    }
    update(now);
}
int query(int now, int l, int r, int x, int y, int opt)
{
    if (x <= l && y >= r)
    {
        if (opt == 1)
        {
            return sgs[now].vz + sgs[now].vf;
        }
        else if (opt == 2)
        {
            return sgs[now].maxv;
        }
        else
        {
            return sgs[now].minv;
        }
    }
    pushdown(now);
    int mid = (l + r) / 2, ans = 0;
    if (opt == 1)
    {
        if (x <= mid)
        {
            ans += query(LC, l, mid, x, y, opt);
        }
        if (y > mid)
        {
            ans += query(RC, mid + 1, r, x, y, opt);
        }
    }
    else if (opt == 2)
    {
        ans = -0x3f3f3f3f;
        if (x <= mid)
        {
            ans = max(ans, query(LC, l, mid, x, y, opt));
        }
        if (y > mid)
        {
            ans = max(ans, query(RC, mid + 1, r, x, y, opt));
        }
    }
    else
    {
        ans = 0x3f3f3f3f;
        if (x <= mid)
        {
            ans = min(ans, query(LC, l, mid, x, y, opt));
        }
        if (y > mid)
        {
            ans = min(ans, query(RC, mid + 1, r, x, y, opt));
        }
    }
    return ans;
}
int findAns(int a, int b, int opt)
{
    int ans = 0;
    if (opt == 2)
    {
        ans = -0x3f3f3f3f;
    }
    else if (opt == 3)
    {
        ans = 0x3f3f3f3f;
    }
    while (ns[a].hd != ns[b].hd)
    {
        if (ns[ns[a].hd].dp < ns[ns[b].hd].dp)
        {
            swap(a, b);
        }
        if (opt == 0)
        {
            edit(segroot, 1, n, ns[ns[a].hd].dfn, ns[a].dfn, 0x3f3f3f3f);
        }
        else if (opt == 1)
        {
            ans += query(segroot, 1, n, ns[ns[a].hd].dfn, ns[a].dfn, opt);
        }
        else if (opt == 2)
        {
            ans = max(ans, query(segroot, 1, n, ns[ns[a].hd].dfn, ns[a].dfn, opt));
        }
        else
        {
            ans = min(ans, query(segroot, 1, n, ns[ns[a].hd].dfn, ns[a].dfn, opt));
        }
        a = ns[ns[a].hd].fa;
    }
    if (a == b)
    {
        return ans;
    }
    if (ns[a].dp < ns[b].dp)
    {
        swap(a, b);
    }
    if (opt == 0)
    {
        edit(segroot, 1, n, ns[b].dfn + 1, ns[a].dfn, 0x3f3f3f3f);
    }
    else if (opt == 1)
    {
        ans += query(segroot, 1, n, ns[b].dfn + 1, ns[a].dfn, opt);
    }
    else if (opt == 2)
    {
        ans = max(ans, query(segroot, 1, n, ns[b].dfn + 1, ns[a].dfn, opt));
    }
    else
    {
        ans = min(ans, query(segroot, 1, n, ns[b].dfn + 1, ns[a].dfn, opt));
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        to[u].push_back(i), to[v].push_back(i);
        es[i].u = u, es[i].v = v, es[i].w = w;
    }
    dfs1(root, 1), dfs2(root, root);
    npos = 0, initsg(segroot, 1, n);
    cin >> m;
    while (m--)
    {
        string opt;
        int u, v;
        cin >> opt >> u >> v;
        if (opt == "C")
        {
            int a = es[u].u, b = es[u].v;
            if (ns[b].fa == a)
            {
                swap(a, b);
            }
            edit(segroot, 1, n, ns[a].dfn, ns[a].dfn, v);
        }
        else if (opt == "N")
        {
            findAns(u + 1, v + 1, 0);
        }
        else if (opt == "SUM")
        {
            cout << findAns(u + 1, v + 1, 1) << endl;
        }
        else if (opt == "MAX")
        {
            cout << findAns(u + 1, v + 1, 2) << endl;
        }
        else
        {
            cout << findAns(u + 1, v + 1, 3) << endl;
        }
    }
    return 0;
}
// TAG: 树链剖分 重链剖分 LCA 线段树 边权转点权 路径不包含LCA点权