#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, k, ans, dp[105][2005]; // dp[i][j] 选了i个，其中包含j个3，最多包含dp[i][j]个2
int main()
{
    cin >> n >> k;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k * 18; j++)
        {
            dp[i][j] = -0x3f3f3f3f;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, x, c2 = 0, c3 = 0;
        cin >> a;
        x = a;
        while (x % 2 == 0)
        {
            c2++, x /= 2;
        }
        x = a;
        while (x % 3 == 0)
        {
            c3++, x /= 3;
        }
        for (int j = k; j > 0; j--)
        {
            for (int m = c3; m <= k * 18; m++)
            {
                if (dp[j - 1][m - c3] != -0x3f3f3f3f)
                {
                    dp[j][m] = max(dp[j][m], dp[j - 1][m - c3] + c2);
                }
            }
        }
    }
    for (int i = 1; i <= k * 18; i++)
    {
        ans = max(ans, min(i, dp[k][i]));
    }
    cout << ans << endl;
    return 0;
}