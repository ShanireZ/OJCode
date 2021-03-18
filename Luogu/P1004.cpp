#include <iostream>
#include <algorithm>
using namespace std;
int nums[15][15];
int dp[20][15][15];
int main()
{
    int n;
    cin >> n;
    int x, y, w;
    cin >> x >> y >> w;
    while (x != 0 && y != 0 && w != 0)
    {
        nums[x][y] = w;
        cin >> x >> y >> w;
    }
    dp[0][1][1] = nums[1][1];
    for (int step = 1; step <= (n - 1) * 2; step++)
    {
        for (int i = 1; i <= n && i <= step + 1; i++)
        {
            for (int j = 1; j <= n && j <= step + 1; j++)
            {
                int way1 = max(dp[step - 1][i - 1][j], dp[step - 1][i][j]);
                int way2 = max(dp[step - 1][i - 1][j - 1], dp[step - 1][i][j - 1]);
                int now = nums[i][step + 2 - i];
                if (i != j)
                {
                    now += nums[j][step + 2 - j];
                }
                dp[step][i][j] = max(way1, way2) + now;
            }
        }
    }
    cout << dp[(n - 1) * 2][n][n];
    return 0;
}