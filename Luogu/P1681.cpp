#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, dp[1505][1505][2];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int v;
            cin >> v;
            if (v == 1)
            {
                dp[i][j][1] = min({dp[i][j - 1][0], dp[i - 1][j][0], dp[i - 1][j - 1][1]}) + 1;
            }
            else
            {
                dp[i][j][0] = min({dp[i][j - 1][1], dp[i - 1][j][1], dp[i - 1][j - 1][0]}) + 1;
            }
            ans = max({ans, dp[i][j][0], dp[i][j][1]});
        }
    }
    cout << ans << endl;
    return 0;
}