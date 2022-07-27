#include <iostream>
using namespace std;
int n, w[205], dp[205][205];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = i + 1; j <= n * 2; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l < n * 2; l++)
        {
            int r = l + len - 1;
            if (r > n * 2)
            {
                break;
            }
            for (int k = l; k < r; k++)
            {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + w[l] * w[k + 1] * w[r + 1]);
            }
        }
    }
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        int r = l + n - 1;
        ans = max(ans, dp[l][r]);
    }
    cout << ans << endl;
    return 0;
}