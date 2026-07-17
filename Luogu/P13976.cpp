#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 300005
long long a[MX], ex[555], sum[555], n, sz, m, opt, l, r, c, kl, kr;
int k(int x)
{
    return (x - 1) / sz + 1;
}
int main()
{
    cin >> n;
    sz = pow(n, 0.5);
    m = (n + sz - 1) / sz;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[k(i)] += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> opt >> l >> r >> c;
        kl = k(l), kr = k(r);
        if (opt == 0)
        {
            if (kl == kr)
            {
                for (int j = l; j <= r; j++)
                {
                    a[j] += c, sum[kl] += c;
                }
            }
            else
            {
                for (int j = l; j <= kl * sz; j++)
                {
                    a[j] += c, sum[kl] += c;
                }
                for (int j = kl + 1; j < kr; j++)
                {
                    ex[j] += c;
                }
                for (int j = (kr - 1) * sz + 1; j <= r; j++)
                {
                    a[j] += c, sum[kr] += c;
                }
            }
        }
        else
        {
            cout << a[r] + ex[kr] << '\n';
        }
    }
    return 0;
}