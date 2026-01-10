#include <algorithm>
#include <iostream>
using namespace std;
int dp[305][305], c[305], a[305], n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) // dp[i][j] i个人j组,最后一组k个人
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + a[1];
            for (int k = 2; k <= i - j + 1; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + a[k] - c[j] + c[n - j + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}