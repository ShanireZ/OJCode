#include <cstring>
#include <iostream>
using namespace std;
int dp[1500005], cnt[100005][25], p[25], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= m; j++)
        {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][x]++;
    }
    p[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        p[i] = p[i - 1] * 2;
    }
    int ed = p[m] - 1;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= ed; i++)
    {
        int tot = 0;
        for (int j = 1; j <= m; j++)
        {
            int stj = p[j - 1];
            if (i & stj)
            {
                tot += cnt[n][j];
            }
        }
        for (int j = 1; j <= m; j++)
        {
            int stj = p[j - 1];
            if (i & stj)
            {
                int l = tot - cnt[n][j], r = tot;
                dp[i] = min(dp[i], dp[i ^ stj] + cnt[n][j] - (cnt[r][j] - cnt[l][j]));
            }
        }
    }
    cout << dp[ed] << endl;
    return 0;
}