#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, id;
};
Node ns[200005];
int sz, a[200005];
long long res, ans[200005], cnt[200005];
bool cmp(Node a, Node b)
{
    if (a.l / sz == b.l / sz)
    {
        return a.r < b.r;
    }
    return a.l < b.l;
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
    int n = read(), m = read();
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        ns[i].l = read(), ns[i].r = read();
        ns[i].id = i;
    }
    sort(ns + 1, ns + m + 1, cmp);
    int st = 1, ed = 0;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            if (cnt[a[ed]] >= 2)
            {
                res += cnt[a[ed]] * (cnt[a[ed]] - 1) / 2;
            }
            cnt[a[ed]]++;
        }
        while (ed > ns[i].r)
        {
            cnt[a[ed]]--;
            if (cnt[a[ed]] >= 2)
            {
                res -= cnt[a[ed]] * (cnt[a[ed]] - 1) / 2;
            }
            ed--;
        }
        while (st < ns[i].l)
        {
            cnt[a[st]]--;
            if (cnt[a[st]] >= 2)
            {
                res -= cnt[a[st]] * (cnt[a[st]] - 1) / 2;
            }
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            if (cnt[a[st]] >= 2)
            {
                res += cnt[a[st]] * (cnt[a[st]] - 1) / 2;
            }
            cnt[a[st]]++;
        }
        ans[ns[i].id] = res;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}