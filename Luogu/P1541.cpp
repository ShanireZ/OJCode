#include <iostream>
using namespace std;
int dp[45][45][45][45], s[400], cnt[10];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    dp[0][0][0][0] = s[1];
    for (int c1 = 0; c1 <= cnt[1]; c1++)
    {
        for (int c2 = 0; c2 <= cnt[2]; c2++)
        {
            for (int c3 = 0; c3 <= cnt[3]; c3++)
            {
                for (int c4 = 0; c4 <= cnt[4]; c4++)
                {
                    int x = c1 + 2 * c2 + 3 * c3 + 4 * c4 + 1;
                    if (c1 != 0)
                    {
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1 - 1][c2][c3][c4] + s[x]);
                    }
                    if (c2 != 0)
                    {
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1][c2 - 1][c3][c4] + s[x]);
                    }
                    if (c3 != 0)
                    {
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1][c2][c3 - 1][c4] + s[x]);
                    }
                    if (c4 != 0)
                    {
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4], dp[c1][c2][c3][c4 - 1] + s[x]);
                    }
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    return 0;
}