#include <iostream>
using namespace std;
long long sum[1500005], cnt[1500005], read();
int main()
{
    long long pos = 1000000, n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        long long a = read();
        cnt[pos + a]++, sum[pos + a] += a;
    }
    for (int i = 500000; i <= 1500000; i++)
    {
        cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int opt = read();
        if (opt == 1)
        {
            pos = pos - read();
        }
        else
        {
            long long ans = 0;
            if (pos < 500000)
            {
                ans = sum[1500000] + (1000000 - pos) * cnt[1500000];
            }
            else if (pos <= 1500000)
            {
                ans = (sum[1500000] - sum[pos]) + (1000000 - pos) * (cnt[1500000] - cnt[pos]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
long long read()
{
    long long ans = 0, tag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        tag = (ch == '-') ? -1 : 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * tag;
}