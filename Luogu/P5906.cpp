#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 200005
int ans[MX], a[MX], ls[MX], g[MX], fst[MX], lst[MX], rec[MX * 2], n, m, sz;
struct Node
{
    int id, l, r;
};
Node ns[MX];
bool cmp(Node x, Node y)
{
    return (g[x.l] == g[y.l]) ? x.r < y.r : x.l < y.l;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ls[i] = a[i];
    }
    sort(ls + 1, ls + 1 + n);
    int len = unique(ls + 1, ls + 1 + n) - ls;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + len, a[i]) - ls;
    }
    cin >> m;
    sz = max(1, (int)sqrt(n));
    for (int i = 1; i <= n; i++)
    {
        g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + m, cmp);
    int now = 1;
    while (now <= m)
    {
        int res = 0, rpos = 0;
        if (g[ns[now].l] == g[ns[now].r])
        {
            for (int j = ns[now].l; j <= ns[now].r; j++)
            {
                if (fst[a[j]] == 0)
                {
                    fst[a[j]] = j, rec[++rpos] = a[j];
                }
                res = max(res, j - fst[a[j]]);
            }
            ans[ns[now].id] = res, now++;
            for (int j = 1; j <= rpos; j++)
            {
                fst[rec[j]] = 0;
            }
        }
        else
        {
            int l = g[ns[now].l] * sz + 1, r = g[ns[now].l] * sz;
            do
            {
                while (r < ns[now].r)
                {
                    r++;
                    if (fst[a[r]] == 0)
                    {
                        fst[a[r]] = r, rec[++rpos] = a[r];
                    }
                    res = max(res, r - fst[a[r]]), lst[a[r]] = r;
                }
                int nr = res, bpos = rpos;
                while (l > ns[now].l)
                {
                    l--;
                    if (lst[a[l]] == 0)
                    {
                        lst[a[l]] = l, rec[++bpos] = a[l];
                    }
                    nr = max(nr, lst[a[l]] - l);
                }
                ans[ns[now].id] = nr, l = g[ns[now].l] * sz + 1, now++;
                for (int j = rpos + 1; j <= bpos; j++)
                {
                    lst[rec[j]] = 0;
                }
            } while (now <= m && g[ns[now].l] == g[ns[now - 1].l]);
            for (int j = 1; j <= rpos; j++)
            {
                fst[rec[j]] = lst[rec[j]] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}