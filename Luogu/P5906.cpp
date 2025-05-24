#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define MX 200005
int n, m, len, mpos, a[MX], ls[MX], fst[MX], lst[MX], ans[MX], rec[MX], bk[MX];
struct Node
{
    int l, r, id;
    bool operator<(const Node &oth) const
    {
        return bk[l] == bk[oth.l] ? r < oth.r : l < oth.l;
    }
};
Node ns[MX];
int main()
{
    cin >> n;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ls[i] = a[i], bk[i] = (i - 1) / len + 1;
    }
    sort(ls + 1, ls + 1 + n);
    mpos = unique(ls + 1, ls + 1 + n) - ls;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + mpos, a[i]) - ls;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + m);
    for (int i = 1; i <= m;)
    {
        if (bk[ns[i].l] == bk[ns[i].r])
        {
            int res = 0;
            for (int j = ns[i].l; j <= ns[i].r; j++)
            {
                int x = a[j];
                if (fst[x] == 0)
                {
                    fst[x] = j;
                }
                lst[x] = j, res = max(res, lst[x] - fst[x]);
            }
            for (int j = ns[i].l; j <= ns[i].r; j++)
            {
                int x = a[j];
                fst[x] = lst[x] = 0;
            }
            ans[ns[i].id] = res, i++;
            continue;
        }
        int l = bk[ns[i].l] * len + 1, r = l - 1, res = 0;
        do
        {
            while (r < ns[i].r)
            {
                int x = a[++r];
                if (fst[x] == 0)
                {
                    fst[x] = r;
                }
                lst[x] = r, res = max(res, lst[x] - fst[x]);
            }
            int nr = res, rpos = 0;
            while (l > ns[i].l)
            {
                int x = a[--l];
                if (lst[x] == 0)
                {
                    lst[x] = l, rec[++rpos] = x;
                }
                nr = max(nr, lst[x] - l);
            }
            for (int j = 1; j <= rpos; j++)
            {
                lst[rec[j]] = 0;
            }
            ans[ns[i].id] = nr, l = bk[ns[i].l] * len + 1, i++;
        } while (bk[ns[i - 1].l] == bk[ns[i].l]);
        memset(fst, 0, sizeof(fst)), memset(lst, 0, sizeof(lst));
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}