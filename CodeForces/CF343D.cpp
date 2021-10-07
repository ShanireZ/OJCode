#include <iostream>
#include <vector>
using namespace std;
int read();
struct Node
{
    int fa, zson, head, size, dfn, deep;
    vector<int> link;
};
struct Seg
{
    int lc, rc, v, tag;
    //tag -1无操作 0清零 1赋值1
};
Node ns[500005];
Seg seg[2000005];
int root = 1, segroot, pos, n, m;
void dfs1(int now, int dp)
{
    ns[now].deep = dp;
    ns[now].size = 1;
    for (int i = 0; i < ns[now].link.size(); i++)
    {
        int to = ns[now].link[i];
        if (to == ns[now].fa)
        {
            continue;
        }
        ns[to].fa = now;
        dfs1(to, dp + 1);
        ns[now].size += ns[to].size;
        if (ns[ns[now].zson].size < ns[to].size)
        {
            ns[now].zson = to;
        }
    }
}
void dfs2(int now, int head)
{
    ns[now].head = head;
    ns[now].dfn = ++pos;
    if (ns[now].zson == 0)
    {
        return;
    }
    dfs2(ns[now].zson, head);
    for (int i = 0; i < ns[now].link.size(); i++)
    {
        int to = ns[now].link[i];
        if (to == ns[now].zson || to == ns[now].fa)
        {
            continue;
        }
        dfs2(to, to);
    }
}
void pushdown(int now, int l, int r)
{
    if (seg[now].tag == -1)
    {
        return;
    }
    int lc = seg[now].lc, rc = seg[now].rc, tag = seg[now].tag;
    seg[lc].v = seg[rc].v = seg[lc].tag = seg[rc].tag = tag;
    seg[now].tag = -1;
}
void init(int &now, int l, int r)
{
    now = ++pos;
    seg[now].tag = -1;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    init(seg[now].lc, l, mid);
    init(seg[now].rc, mid + 1, r);
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && r <= y)
    {
        seg[now].v = seg[now].tag = k;
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
}
int query(int now, int l, int r, int k)
{
    if (l == r)
    {
        return seg[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) / 2, ans = 0;
    if (k <= mid)
    {
        ans = query(seg[now].lc, l, mid, k);
    }
    else if (k > mid)
    {
        ans = query(seg[now].rc, mid + 1, r, k);
    }
    return ans;
}
int main()
{
    n = read();
    for (int i = 1; i <= n - 1; i++)
    {
        int x = read(), y = read();
        ns[x].link.push_back(y);
        ns[y].link.push_back(x);
    }
    dfs1(root, 1);
    dfs2(root, root);
    pos = 0;
    init(segroot, 1, n);
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int op = read(), p = read();
        if (op == 1)
        {
            edit(segroot, 1, n, ns[p].dfn, ns[p].dfn + ns[p].size - 1, 1);
        }
        else if (op == 2)
        {
            while (ns[p].head != 1)
            {
                edit(segroot, 1, n, ns[ns[p].head].dfn, ns[p].dfn, 0);
                p = ns[ns[p].head].fa;
            }
            edit(segroot, 1, n, 1, ns[p].dfn, 0);
        }
        else
        {
            printf("%d\n", query(segroot, 1, n, ns[p].dfn));
        }
    }
}
int read()
{
    int ans = 0, type = 1;
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