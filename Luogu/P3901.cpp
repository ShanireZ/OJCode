#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int l, r, id;
};
Node ns[MX];
int a[MX], t[MX], g[MX], ans[MX], n, m;
bool cmp(Node a, Node b)
{
    if (g[a.l] == g[b.l])
    {
        return a.r < b.r;
    }
    return a.l < b.l;
}
int main()
{
    cin >> n >> m;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i;
    }
    sort(ns + 1, ns + m + 1, cmp);
    int st = 1, ed = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            t[a[ed]]++;
            cnt += (t[a[ed]] == 2);
        }
        while (ed > ns[i].r)
        {
            t[a[ed]]--;
            cnt -= (t[a[ed]] == 1);
            ed--;
        }
        while (st < ns[i].l)
        {
            t[a[st]]--;
            cnt -= (t[a[st]] == 1);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            t[a[st]]++;
            cnt += (t[a[st]] == 2);
        }
        ans[ns[i].id] = cnt;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << (ans[i] == 0 ? "Yes" : "No") << '\n';
    }
    return 0;
}
// TAG: 分块 莫队算法