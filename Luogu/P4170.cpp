#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int dp[55][55];
int main()
{
    memset(dp, 0x3f, sizeof(dp));
    string s;
    cin >> s;
    int sz = s.size();
    s.insert(0, "*");
    for (int i = 1; i <= sz; i++) //只刷一个格子 方案数为1
    {
        dp[i][i] = 1;
    }
    for (int len = 1; len < sz; len++) //枚举每一个区间长度
    {
        for (int l = 1; l < sz; l++) //枚举左端点
        {
            int r = l + len; //右端点
            if (r > sz)
            {
                continue;
            }
            //如果l r颜色相同 那么可以从l+1~r或l~r-1区域第一次涂色时延续个底盘即可 不增加次数
            if (s[l] == s[r])
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
    cout << dp[1][sz] << endl;
    return 0;
}