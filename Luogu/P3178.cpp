#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define maxsz 100005
long long read();
struct Node
{
    int dp, sz, head, fa, zson, dfn;
    long long w;
    vector<int> son;
};
Node ns[maxsz];
int trans[maxsz], cnt, segroot, root;
struct Seg
{
    int lc, rc;
    long long v, tag;
};
Seg seg[maxsz * 4];
void dfs1(int now, int dp)
{
    ns[now].dp = dp;
    ns[now].sz = 1;
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int son = ns[now].son[i];
        if (son == ns[now].fa)
        {
            continue;
        }
        ns[son].fa = now;
        dfs1(son, dp + 1);
        ns[now].sz += ns[son].sz;
        if (ns[ns[now].zson].sz < ns[son].sz)
        {
            ns[now].zson = son;
        }
    }
}
void dfs2(int now, int head)
{
    ns[now].head = head;
    ns[now].dfn = ++cnt;
    trans[cnt] = now;
    if (ns[now].zson == 0)
    {
        return;
    }
    dfs2(ns[now].zson, head);
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int son = ns[now].son[i];
        if (son == ns[now].zson || son == ns[now].fa)
        {
            continue;
        }
        dfs2(son, son);
    }
}
void update(int now)
{
    seg[now].v = seg[seg[now].lc].v + seg[seg[now].rc].v;
}
void pushdown(int now, int l, int r)
{
    int lc = seg[now].lc, rc = seg[now].rc, mid = (l + r) / 2;
    seg[lc].v += seg[now].tag * (mid - l + 1);
    seg[rc].v += seg[now].tag * (r - mid);
    seg[lc].tag += seg[now].tag, seg[rc].tag += seg[now].tag, seg[now].tag = 0;
}
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        seg[now].v = ns[trans[l]].w;
        return;
    }
    int mid = (l + r) / 2;
    init(seg[now].lc, l, mid);
    init(seg[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int x, int y, long long k)
{
    if (x <= l && y >= r)
    {
        seg[now].v += k * (r - l + 1);
        seg[now].tag += k;
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
    update(now);
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
        ans += query(seg[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += query(seg[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
long long pathquery(int x, int n)
{
    long long ans = 0;
    while (ns[x].head != root)
    {
        ans += query(segroot, 1, n, ns[ns[x].head].dfn, ns[x].dfn);
        x = ns[ns[x].head].fa;
    }
    ans += query(segroot, 1, n, 1, ns[x].dfn);
    return ans;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].w = read();
    }
    for (int i = 1; i < n; i++)
    {
        int a = read(), b = read();
        ns[a].son.push_back(b);
        ns[b].son.push_back(a);
    }
    cnt = 0, root = 1;
    dfs1(root, 1);
    dfs2(root, root);
    cnt = 0;
    init(segroot, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            long long a = read();
            edit(segroot, 1, n, ns[x].dfn, ns[x].dfn, a);
        }
        else if (op == 2)
        {
            long long a = read();
            edit(segroot, 1, n, ns[x].dfn, ns[x].dfn + ns[x].sz - 1, a);
        }
        else
        {
            printf("%lld\n", pathquery(x, n));
        }
    }
    return 0;
}
long long read()
{
    long long ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}