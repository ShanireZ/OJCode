#include <algorithm>
#include <iostream>
using namespace std;
__int128 tot[1005][1005], mod = 2e64;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                unsigned long long x;
                cin >> x;
                tot[i][j] = (x + tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1]) % mod;
            }
        }
        unsigned long long ans = 0;
        for (int i = 1; i <= q; i++)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            ans ^= (tot[x][y] - tot[u - 1][y] - tot[x][v - 1] + tot[u - 1][v - 1]) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}