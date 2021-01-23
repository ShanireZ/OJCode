#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[10005], price[105][105]; //第i天第j件物品价格
int main()
{
    int t, n, m;
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> price[i][j];
        }
    }
    //利润靠倒卖商品来 第一天买第三天卖==第一天买第二天卖+第二天买第三天卖
    for (int i = 2; i <= t; i++) //第一天肯定无利润 所以从第二天开始计算
    {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; j++)
        {
            if (price[i][j] > price[i - 1][j]) //如果没利润则相近两天不倒卖该商品
            {
                for (int k = price[i - 1][j]; k <= m; k++)
                {
                    //完全背包 DP每天每种商品在每个本金下的利润 多种商品取最大的
                    dp[k] = max(dp[k - price[i - 1][j]] + price[i][j] - price[i - 1][j], dp[k]);
                }
            }
        }
        m += dp[m]; //本金中加入当天利润作为下一天新本金
    }
    cout << m << endl;
    return 0;
}