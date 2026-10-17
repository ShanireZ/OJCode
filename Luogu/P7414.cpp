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
    for (int i = 1; i <= n; i++) //只刷一個格子 方案數為1
    {
        dp[i][i] = 1;
    }
    for (int len = 1; len < n; len++) //枚舉每一個區間長度
    {
        for (int l = 1; l < n; l++) //枚舉左端點
        {
            int r = l + len; //右端點
            if (r > n)
            {
                continue;
            }
            //如果l r顏色相同 那麼可以從l+1~r或l~r-1區域第一次塗色時延續個底盤即可 不增加次數
            if (nums[l] == nums[r])
            {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
                continue;
            }
            //如果l r顏色不同 枚舉每一個塗色分隔點
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}