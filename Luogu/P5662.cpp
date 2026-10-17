#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[10005], price[105][105]; //第i天第j件物品價格
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
    //利潤靠倒賣商品來 第一天買第三天賣==第一天買第二天賣+第二天買第三天賣
    for (int i = 2; i <= t; i++) //第一天肯定無利潤 所以從第二天開始計算
    {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; j++)
        {
            if (price[i][j] > price[i - 1][j]) //如果沒利潤則相近兩天不倒賣該商品
            {
                for (int k = price[i - 1][j]; k <= m; k++)
                {
                    //完全揹包 DP每天每種商品在每個本金下的利潤 多種商品取最大的
                    dp[k] = max(dp[k - price[i - 1][j]] + price[i][j] - price[i - 1][j], dp[k]);
                }
            }
        }
        m += dp[m]; //本金中加入當天利潤作為下一天新本金
    }
    cout << m << endl;
    return 0;
}