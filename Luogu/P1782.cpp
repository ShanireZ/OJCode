#include <algorithm>
#include <cstdio>
using namespace std;
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}
long long dp[10005], y[10005];
int main()
{
    int n = read(), m = read(), bag = read();
    for (int i = 1; i <= n; i++)
    {
        int v = read(), w = read(), d = read(), base = 1;
        if (v * d >= bag)
        {
            for (int j = v; j <= bag; j++)
            {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
        else
        {
            for (int x = 1; d != 0; x *= 2)
            {
                int now = min(x, d);
                d -= now;
                for (int j = bag; j >= now * v; j--)
                {
                    dp[j] = max(dp[j], dp[j - now * v] + now * w);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), c = read();
        for (long long x = 0; x <= bag; x++)
        {
            y[x] = a * x * x + b * x + c;
        }
        for (int j = bag; j >= 0; j--)
        {
            long long ans = 0;
            for (int x = 0; x <= j; x++)
            {
                ans = max(ans, dp[j - x] + y[x]);
            }
            dp[j] = max(dp[j], ans);
        }
    }
    printf("%lld\n", dp[bag]);
    return 0;
}