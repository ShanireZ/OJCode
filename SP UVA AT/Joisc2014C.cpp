#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define MX 110000
int n, m, sz, cnt, now = 1, bl[MX];
long long t[MX], ans[MX], ls[MX], a[MX];
struct Quest
{
    int l, r, id;
    bool operator<(const Quest oth) const
    {
        if (bl[l] == bl[oth.l])
        {
            return r < oth.r;
        }
        return bl[l] < bl[oth.l];
    }
};
Quest q[MX];
void lsh()
{
    sort(ls + 1, ls + 1 + n);
    cnt = unique(ls + 1, ls + 1 + n) - (ls + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + 1 + cnt, a[i]) - ls;
    }
}
void bm(int pos)
{
    memset(t, 0, sizeof(t));
    int std = sz * (pos + 1) + 1;
    int l = std, r = std - 1;
    long long ansnow = 0, ansstd = 0;
    while (bl[q[now].l] == pos)
    {
        while (q[now].r < r)
        {
            t[a[r--]] -= 1;
        }
        while (q[now].r > r)
        {
            t[a[++r]] += 1;
            ansstd = max(ansstd, t[a[r]] * ls[a[r]]);
        }
        ansnow = ansstd;
        while (q[now].l < l)
        {
            t[a[--l]] += 1;
            ansnow = max(ansnow, t[a[l]] * ls[a[l]]);
        }
        while (std > l)
        {
            t[a[l++]] -= 1;
        }
        ans[q[now++].id] = ansnow;
    }
}
int main()
{
    cin >> n >> m;
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ls[i] = a[i], bl[i] = (i - 1) / sz;
    }
    lsh();
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (int i = 0; i <= bl[n]; i++)
    {
        bm(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
// TAG: 分块 回滚莫队