#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 250005
long long fac[MX], inv[MX], invn[MX], sum[505], mod = 998244353;
int a[MX], bk[MX], cnt[MX], ans[MX], t[505], read();
struct Node
{
    int l, r, x, id;
    bool operator<(const Node &oth) const
    {
        if (bk[l] != bk[oth.l])
        {
            return l < oth.l;
        }
        return bk[l] % 2 ? r < oth.r : r > oth.r;
    }
};
Node ns[MX];
long long qp(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y % 2 == 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod, y /= 2;
    }
    return res;
}
void add(int v)
{
    cnt[v]++, t[bk[v]]++;
    sum[bk[v]] = sum[bk[v]] * invn[cnt[v]] % mod;
}
void del(int v)
{
    sum[bk[v]] = sum[bk[v]] * cnt[v] % mod;
    cnt[v]--, t[bk[v]]--;
}
int main()
{
    int n = read(), q = read();
    fac[0] = fac[1] = invn[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        invn[i] = (mod - mod / i) * invn[mod % i] % mod;
    }
    inv[n] = qp(fac[n], mod - 2);
    for (int i = n; i > 0; i--)
    {
        inv[i - 1] = inv[i] * i % mod;
    }
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), bk[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= q; i++)
    {
        ns[i] = Node{read(), read(), read(), i};
    }
    sort(ns + 1, ns + q + 1), fill(sum + 1, sum + 1 + bk[n], 1);
    for (int i = 1, l = 1, r = 0; i <= q; i++)
    {
        while (l > ns[i].l)
        {
            add(a[--l]);
        }
        while (r < ns[i].r)
        {
            add(a[++r]);
        }
        while (l < ns[i].l)
        {
            del(a[l++]);
        }
        while (r > ns[i].r)
        {
            del(a[r--]);
        }
        int res = 1, tot = 0, x = ns[i].x;
        for (int j = 1; j < bk[x]; j++)
        {
            res = res * sum[j] % mod, tot += t[j];
        }
        for (int j = (bk[x] - 1) * sz + 1; j < x; j++)
        {
            res = res * inv[cnt[j]] % mod, tot += cnt[j];
        }
        ans[ns[i].id] = res * fac[tot] % mod;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%d\n", ans[i]);
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