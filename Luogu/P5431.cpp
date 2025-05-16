#include <algorithm>
#include <iostream>
using namespace std;
long long ans, tot, qz[5000005], hz[5000005], a[5000005];
long long qp(long long x, long long p)
{
    long long res = 1, y = p - 2;
    while (y)
    {
        if (y % 2)
        {
            res = res * x % p;
        }
        x = x * x % p, y /= 2;
    }
    return res;
}
long long read()
{
    long long ans = 0;
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
    long long n = read(), p = read(), k = read();
    qz[0] = hz[n + 1] = tot = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        tot = tot * a[i] % p;
        qz[i] = qz[i - 1] * a[i] % p;
    }
    for (int i = n; i >= 1; i--)
    {
        hz[i] = hz[i + 1] * a[i] % p;
    }
    for (int i = 1, kf = 1; i <= n; i++)
    {
        kf = kf * k % p;
        ans = (ans + kf * qz[i - 1] % p * hz[i + 1] % p) % p;
    }
    printf("%lld\n", ans * qp(tot, p) % p);
    return 0;
}