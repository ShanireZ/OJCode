#include <algorithm>
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
long long h[200005], l[200005], cnt[500005];
int main()
{
    long long n = read(), m = read(), q = read(), k = read();
    while (q--)
    {
        long long op = read(), x = read();
        if (op == 1)
        {
            h[x] = (h[x] + 1) % k;
        }
        else
        {
            l[x] = (l[x] + 1) % k;
        }
    }
    long long ans = n * m;
    for (int i = 1; i <= m; i++)
    {
        cnt[l[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        ans -= cnt[(k - h[i]) % k];
    }
    printf("%lld\n", ans);
    return 0;
}
// TAG: 整除 余数