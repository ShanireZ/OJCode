#include <cstdio>
#include <string>
using namespace std;
long long read()
{
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    long long ans = 0, t = 1;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + (ch - '0');
        ch = getchar();
    }
    return ans * t;
}
int n, m, pos, root;
long long nums[100005];
struct Node
{
    int lc, rc;
    long long tag, v;
};
Node ns[400005];
void pushdown(int now, int l, int r)
{
    if (ns[now].tag == 0)
    {
        return;
    }
    int mid = (l + r) / 2;
    ns[ns[now].lc].v += (mid - l + 1) * ns[now].tag;
    ns[ns[now].rc].v += (r - mid) * ns[now].tag;
    ns[ns[now].lc].tag += ns[now].tag, ns[ns[now].rc].tag += ns[now].tag;
    ns[now].tag = 0;
}
void update(int now)
{
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void makeTree(int &now, int l, int r) //! now当前节点编号 l节点左边界 r节点有边界
{
    now = ++pos;
    if (l == r)
    {
        ns[now].v = nums[l];
        return;
    }
    int mid = (l + r) / 2;
    makeTree(ns[now].lc, l, mid);
    makeTree(ns[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int x, int y, int k)
{
    pushdown(now, l, r);
    if (x <= l && y >= r)
    {
        ns[now].v += (r - l + 1) * k;
        ns[now].tag += k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid && l <= y)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y >= mid + 1 && x <= r)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    update(now);
}
long long querry(int now, int l, int r, int x, int y)
{
    pushdown(now, l, r);
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2;
    long long ans = 0;
    if (x <= mid && l <= y)
    {
        ans += querry(ns[now].lc, l, mid, x, y);
    }
    if (y >= mid + 1 && x <= r)
    {
        ans += querry(ns[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        nums[i] = read();
    }
    makeTree(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read(), y = read();
        if (opt == 1) // todo 修改
        {
            long long k = read();
            edit(root, 1, n, x, y, k);
        }
        else // todo 查询
        {
            printf("%lld\n", querry(root, 1, n, x, y));
        }
    }
    return 0;
}