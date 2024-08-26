#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, dp[1005][1005], a[1005][1005];
int main()
{
    memset(dp, 0x3f, sizeof(dp)), dp[1][1] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
            for (int k = j - 1; k >= 1; k--)
            {
                if (a[i][k] <= a[i][k + 1])
                {
                    break;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + 1);
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
// TAG: DP 搜索