#include <iostream>
using namespace std;
long long dp[505][505], cost[505], fst[505], last[505];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        if (fst[c] == 0)
        {
            fst[c] = i;
        }
        last[c] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        if (fst[i])
        {
            dp[i][1] = cost[i];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            for (int p = j - 1; p < i; p++)
            {
                if (fst[p] && last[p] < fst[i] && dp[p][j - 1] != 0)
                {
                    dp[i][j] = max(dp[i][j], cost[i] + dp[p][j - 1]);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][k]);
    }
    cout << (ans == 0 ? -1 : ans) << endl;
    return 0;
}