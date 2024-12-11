#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[50005]; // dp[y]花费不超过y的最大强度
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, p, q;
        cin >> n >> p >> q;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            int pi, ci;
            cin >> pi >> ci;
            for (int j = q; j >= ci; j--)
            {
                dp[j] = max(dp[j - ci] + pi, dp[j]);
            }
        }
        if (dp[q] < p)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= q; i++)
        {
            if (dp[i] >= p)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}