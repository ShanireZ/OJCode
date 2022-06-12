#include <iostream>
using namespace std;
int mp[1005][1005], dp[1005][1005];
int main()
{
    int n, t, ans = 0;
    cin >> n >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == 0)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}