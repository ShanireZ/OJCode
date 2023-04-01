#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
long long pos[25][2];
double dis[25][25], dp[25][1500000];
int main()
{
    int n, D;
    cin >> n >> D;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
        for (int j = 1; j <= i; j++)
        {
            double d = sqrt((pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]));
            if (d <= D)
            {
                dis[i][j] = dis[j][i] = d;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = 1e18;
        }
    }
    dp[1][1] = 0;
    for (int i = 1; i < (1 << n); i++) // 状态
    {
        for (int j = 1; j <= n; j++) // 上一步终点
        {
            if (i & (1 << (j - 1)))
            {
                for (int k = 1; k <= n; k++) // 本次终点
                {
                    if (i & (1 << (k - 1)))
                    {
                        dp[k][i] = min(dp[k][i], min(dp[j][i], dp[j][i ^ (1 << (k - 1))]) + dis[j][k]);
                    }
                }
            }
        }
    }
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][(1 << n) - 1] + dis[i][1]);
    }
    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}
// TAG: DP 状态压缩 Floyd 图论 最短路