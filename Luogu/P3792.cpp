#include <algorithm>
#include <iostream>
using namespace std;
#define MX 500005
struct Node
{
    int lc, rc;
    long long mxv, mnv, sum2;
};
Node ns[MX * 2];
int v[MX], n, m, pos, root;
long long s2[25000005], mod = 999999937;
void update(int now)
{
    ns[now].mxv = max(ns[ns[now].lc].mxv, ns[ns[now].rc].mxv);
    ns[now].mnv = min(ns[ns[now].lc].mnv, ns[ns[now].rc].mnv);
    ns[now].sum2 = (ns[ns[now].lc].sum2 + ns[ns[now].rc].sum2) % mod;
}
void init(int &now, int l, int r)
{
    now = ++pos;
    if (l == r)
    {
        ns[now].mxv = ns[now].mnv = v[l];
        ns[now].sum2 = 1ll * v[l] * v[l] % mod;
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
        ns[now].sum2 = 1ll * y * y % mod;
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
        res.sum2 = (res.sum2 + tmp.sum2) % mod;
    }
    if (y > mid)
    {
        Node tmp = query(ns[now].rc, mid + 1, r, x, y);
        res.mxv = max(res.mxv, tmp.mxv), res.mnv = min(res.mnv, tmp.mnv);
        res.sum2 = (res.sum2 + tmp.sum2) % mod;
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
    cin.tie(0)->ios::sync_with_stdio(false);
    for (int i = 1; i <= 25000000; i++)
    {
        s2[i] = (s2[i - 1] + 1ll * i * i % mod) % mod;
    }
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        v[i] = read();
    }
    init(root, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt = read(), x = read(), y = read();
        if (opt == 1)
        {
            edit(root, 1, n, x, y);
        }
        else
        {
            Node res = query(root, 1, n, x, y);
            if (res.mxv - y == res.mnv - x && (s2[res.mxv] - s2[res.mnv - 1] + mod) % mod == res.sum2)
            {
                printf("damushen\n");
            }
            else
            {
                printf("yuanxing\n");
            }
        }
    }
    return 0;
}