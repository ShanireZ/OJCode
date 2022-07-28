#include <iostream>
using namespace std;
int dp[25][25]; // dp[i][j] 共用i张CD且最后一张CD已用时间不超过j 的 最大歌曲数
int main()
{
    int n, T, m;
    cin >> n >> T >> m;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        for (int j = m; j >= 1; j--)
        {
            for (int k = T; k >= t; k--)
            {
                dp[j][k] = max(dp[j][k], max(dp[j][k - t] + 1, dp[j - 1][T] + 1));
            }
        }
    }
    cout << dp[m][T] << endl;
    return 0;
}