#include <algorithm>
#include <iostream>
using namespace std;
#define N 3012
#define M 312
int n, m, p[N], dp[N][M], dis[N][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        fill(dp[i] + 1, dp[i] + 1 + m, 100000000);
    }
    stable_sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dis[i][j] = dis[i][j - 1] + p[j] - p[(i + j) >> 1];
        }
        dp[i][1] = dis[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, m); j++)
        {
            for (int k = j - 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + dis[k + 1][i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}