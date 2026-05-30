#include <algorithm>
#include <cstdio>
using namespace std;
#define MX 1000005
long long d[MX], ans;
int read()
{
    int ans = 0;
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
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read(), z = read();
        d[x] += z, d[y] -= z;
        if (x >= y)
        {
            d[1] += z, d[n + 1] -= z;
        }
    }
    long long now = 0;
    for (int i = 1; i <= n; i++)
    {
        now += d[i];
        ans = max(ans, now);
    }
    printf("%lld\n", (ans + 35) / 36);
    return 0;
}
// TAG: 差分 环形区间
