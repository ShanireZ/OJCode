#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
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
    long long l = read(), r = read(), ans = 1, s = 0;
    long long st = sqrt(l - 1), ed = sqrt(r + 1);
    for (long long i = st; i <= ed; i++)
    {
        long long now = i * i;
        if (now >= l && now <= r)
        {
            long long x = now, tot = 0, trig = 1;
            while (x)
            {
                tot += x % 10;
                x /= 10;
            }
            for (int j = 2; j < tot; j++)
            {
                if (tot % j == 0)
                {
                    trig = 0;
                    break;
                }
            }
            if (trig && tot != 1)
            {
                s = 1, ans = i * i % 998244353 * ans % 998244353;
            }
        }
    }
    if (s == 0)
    {
        ans = 0;
    }
    printf("%lld\n", ans);
    return 0;
}