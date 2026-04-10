#include <algorithm>
#include <iostream>
using namespace std;
long long dp[25][100005], n, m, a, ans;
int main()
{
    cin >> n >> m;
    dp[m][0] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        dp[i][0] = dp[i + 1][0] * 2;
    }
    for (int j = 1; j <= n; j++)
    {
        cin >> a;
        for (int i = m; i >= 0; i--)
        {
            dp[i][j] = dp[i][j - 1] + a;
            for (int k = 1; i + k <= m; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i + k][j] * (1ll << k));
            }
        }
    }
    ans = dp[0][n];
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, dp[i][n] * (1ll << i));
    }
    cout << ans << endl;
    return 0;
}