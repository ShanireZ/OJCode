#include <iostream>
using namespace std;
int dp[25][25]; // dp[i][j] 共用i張CD且最後一張CD已用時間不超過j 的 最大歌曲數
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