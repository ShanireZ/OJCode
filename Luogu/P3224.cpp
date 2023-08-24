#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
    int lc, rc, v;
};
Node ns[MX * 40];
int read(), root[MX], g[MX], rks[MX], npos, n, m, q;
int dfn(int now)
{
    return (now == g[now] ? now : g[now] = dfn(g[now]));
}
void init(int &now, int l, int r, int p)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].v = 1;
        return;
    }
    int mid = (l + r) / 2;
    p <= mid ? init(LC, l, mid, p) : init(RC, mid + 1, r, p);
    ns[now].v = ns[LC].v + ns[RC].v;
}
void merge(int &now, int sup, int l, int r)
{
    if (now == 0 || sup == 0)
    {
        now = now + sup;
        return;
    }
    if (l == r)
    {
        ns[now].v += ns[sup].v;
        return;
    }
    int mid = (l + r) / 2;
    merge(LC, ns[sup].lc, l, mid), merge(RC, ns[sup].rc, mid + 1, r);
    ns[now].v = ns[LC].v + ns[RC].v;
}
int query(int now, int l, int r, int k)
{
    if (l == r)
    {
        return rks[l];
    }
    int mid = (l + r) / 2;
    return (ns[LC].v >= k ? query(LC, l, mid, k) : query(RC, mid + 1, r, k - ns[LC].v));
}
void addEdge(int x, int y)
{
    if (x != y)
    {
        merge(root[x], root[y], 1, n), g[y] = x;
    }
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        init(root[i], 1, n, x), g[i] = i, rks[x] = i;
    }
    while (m--)
    {
        int x = read(), y = read();
        addEdge(dfn(x), dfn(y));
    }
    q = read();
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'Q')
        {
            int x = read(), y = read();
            x = dfn(x);
            printf("%d\n", y > ns[root[x]].v ? -1 : query(root[x], 1, n, y));
        }
        else
        {
            int x = read(), y = read();
            addEdge(dfn(x), dfn(y));
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
// TAG: 线段树合并