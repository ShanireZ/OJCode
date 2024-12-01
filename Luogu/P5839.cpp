#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, lmt, pre[30], str[100005], dp[100005], a[30][30], sum[100005][30];
int main()
{
    cin >> n >> m >> lmt;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        str[i] = ch - 'a' + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[j][i] = sum[j - 1][i] + a[str[j]][i];
        }
    }
    memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
    memset(pre, 0x3f, sizeof(pre));
    for (int i = 1; i <= n; i++) // 枚举当前终点
    {
        // dp[i] = min(dp[j-1] + min(j至i的花费))  0<=j-1<=i-k
        // dp[i] = min(dp[j-1] + min(sum[i][c] - sum[j-1][c]))
        // 用 pre[c] 记录前方范围内 min(dp[j-1]-sum[j-1][c])
        // dp[i] = min(sum[i][c] + pre[c])
        for (int c = 1; c <= m; c++)
        {
            dp[i] = min(dp[i], sum[i][c] + pre[c]);
            if (i - lmt + 1 >= 0)
            {
                pre[c] = min(pre[c], dp[i - lmt + 1] - sum[i - lmt + 1][c]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}