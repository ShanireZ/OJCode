#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, id;
};
Node ns[10005];
int n, c, m, a[300005], g[300005], cnt[10005], ans[10005];
bool cmp(Node x, Node y)
{
    if (g[x.l] == g[y.l])
    {
        return x.r < y.r;
    }
    return x.l < y.l;
}
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i;
    }
    int sz = n / sqrt(m);
    for (int i = 1; i <= n; i++)
    {
        g[i] = (i - 1) / sz + 1;
    }
    sort(ns + 1, ns + m + 1, cmp);
    int st, ed, maxc, res, p = 1;
    while (p <= m)
    {
        memset(cnt, 0, sizeof(cnt));
        if (g[ns[p].l] == g[ns[p].r])
        {
            maxc = 0, res = 0;
            for (int i = ns[p].l; i <= ns[p].r; i++)
            {
                cnt[a[i]]++;
                if (cnt[a[i]] > maxc)
                {
                    maxc = cnt[a[i]];
                    res = a[i];
                }
            }
            if (ns[p].r - ns[p].l + 1 < maxc * 2)
            {
                ans[ns[p].id] = res;
            }
            p++;
            continue;
        }
        ed = g[ns[p].l] * sz;
        st = ed + 1, maxc = 0, res = 0;
        do
        {
            while (ed < ns[p].r)
            {
                ed++;
                cnt[a[ed]]++;
                if (cnt[a[ed]] > maxc)
                {
                    maxc = cnt[a[ed]];
                    res = a[ed];
                }
            }
            int nowc = maxc, nowr = res;
            while (st > ns[p].l)
            {
                st--;
                cnt[a[st]]++;
                if (cnt[a[st]] > nowc)
                {
                    nowc = cnt[a[st]];
                    nowr = a[st];
                }
            }
            if (ns[p].r - ns[p].l + 1 < nowc * 2)
            {
                ans[ns[p].id] = nowr;
            }
            while (st < g[ns[p].l] * sz + 1) // 回滚st
            {
                cnt[a[st]]--;
                st++;
            }
            p++;
        } while (p <= m && g[ns[p].l] == g[ns[p - 1].l]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 0)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes " << ans[i] << '\n';
        }
    }
    return 0;
}