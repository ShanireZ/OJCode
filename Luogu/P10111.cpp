#include <algorithm>
#include <iostream>
using namespace std;
int dp[1005][1005][3], a[1005], b[1005], c[1005], n;
int delt[3] = {-1, 0, 1};
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int x = (c[i] + delt[k] + 3) % 3;
                dp[i][j][x] = dp[i - 1][j][x];
                if (j > 0)
                {
                    dp[i][j][x] = max(dp[i][j][x], max(dp[i - 1][j - 1][(x + 1) % 3], dp[i - 1][j - 1][(x + 2) % 3]));
                }
                dp[i][j][x] += a[i] * k;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[n][i][0] - b[i]);
        ans = max(ans, dp[n][i][1] - b[i]);
        ans = max(ans, dp[n][i][2] - b[i]);
    }
    cout << ans << endl;
    return 0;
}
