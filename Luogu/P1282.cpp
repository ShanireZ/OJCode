#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int u[1005], d[1005], dp[1005][6005];
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i] >> d[i];
        tot += u[i] + d[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][u[1]] = 0;
    dp[1][d[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            if (j > u[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - u[i]]); //第i张不旋转
            }
            if (j > d[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - d[i]] + 1); //第i张旋转
            }
        }
    }
    int minv = 0x3f3f3f3f, mint = 0x3f3f3f3f;
    for (int i = n; i <= tot; i++)
    {
        if (dp[n][i] >= 0x3f3f3f3f)
        {
            continue;
        }
        if (minv == abs(tot - i * 2))
        {
            mint = min(mint, dp[n][i]);
        }
        else if (minv > abs(tot - i * 2))
        {
            minv = abs(tot - i * 2);
            mint = dp[n][i];
        }
    }
    cout << mint << endl;
    return 0;
}