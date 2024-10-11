#include <algorithm>
#include <iostream>
using namespace std;
int a[10005], vis[1000005], prim[1000005], T, pos, npos, root, read();
struct Node
{
    int lc, rc, v, tag;
};
Node ns[20005];
void init(int &now, int l, int r)
{
    now = ++npos;
    ns[now].tag = -1;
    if (l == r)
    {
        ns[now].v = !vis[a[l]];
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void pushdown(int now, int l, int r)
{
    if (ns[now].tag != -1)
    {
        int mid = (l + r) >> 1;
        ns[ns[now].lc].v = ns[now].tag * (mid - l + 1);
        ns[ns[now].rc].v = ns[now].tag * (r - mid);
        ns[ns[now].lc].tag = ns[ns[now].rc].tag = ns[now].tag;
        ns[now].tag = -1;
    }
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].v = k * (r - l + 1);
        ns[now].tag = k;
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
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pushdown(now, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid)
    {
        res += query(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        res += query(ns[now].rc, mid + 1, r, x, y);
    }
    return res;
}
int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 1000000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    T = read();
    for (int id = 1; id <= T; id++)
    {
        printf("Case %d:\n", id);
        int n = read(), q = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }
        root = npos = 0;
        init(root, 1, n);
        while (q--)
        {
            int op = read(), l = read(), r = read();
            if (op == 0)
            {
                int k = read();
                edit(root, 1, n, l, r, !vis[k]);
            }
            else
            {
                printf("%d\n", query(root, 1, n, l, r));
            }
        }
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}