#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, id;
};
Node ns[500005];
int cnt[500005], a[500005], ans[500005], sz;
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
    int st = 1, ed = 0, res = 0;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            cnt[a[ed]]++;
            res += (cnt[a[ed]] == 1);
        }
        while (ed > ns[i].r)
        {
            cnt[a[ed]]--;
            res -= (cnt[a[ed]] == 0);
            ed--;
        }
        while (st < ns[i].l)
        {
            cnt[a[st]]--;
            res -= (cnt[a[st]] == 0);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            cnt[a[st]]++;
            res += (cnt[a[st]] == 1);
        }
        ans[ns[i].id] = res;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}