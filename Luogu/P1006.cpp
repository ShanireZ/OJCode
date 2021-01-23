#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int nums[55][55];
int dp[105][55][55]; //第i步时，第一个纸条位于第j行，第二个位于第k行，经过的最大路径和
int same(int a, int b)
{
    return a != b;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nums[i][j];
        }
    }
    for (int i = 1; i <= m + n - 2; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            for (int k = 1; k <= i + 1; k++)
            {
                int ans1 = max(dp[i - 1][j][k], dp[i - 1][j - 1][k]); //第i步时，第一个纸条位于第j行，第二个位于第k行，那么第i-1步总共有4种可能
                int ans2 = max(dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1]);
                dp[i][j][k] = max(ans1, ans2) + nums[j][2 + i - j] + nums[k][2 + i - k] * same(j, k); //如果第i步时两个在同一行，那么说明两个在同一个格子，只需加一遍
            }
        }
    }
    cout << dp[m + n - 2][m][m];
    return 0;
}