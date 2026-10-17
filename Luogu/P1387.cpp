#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int nums[105][105];
int dp[105][105]; //以i,j為右下角的正方形邊長大小
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nums[i][j];
        }
    }
    int max_l = -1;
    for (int i = 1; i <= n; i++) //dp[i][j]的值只與上方，左上方，左側的值有關
    {
        for (int j = 1; j <= m; j++)
        {
            if (nums[i][j])
            {
                int ans = min(dp[i - 1][j], dp[i - 1][j - 1]);
                ans = min(ans, dp[i][j - 1]);
                dp[i][j] = ans + 1;
            }
            if (dp[i][j] > max_l)
            {
                max_l = dp[i][j];
            }
        }
    }
    cout << max_l;
    return 0;
}