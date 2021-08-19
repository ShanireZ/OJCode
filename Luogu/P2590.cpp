#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define maxsz 30005
int read();
struct Node
{
    int fa, zson, sz, head, v, dfn, dp;
    vector<int> son;
};
Node ns[maxsz];
struct Seg
{
    int sumv, maxv, lc, rc;
};
Seg sg[maxsz * 4];
int trans[maxsz], cnt, root, n;
void update(int now)
{
    int lc = sg[now].lc, rc = sg[now].rc;
    sg[now].sumv = sg[lc].sumv + sg[rc].sumv;
    sg[now].maxv = max(sg[lc].maxv, sg[rc].maxv);
}
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        sg[now].maxv = sg[now].sumv = ns[trans[l]].v;
        return;
    }
    int mid = (l + r) / 2;
    init(sg[now].lc, l, mid);
    init(sg[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int p, int v)
{
    if (l == r)
    {
        sg[now].sumv = sg[now].maxv = v;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid)
    {
        edit(sg[now].lc, l, mid, p, v);
    }
    else
    {
        edit(sg[now].rc, mid + 1, r, p, v);
    }
    update(now);
}
int queryV(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return sg[now].sumv;
    }
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
    {
        ans += queryV(sg[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += queryV(sg[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
int queryMX(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return sg[now].maxv;
    }
    int mid = (l + r) / 2, ans = -2e9;
    if (x <= mid)
    {
        ans = max(ans, queryMX(sg[now].lc, l, mid, x, y));
    }
    if (y > mid)
    {
        ans = max(ans, queryMX(sg[now].rc, mid + 1, r, x, y));
    }
    return ans;
}
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
int pathV(int x, int y)
{
    int ans = 0;
    while (ns[x].head != ns[y].head)
    {
        if (ns[ns[x].head].dp < ns[ns[y].head].dp)
        {
            swap(x, y);
        }
        ans += queryV(root, 1, n, ns[ns[x].head].dfn, ns[x].dfn);
        x = ns[ns[x].head].fa;
    }
    if (ns[x].dp < ns[y].dp)
    {
        swap(x, y);
    }
    ans += queryV(root, 1, n, ns[y].dfn, ns[x].dfn);
    return ans;
}
int pathMX(int x, int y)
{
    int ans = -2e9;
    while (ns[x].head != ns[y].head)
    {
        if (ns[ns[x].head].dp < ns[ns[y].head].dp)
        {
            swap(x, y);
        }
        ans = max(ans, queryMX(root, 1, n, ns[ns[x].head].dfn, ns[x].dfn));
        x = ns[ns[x].head].fa;
    }
    if (ns[x].dp < ns[y].dp)
    {
        swap(x, y);
    }
    ans = max(ans, queryMX(root, 1, n, ns[y].dfn, ns[x].dfn));
    return ans;
}
int main()
{
    sg[0].maxv = -2e9;
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        ns[u].son.push_back(v);
        ns[v].son.push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].v = read();
    }
    dfs1(1, 1);
    dfs2(1, 1);
    cnt = 0;
    init(root, 1, n);
    int q = read();
    string op;
    op.resize(10);
    for (int i = 1; i <= q; i++)
    {
        scanf("%s", &op[0]);
        int u = read(), v = read();
        if (op[1] == 'H') //修改
        {
            edit(root, 1, n, ns[u].dfn, v);
        }
        else if (op[1] == 'S') //求和
        {
            printf("%d\n", pathV(u, v));
        }
        else //求最值
        {
            printf("%d\n", pathMX(u, v));
        }
    }
    return 0;
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