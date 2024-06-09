#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, id;
};
Node ns[1000005];
int res, sz, ans[1000005], cnt[100005], a[100005];
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
    int n = read();
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int m = read();
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
            cnt[a[ed]]++;
            res += (cnt[a[ed]] % 2 == 0);
        }
        while (ed > ns[i].r)
        {
            cnt[a[ed]]--;
            res -= (cnt[a[ed]] % 2 == 1);
            ed--;
        }
        while (st < ns[i].l)
        {
            cnt[a[st]]--;
            res -= (cnt[a[st]] % 2 == 1);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            cnt[a[st]]++;
            res += (cnt[a[st]] % 2 == 0);
        }
        ans[ns[i].id] = res;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}