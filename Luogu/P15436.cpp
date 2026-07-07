#include <algorithm>
#include <iostream>
using namespace std;
int dp[10005], s[10005], a[10005], n, c, b;
int main()
{
    cin >> n >> c >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = b;
    }
    dp[0] = b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            if (dp[j] < 0)
            {
                break;
            }
            dp[j] = min(c, dp[j] + s[i]);
            if (j >= 1 && dp[j - 1] >= 0)
            {
                dp[j] = max(dp[j], min(c, dp[j - 1] + s[i] * 2));
            }
            if (dp[j] < a[i])
            {
                dp[j] = -1;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] >= 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}