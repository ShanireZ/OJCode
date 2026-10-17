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
    for (int i = 1; i <= sz; i++) //只刷一個格子 方案數為1
    {
        dp[i][i] = 1;
    }
    for (int len = 1; len < sz; len++) //枚舉每一個區間長度
    {
        for (int l = 1; l < sz; l++) //枚舉左端點
        {
            int r = l + len; //右端點
            if (r > sz)
            {
                continue;
            }
            //如果l r顏色相同 那麼可以從l+1~r或l~r-1區域第一次塗色時延續個底盤即可 不增加次數
            if (s[l] == s[r])
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
    cout << dp[1][sz] << endl;
    return 0;
}