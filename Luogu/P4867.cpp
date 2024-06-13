#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
struct Node
{
    int l, r, a, b, id;
};
Node ns[MX * 10];
int ans[MX * 10], g[MX], a[MX], t[MX], res[325]; // 值域分块
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
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r >> ns[i].a >> ns[i].b;
        ns[i].id = i;
    }
    sort(ns + 1, ns + m + 1, cmp);
    int st = 1, ed = 0;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            int x = a[ed];
            t[x]++;
            res[g[x]] += (t[x] == 1);
        }
        while (ed > ns[i].r)
        {
            int x = a[ed];
            t[x]--;
            res[g[x]] -= (t[x] == 0);
            ed--;
        }
        while (st < ns[i].l)
        {
            int x = a[st];
            t[x]--;
            res[g[x]] -= (t[x] == 0);
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            int x = a[st];
            t[x]++;
            res[g[x]] += (t[x] == 1);
        }
        if (g[ns[i].a] == g[ns[i].b])
        {
            for (int j = ns[i].a; j <= ns[i].b; j++)
            {
                ans[ns[i].id] += (t[j] > 0);
            }
            continue;
        }
        for (int j = ns[i].a; j <= g[ns[i].a] * sz; j++)
        {
            ans[ns[i].id] += (t[j] > 0);
        }
        for (int j = g[ns[i].a] + 1; j < g[ns[i].b]; j++)
        {
            ans[ns[i].id] += res[j];
        }
        for (int j = ns[i].b; j > (g[ns[i].b] - 1) * sz; j--)
        {
            ans[ns[i].id] += (t[j] > 0);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
// TAG: 莫队 值域分块 根号分治