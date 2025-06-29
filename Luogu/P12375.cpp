#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long n, m, mod = 998244353;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) // (n^3+5n)/6
    {
        cin >> n >> m;
        __int128 x = 1.5 + sqrt(2.25 - 2 * (n - m));
        long long ans = ((x * x * x + 5 * x) / 6 + (2 * m - n + x + 2) * (n - 1 - x) / 2) % mod;
        cout << ans << '\n';
    }
    return 0;
}