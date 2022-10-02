#include <iostream>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int dp[505][505], c[505], f[505], b[505];
// dp[x][y] 价格不超过x 且 新鲜度至少为y 时的最大美丽度
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        c[i] = read(), f[i] = read(), b[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int x = 500; x >= c[i]; x--)
        {
            for (int y = 500; y > f[i]; y--)
            {
                if (dp[x - c[i]][y - f[i]])
                {
                    dp[x][y] = max(dp[x][y], dp[x - c[i]][y - f[i]] + b[i]);
                }
            }
            for (int y = f[i]; y >= 0; y--) // 如果第i个花自己即可达到当前新鲜度
            {
                dp[x][y] = max(dp[x][y], dp[x - c[i]][0] + b[i]);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int cost = read(), fre = read();
        printf("%d\n", dp[cost][fre]);
    }
    return 0;
}