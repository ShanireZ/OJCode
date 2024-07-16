#include <algorithm>
#include <iostream>
using namespace std;
int dp[2005][2005], ans = 2e9;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dp[i][j];
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            int pre = (i == 1 ? m : i - 1);
            dp[i][j] += min(dp[i][j - 1], dp[pre][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ans = min(ans, dp[i][n]);
    }
    cout << ans << endl;
    return 0;
}