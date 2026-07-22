#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    long long l, r, lk, id;
};
Node ns[50005];
long long n, m, sz, a[50005], t[50005], fz[50005], fm[50005];
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
    cin >> n >> m;
    sz = pow(n, 0.5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i, ns[i].lk = cb(ns[i].l);
        fm[i] = (ns[i].r - ns[i].l + 1) * (ns[i].r - ns[i].l);
    }
    sort(ns + 1, ns + 1 + m, cmp);
    for (int k = 1, i = 1; k <= cb(n); k++)
    {
        fill(t + 1, t + 1 + n, 0);
        int l = ns[i].l, r = ns[i].l - 1;
        long long res = 0;
        while (ns[i].lk == k)
        {
            while (r < ns[i].r)
            {
                r++;
                t[a[r]]++;
                if (t[a[r]] >= 2)
                {
                    res += 2 * (t[a[r]] - 1);
                }
            }
            while (l < ns[i].l)
            {
                t[a[l]]--;
                if (t[a[l]] >= 1)
                {
                    res -= 2 * t[a[l]];
                }
                l++;
            }
            while (l > ns[i].l)
            {
                l--;
                t[a[l]]++;
                if (t[a[l]] >= 2)
                {
                    res += 2 * (t[a[l]] - 1);
                }
            }
            fz[ns[i].id] = res;
            i++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (fz[i] == 0)
        {
            cout << "0/1" << "\n";
        }
        else
        {
            long long g = __gcd(fz[i], fm[i]);
            cout << fz[i] / g << "/" << fm[i] / g << "\n";
        }
    }
    return 0;
}