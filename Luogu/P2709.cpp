#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, lk, id;
};
Node ns[100005];
int n, q, k, sz, a[100005], t[100005];
long long ans[100005];
bool cmp(Node a, Node b)
{
    return a.lk == b.lk ? a.r < b.r : a.lk < b.lk;
}
int cb(int x)
{
    return (x - 1) / sz + 1;
}
int main()
{
    cin >> n >> q >> k;
    sz = pow(n, 0.5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i, ns[i].lk = cb(ns[i].l);
    }
    sort(ns + 1, ns + 1 + q, cmp);
    for (int lk = 1, i = 1; lk <= cb(n); lk++)
    {
        fill(t + 1, t + 1 + k, 0);
        int l = ns[i].l, r = ns[i].l - 1;
        long long res = 0;
        while (ns[i].lk == lk)
        {
            while (r < ns[i].r)
            {
                t[a[++r]]++;
                res += t[a[r]] * 2 - 1;
            }
            while (l < ns[i].l)
            {
                t[a[l]]--;
                res += -t[a[l]] * 2 - 1;
                l++;
            }
            while (l > ns[i].l)
            {
                t[a[--l]]++;
                res += t[a[l]] * 2 - 1;
            }
            ans[ns[i++].id] = res;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}