#include <algorithm>
#include <iostream>
using namespace std;
long long MOD = 1000000007, n, m, ans = 1;
long long qpow(long long base, long long ex)
{
    long long res = 1;
    while (ex)
    {
        if (ex % 2 == 1)
        {
            res = res * base % MOD;
        }
        base = base * base % MOD, ex /= 2;
    }
    return res;
}
int main()
{
    cin >> n >> m;
    m = min(m, n - m);
    for (int i = 1; i <= m; ++i)
    {
        int x = n - m + i;
        ans = ans * x % MOD * qpow(i, MOD - 2) % MOD;
    }
    cout << ans << '\n';
    return 0;
}