#include <iostream>
using namespace std;
int dp[55][1005];
int main()
{
    int n, st, mx;
    cin >> n >> st >> mx;
    dp[0][st] = 1;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j <= mx; j++)
        {
            if (j - c >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c]);
            }
            if (j + c <= mx)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + c]);
            }
        }
    }
    int ans = -1;
    for (int i = mx; i >= 0; i--)
    {
        if (dp[n][i])
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}