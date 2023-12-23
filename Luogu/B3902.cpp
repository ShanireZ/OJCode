#include <algorithm>
#include <iostream>
using namespace std;
long long mod = 1e9 + 7, n, m, ans, b[100005], dp[2005], vis[2005];
long long qpow(long long a, long long b)
{
    long long res = 1, base = a;
    while (b)
    {
        if (b % 2 == 1)
        {
            res = res * base % mod;
        }
        b /= 2, base = base * base % mod;
    }
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        if (b[i] <= 2000)
        {
            vis[b[i]] = i;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vis[i - j]) // 是否存在 i - j
            {
                long long x = m - vis[i - j] + 1; // 大于等于i - j 的数的个数
                dp[i] += (qpow(x, i - j) - qpow(x - 1, i - j) + mod) % mod * dp[j] % mod;
                // 一共i-j个位置，每个位置有x种选择
                // 但i-j必须出现一次，所以减去i-j没出现的情况数
            }
        }
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}