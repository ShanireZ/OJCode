#include <algorithm>
#include <cstdio>
using namespace std;
int read()
{
    char ch = getchar();
    int num = 0;
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}
int dp[1005];
int main()
{
    int ts = read() * 60 + read();
    int te = read() * 60 + read();
    te -= ts;
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int t = read(), c = read(), p = read();
        if (p == 0)
        {
            p = te / t;
        }
        int base = 1;
        while (p >= base)
        {
            for (int j = te; j >= t * base; j--)
            {
                dp[j] = max(dp[j], dp[j - t * base] + c * base);
            }
            p -= base;
            base *= 2;
        }
        for (int j = te; j >= t * p; j--)
        {
            dp[j] = max(dp[j], dp[j - t * p] + c * p);
        }
    }
    printf("%d\n", dp[te]);
    return 0;
}