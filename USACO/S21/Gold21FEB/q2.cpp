#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[305][305], nums[305];
int main()
{
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) //只刷一个格子 方案数为1
    {
        dp[i][i] = 1;
    }
    for (int len = 1; len < n; len++) //枚举每一个区间长度
    {
        for (int l = 1; l < n; l++) //枚举左端点
        {
            int r = l + len; //右端点
            if (r > n)
            {
                continue;
            }
            //如果l r颜色相同 那么可以从l+1~r或l~r-1区域第一次涂色时延续个底盘即可 不增加次数
            if (nums[l] == nums[r])
            {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
                continue;
            }
            //如果l r颜色不同 枚举每一个涂色分隔点
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}