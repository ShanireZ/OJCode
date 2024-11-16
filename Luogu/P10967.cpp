#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[305][35], dis[305][305], p[305];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dis[i][j] = dis[i][j - 1] + p[j] - p[(i + j) / 2]; // i到j放1个的最小距离和
        }
        dp[i][1] = dis[1][i]; // 前i个放1个的最小距禋和
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, m); j++)
        {
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + dis[k + 1][i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}