#include <algorithm>
#include <iostream>
using namespace std;
long long n, mod = 998244353, cb[35][2], pw[35];
int main()
{
    cin >> n;
    long long tot = 0, cnt = 2, base = n % mod, p = n - 3;
    while (p) // 每条边n^(n-3)次,如果往返去重,则再翻一倍
    {
        if (p % 2 == 1)
        {
            cnt = cnt * base % mod;
        }
        base = base * base % mod, p /= 2;
    }
    pw[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        pw[i] = pw[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++) // cnt*所有边的和为答案
    {
        long long a;
        cin >> a;
        for (int j = 0; j <= 30; j++)
        {
            int now = a % 2;
            tot = (tot + cb[j][!now] * pw[j] % mod) % mod;
            cb[j][now]++, a /= 2;
        }
    }
    cout << tot * cnt % mod << endl;
    return 0;
}