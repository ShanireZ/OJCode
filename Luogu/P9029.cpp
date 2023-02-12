#include <algorithm>
#include <iostream>
using namespace std;
long long c[100005], qz[100005], read();
int main()
{
    long long n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        c[i] = read();
    }
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        qz[i] = qz[i - 1] + c[i];
    }
    for (int i = 1; i <= q; i++) // 三个价格1~k[上升] k+1~2k-1[下降] 2k~无限[负数且下降]
    {
        long long ans = 0, k = read(), m = read();
        long long r = lower_bound(c + 1, c + 1 + n, k + k) - c - 1; // r+1的价格>=k*2
        if (m >= n - r)
        {
            ans += (n - r) * k - (qz[n] - qz[r] - (n - r) * k), m -= n - r;
        }
        else
        {
            ans += m * k - (qz[n] - qz[n - m] - m * k), m = 0;
        }
        long long l = upper_bound(c + 1, c + 1 + r, k) - c - 1; // l的价格<=k
        if (m >= l)
        {
            ans += qz[l], m -= l;
            ans += m * k - (qz[r] - qz[r - m] - m * k), r = r - m, m = 0;
        }
        else
        {
            ans += qz[m], l = m, m = 0;
        }
        while (c[l] > k - (c[r] - k)) // 二分可继续优化
        {
            ans -= c[l], l--;
            ans += k - (c[r] - k), r--;
        }
        printf("%lld\n", ans);
    }
    return 0;
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