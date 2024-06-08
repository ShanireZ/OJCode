#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 500005
struct Node
{
    int l, r, id;
};
Node ns[MX];
int a[MX], g[MX], cnt[MX], ans[MX], all[MX];
bool cmp(Node a, Node b)
{
    if (g[a.l] == g[b.l])
    {
        return a.r < b.r;
    }
    return g[a.l] < g[b.l];
}
int main()
{
    int n, m;
    cin >> n >> m;
    int sz = sqrt(n), pos = 0, gpos = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all[i] = a[i];
        if (pos == sz)
        {
            gpos++, pos = 0;
        }
        g[i] = gpos, pos++;
    }
    sort(all + 1, all + 1 + n);
    int ls = unique(all + 1, all + 1 + n) - all - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all + 1, all + 1 + ls, a[i]) - all;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + m, cmp);
    int st = 1, ed = 0, now = 0;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            int x = a[ed];
            cnt[x]++;
            now += (cnt[x] == 2), now -= (cnt[x] == 3);
        }
        while (ed > ns[i].r)
        {
            int x = a[ed];
            cnt[x]--;
            now += (cnt[x] == 2), now -= (cnt[x] == 1);
            ed--;
        }
        while (st < ns[i].l)
        {
            int x = a[st];
            cnt[x]--;
            now += (cnt[x] == 2), now -= (cnt[x] == 1);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            int x = a[st];
            cnt[x]++;
            now += (cnt[x] == 2), now -= (cnt[x] == 3);
        }
        ans[ns[i].id] = now;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}