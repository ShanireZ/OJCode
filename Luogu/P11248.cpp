#include <algorithm>
#include <iostream>
using namespace std;
int dp[505][505][305], T, n, m, k;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                for (int t = 0; t <= k; t++)
                {
                    if (c == '?' && t > 0)
                    {
                        dp[i][j][t] = max(dp[i - 1][j][t - 1], dp[i][j - 1][t - 1]) + 1;
                    }
                    else
                    {
                        dp[i][j][t] = max(dp[i - 1][j][t], dp[i][j - 1][t]) + (c == '1');
                    }
                }
            }
        }
        cout << dp[n][m][k] << endl;
    }
    return 0;
}