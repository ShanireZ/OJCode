#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Node
{
    int lc, rc;
    long long tag, minv;
};
Node ns[1000005];
long long a[1000005];
int pos, root;
void update(int now)
{
    int lc = ns[now].lc, rc = ns[now].rc;
    ns[now].minv = min(ns[lc].minv, ns[rc].minv);
}
void pushdown(int now)
{
    int lc = ns[now].lc, rc = ns[now].rc, tag = ns[now].tag;
    if (tag == 0)
    {
        return;
    }
    ns[lc].tag += tag, ns[rc].tag += tag;
    ns[lc].minv -= tag, ns[rc].minv -= tag;
    ns[now].tag = 0;
}
void edit(int now, int l, int r, int k, int x, int y)
{
    if (x <= l && y >= r)
    {
        ns[now].tag += k;
        ns[now].minv -= k;
        return;
    }
    pushdown(now);
    int mid = (l + r) / 2;
    if (x <= mid && y >= l)
    {
        edit(ns[now].lc, l, mid, k, x, y);
    }
    if (y > mid and x <= r)
    {
        edit(ns[now].rc, mid + 1, r, k, x, y);
    }
    update(now);
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].minv = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
    update(now);
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int d = read(), s = read(), t = read();
        edit(root, 1, n, d, s, t);
        if (ns[root].minv < 0)
        {
            printf("-1\n%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}