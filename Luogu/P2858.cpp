#include <iostream>
using namespace std;
int v[2005], dp[2005][2005]; // dp[i][j] 左边取i个 右边取j个
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + v[n - i + 1] * i;
        dp[i][0] = dp[i - 1][0] + v[i] * i;
    }
    for (int l = 1; l <= n; l++)
    {
        for (int j = l; j <= n; j++)
        {
            int r = j - l;
            dp[l][r] = max(dp[l - 1][r] + v[l] * j, dp[l][r - 1] + j * v[n - r + 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, dp[i][n - i]);
    }
    cout << ans << endl;
    return 0;
}