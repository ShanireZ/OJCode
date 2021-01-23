#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1005][1005], tot[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tot[i][j];
            tot[i][j] += tot[i - 1][j];
        }
        dp[i][1] = tot[i][1];
    }
    for (int j = 2; j <= m; j++)
    {
        long long maxv = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            maxv = max(maxv, dp[i][j - 1] - tot[i - 1][j]);
            dp[i][j] = maxv + tot[i][j];
        }
        maxv = -0x3f3f3f3f;
        for (int i = n; i >= 1; i--)
        {
            maxv = max(maxv, dp[i][j - 1] + tot[i][j]);
            dp[i][j] = max(dp[i][j], maxv - tot[i - 1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}