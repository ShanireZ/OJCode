#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cnt[105][2];
int dp[205][205]; //前i个愿望时，不超过m元t时间，完成的最大愿望数量，已压缩空间所以需从后向前倒推
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt[i][0] >> cnt[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (j >= cnt[i][0])
            {
                for (int k = t; k >= 1; k--)
                {
                    if (k >= cnt[i][1])
                    {
                        dp[j][k] = max(dp[j][k], dp[j - cnt[i][0]][k - cnt[i][1]] + 1);
                    }
                }
            }
        }
    }
    cout << dp[m][t];
    return 0;
}