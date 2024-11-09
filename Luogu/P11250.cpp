#include <algorithm>
#include <iostream>
using namespace std;
long long c[2005][2005], pw[2005], mod = 1000000007;
int main()
{
    pw[0] = c[0][0] = 1;
    for (int i = 1; i <= 2000; i++)
    {
        pw[i] = pw[i - 1] * 2 % mod, c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        if (k * 2 > m || n - m + k < 0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << c[n][k] * c[n - k][m - 2 * k] % mod * pw[m - 2 * k] % mod << endl;
    }
    return 0;
}