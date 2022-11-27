#include <cstring>
#include <iostream>
using namespace std;
#define MOD 998244353
long long a[1010][1010], hz[1010][1010], thz[1010][1010], thhz[1010][1010], h[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    int t, tid;
    cin >> t >> tid;
    while (t--)
    {
        long long n, m, c, f, ansc = 0, ansf = 0;
        cin >> n >> m >> c >> f;
        memset(hz, -1, sizeof(hz)), memset(thz, 0, sizeof(thz));
        memset(thhz, 0, sizeof(thhz)), memset(h, 0, sizeof(h));
        char ch;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ch;
                a[i][j] = (ch == '0') ? 0 : 1;
            }
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                if (a[i][j] == 1)
                {
                    continue;
                }
                hz[i][j] = hz[i][j + 1] + 1;
                if (i + 2 <= n && a[i + 1][j] == 0 && a[i + 2][j] == 0)
                {
                    thz[i][j] = thz[i + 1][j] + hz[i + 2][j];
                }
                if (i + 3 <= n && a[i + 1][j] == 0 && a[i + 2][j] == 0 && a[i + 3][j] == 0)
                {
                    h[i][j] = h[i + 1][j] + 1;
                    thhz[i][j] = thhz[i + 1][j] + hz[i + 2][j] * h[i][j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (hz[i][j] > 0)
                {
                    ansc = (ansc + hz[i][j] * thz[i][j]) % MOD;
                    ansf = (ansf + hz[i][j] * thhz[i][j]) % MOD;
                }
            }
        }
        cout << ansc * c % MOD << ' ' << ansf * f % MOD << '\n';
    }
    return 0;
}