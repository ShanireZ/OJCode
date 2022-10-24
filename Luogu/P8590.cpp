#include <iostream>
using namespace std;
__int128 a[1000005], a2[1000005], ans, mod = 998244353;
int main()
{
    ios::sync_with_stdio(false);
    int n, k, pos = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        if (x < -1)
        {
            pos = i;
        }
        a[i] = a[i - 1] + x, a2[i] = a2[i - 1] + x * x;
    }
    for (__int128 i = 1; i <= k; i++)
    {
        while (pos > 0 && (i + 1) / 2 == a[pos - 1] - a[pos])
        {
            pos--;
        }
        ans += a2[pos] + a[pos] * 2 + pos;
        ans += (a2[n] - a2[pos]) + (a[n] - a[pos]) * 2 * i + i * i * (n - pos);
    }
    long long x = ans % mod;
    cout << x << endl;
    return 0;
}