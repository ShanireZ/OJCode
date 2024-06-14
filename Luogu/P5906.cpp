#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 200005
int ans[MX], a[MX], ls[MX], g[MX], fst[MX], lst[MX], rec[MX * 2];
struct Node
{
    int id, l, r;
};
Node ns[MX];
bool cmp(Node x, Node y)
{
    return (g[x.l] == g[y.l]) ? x.r < y.r : x.l < y.l;
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
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        ls[i] = a[i] = read();
    }
    sort(ls + 1, ls + 1 + n);
    int len = unique(ls + 1, ls + 1 + n) - ls;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + len, a[i]) - ls;
    }
    int m = read(), sz = max(1, int(n / sqrt(m)));
    for (int i = 1; i <= n; i++)
    {
        g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        ns[i].l = read(), ns[i].r = read(), ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + m, cmp);
    int p = 1;
    while (p <= m)
    {
        int res = 0, rpos = 0;
        if (g[ns[p].l] == g[ns[p].r])
        {
            for (int j = ns[p].l; j <= ns[p].r; j++)
            {
                if (fst[a[j]] == 0)
                {
                    fst[a[j]] = j, rec[++rpos] = a[j];
                }
                res = max(res, j - fst[a[j]]);
            }
            ans[ns[p].id] = res, p++;
            for (int j = 1; j <= rpos; j++)
            {
                fst[rec[j]] = 0;
            }
        }
        else
        {
            int st = g[ns[p].l] * sz + 1, ed = g[ns[p].l] * sz;
            do
            {
                while (ed < ns[p].r)
                {
                    ed++;
                    if (fst[a[ed]] == 0)
                    {
                        fst[a[ed]] = ed, rec[++rpos] = a[ed];
                    }
                    res = max(res, ed - fst[a[ed]]), lst[a[ed]] = ed;
                }
                int nowr = res, nowp = rpos;
                while (st > ns[p].l)
                {
                    st--;
                    if (lst[a[st]] == 0)
                    {
                        lst[a[st]] = st, rec[++nowp] = a[st];
                    }
                    nowr = max(nowr, lst[a[st]] - st);
                }
                ans[ns[p].id] = nowr, st = g[ns[p].l] * sz + 1, p++;
                while (nowp > rpos)
                {
                    lst[rec[nowp]] = 0;
                    nowp--;
                }
            } while (p <= m && g[ns[p].l] == g[ns[p - 1].l]);
            for (int j = 1; j <= rpos; j++)
            {
                fst[rec[j]] = lst[rec[j]] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
// TAG: 回滚莫队