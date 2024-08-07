#include <algorithm>
#include <iostream>
using namespace std;
#define MX 300005
struct Node
{
    int lc, rc;
    __int128 mxv, mnv, sum;
};
Node ns[MX * 2];
int v[MX], n, m, pos, root, cnt;
void update(int now)
{
    ns[now].mxv = max(ns[ns[now].lc].mxv, ns[ns[now].rc].mxv);
    ns[now].mnv = min(ns[ns[now].lc].mnv, ns[ns[now].rc].mnv);
    ns[now].sum = ns[ns[now].lc].sum + ns[ns[now].rc].sum;
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].mxv = ns[now].mnv = v[l];
        ns[now].sum = 1ll * v[l] * v[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    update(now);
}
void edit(int now, int l, int r, int x, int y)
{
    if (l == r)
    {
        v[l] = ns[now].mxv = ns[now].mnv = y;
        ns[now].sum = 1ll * y * y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y);
    }
    else
    {
        edit(ns[now].rc, mid + 1, r, x, y);
    }
    update(now);
}
Node query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now];
    }
    int mid = (l + r) >> 1;
    Node res = Node{0, 0, 0, 1000000000, 0};
    if (x <= mid)
    {
        Node tmp = query(ns[now].lc, l, mid, x, y);
        res.mxv = max(res.mxv, tmp.mxv), res.mnv = min(res.mnv, tmp.mnv);
        res.sum = res.sum + tmp.sum;
    }
    if (y > mid)
    {
        Node tmp = query(ns[now].rc, mid + 1, r, x, y);
        res.mxv = max(res.mxv, tmp.mxv), res.mnv = min(res.mnv, tmp.mnv);
        res.sum = res.sum + tmp.sum;
    }
    return res;
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
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        v[i] = read();
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read() ^ cnt, y = read() ^ cnt;
        if (opt == 1)
        {
            edit(root, 1, n, x, y);
        }
        else
        {
            __int128 k = read() ^ cnt;
            Node res = query(root, 1, n, x, y);
            if (res.mxv - res.mnv == k * (y - x) &&
                res.sum == (y - x + 1) * (6 * res.mnv * res.mnv + k * k * (y - x) * (y * 2 - x * 2 + 1) + 6 * k * res.mnv * (y - x)) / 6)
            {
                printf("Yes\n");
                cnt++;
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}