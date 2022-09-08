#include <cstring>
#include <iostream>
using namespace std;
long long dp[3][1005][1005], pos[2005][2], dis[2005][2005];
// dp[a][i][j] H用了i个 G用了j个 a=1现在在H a=2现在在G
int main()
{
    memset(dp, 0x3f, sizeof(dp));
    int h, g;
    cin >> h >> g;
    for (int i = 1; i <= h + g; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
        for (int j = i - 1; j >= 1; j--)
        {
            dis[i][j] = dis[j][i] = (pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]);
        }
    }
    dp[1][1][0] = 0, dp[2][1][1] = dis[1][1 + h];
    for (int i = 1; i <= h; i++) // H至少选1个
    {
        for (int j = 0; j <= g; j++) // G可以不选
        {
            dp[1][i][j] = min(dp[1][i][j], min(dp[2][i - 1][j] + dis[i][j + h], dp[1][i - 1][j] + dis[i - 1][i]));
            if (j)
            {
                dp[2][i][j] = min(dp[2][i][j], min(dp[2][i][j - 1] + dis[j - 1 + h][j + h], dp[1][i][j - 1] + dis[i][j + h]));
            }
        }
    }
    cout << dp[1][h][g] << endl;
    return 0;
}