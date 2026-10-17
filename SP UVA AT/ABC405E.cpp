#include <algorithm>
#include <iostream>
using namespace std;
long long fac[4000005], inv[4000005], mod = 998244353, a, b, c, d;
long long qp(long long x, long long p)
{
    long long res = 1;
    while (p)
    {
        if (p % 2 == 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod, p /= 2;
    }
    return res;
}
int main()
{
    fac[0] = 1;
    for (int i = 1; i <= 4000000; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[4000000] = qp(fac[4000000], mod - 2); // 費馬小定律
    for (int i = 3999999; i >= 0; i--)        // 階乘逆元
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    cin >> a >> b >> c >> d;
    long long sum = a + b + c + d, ans = 0;
    for (int i = a; i <= a + b; i++) // 枚舉最右側蘋果
    {
        long long x = fac[i - 1] * inv[a - 1] % mod * inv[i - a] % mod;     // 前i-1個位置選a-1個位置放蘋果
        long long y = fac[sum - i] * inv[c] % mod * inv[sum - i - c] % mod; // 後sum-i個位置選c個位置放香蕉
        ans = (ans + x * y % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}