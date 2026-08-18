#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define mod 10007
long long n, k, fn, a[300005], c[555], p[555];
inline int f(int x)
{
    return (x - 1) / k;
}
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] %= mod;
    }
    k = sqrt(n), fn = f(n);
    for (int i = 0; i <= fn; i++)
    {
        c[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        long long opt, l, r, w;
        scanf("%lld%lld%lld%lld", &opt, &l, &r, &w);
        int fl = f(l), fr = f(r);
        if (opt == 2)
        {
            printf("%lld\n", ((a[r] * c[fr] + p[fr]) % mod + mod) % mod);
        }
        else if (opt == 0)
        {
            if (fl == fr)
            {
                for (int j = fl * k + 1; j <= min(n, (fl + 1) * k); j++)
                {
                    a[j] = (a[j] * c[fl] + p[fl]) % mod;
                    if (j >= l && j <= r)
                    {
                        a[j] = (a[j] + w) % mod;
                    }
                }
                c[fl] = 1, p[fl] = 0;
            }
            else
            {
                for (int j = fl * k + 1; j <= (fl + 1) * k; j++)
                {
                    a[j] = (a[j] * c[fl] + p[fl]) % mod;
                    if (j >= l && j <= r)
                    {
                        a[j] = (a[j] + w) % mod;
                    }
                }
                c[fl] = 1, p[fl] = 0;
                for (int j = fl + 1; j < fr; j++)
                {
                    p[j] = (p[j] + w) % mod;
                }
                for (int j = fr * k + 1; j <= min((fr + 1) * k, n); j++)
                {
                    a[j] = (a[j] * c[fr] + p[fr]) % mod;
                    if (j >= l && j <= r)
                    {
                        a[j] = (a[j] + w) % mod;
                    }
                }
                c[fr] = 1, p[fr] = 0;
            }
        }
        else
        {
            if (fl == fr)
            {
                for (int j = fl * k + 1; j <= min(n, (fl + 1) * k); j++)
                {
                    a[j] = (a[j] * c[fl] + p[fl]) % mod;
                    if (j >= l && j <= r)
                    {
                        a[j] = (a[j] * w) % mod;
                    }
                }
                c[fl] = 1, p[fl] = 0;
            }
            else
            {
                for (int j = fl * k + 1; j <= (fl + 1) * k; j++)
                {
                    a[j] = (a[j] * c[fl] + p[fl]) % mod;
                    if (j >= l && j <= r)
                    {
                        a[j] = (a[j] * w) % mod;
                    }
                }
                c[fl] = 1, p[fl] = 0;
                for (int j = fl + 1; j < fr; j++)
                {
                    c[j] = (c[j] * w) % mod;
                    p[j] = (p[j] * w) % mod;
                }
                for (int j = fr * k + 1; j <= min((fr + 1) * k, n); j++)
                {
                    a[j] = (a[j] * c[fr] + p[fr]) % mod;
                    if (j >= l && j <= r)
                    {
                        a[j] = (a[j] * w) % mod;
                    }
                }
                c[fr] = 1, p[fr] = 0;
            }
        }
    }
    return 0;
}